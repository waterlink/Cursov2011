#include "RobotControl.h"
#include "ExceptionHeaders.h"
//#include <iostream>
//#include <io.h>
//#include <fcntl.h>

namespace Robot
{
    RobotControl *RobotControl::instance      = 0;

    const string  RobotControl::ip            = "127.0.0.1";
    const string  RobotControl::pathToJavaBat = "\"C:\\Program Files\\LEGO\\nxt\\StartConnection.bat\""; //"d:\\Документы\\Универ\\Dropbox\\private\\Курсовая\\NXTBTX\\build\\classes\\StartConnection.bat";
    const int     RobotControl::port          = 20042;
    const int     RobotControl::type          = AF_INET; 
    const int     RobotControl::protocol      = IPPROTO_TCP; 

    RobotControl *RobotControl::InitInstance(void)
    {
        return instance ? instance : (instance = new RobotControl());
    }

    RobotControl::RobotControl(void)
    {
        HWND hConsole = FindWindow(L("ConsoleWindowClass"), 0);
        while(hConsole)
        {
            SendMessage(hConsole, WM_CLOSE, 0, 0);
            hConsole = FindWindow(L("ConsoleWindowClass"), 0);
        }
        CreateThread(0, 0, InitJavaConnection, (LPVOID)pathToJavaBat.c_str(), 0, 0);
        Sleep(6000);
        hConsole = FindWindow(L("ConsoleWindowClass"), 0);
        if(!hConsole)
            throw InitJavaException();
        ShowWindow(hConsole, SW_HIDE);
        
        activeConnection = false;
    }

    void RobotControl::OpenConnection(void)
    {
        if(activeConnection)
            throw SocketConnectionIsAlreadyOpened();

        InitWSA();
        InitSocket();
        InitRobotConnection();

        activeConnection = true;
    }

    
    void RobotControl::CloseConnection(void)
    {
        CheckConnection();
        closesocket(connectSocket);
        WSACleanup();
        activeConnection = false;
    }

    void RobotControl::PassRoute(IRobotRoute &route)
    {
        CheckConnection();
        ParseRoute(route);
        StartPassRoute();
    }

    void RobotControl::ParseRoute(IRobotRoute &route)
    {
        const double pi = 3.141593;

        IRobotRoute::RouteIterator thisIterator = route.Begin();
        IRobotRoute::RouteIterator prevIterator = route.Begin();
        IRobotRoute::RouteIterator nextIterator = route.Begin();

        Point t = route.GetStartPos();
        Point p = route.GetOffset();
        Point n;

        for(int i=0; nextIterator != route.End(); i++)
        {
            n = *nextIterator;
            if(i == 0)
            {  
                t = route.GetStartPos();
                p = route.GetOffset();
            }
            else if(i == 1)
            {
                t = *thisIterator;
                p = route.GetStartPos();
            }
            else
            {
                t = *thisIterator;
                p = *prevIterator;
            }
            Point thisVector(p.x - t.x, p.y - t.y);
            Point nextVector(n.x - t.x, n.y - t.y);
            
            double vectorMul = thisVector.x * nextVector.x + thisVector.y * nextVector.y;
            double absThis   = sqrt((double)thisVector.x * thisVector.x + thisVector.y * thisVector.y);
            double absNext   = sqrt((double)nextVector.x * nextVector.x + nextVector.y * nextVector.y);
            angle = acos(vectorMul / (absThis * absNext));

            Action command;
            command.action = Action::ROTATE;
            if(pi / 2 - angle > 0) // до 180 градусов
                command.time = angle * 180 / pi;
            else
                command.time = (pi - angle) * 180 / pi;
            if(i)
            {
                if(thisVector.x * nextVector.y > thisVector.y * nextVector.x)
                    command.time *= -1;
            }
            else
            {
                if(thisVector.x * nextVector.y < thisVector.y * nextVector.x)
                    command.time *= -1;
            }
            if(abs(command.time) > command.eps)
                action.push_back(command);
            command.action = Action::MOVE;
            command.time   = absNext * route.GetScale() * 1000; // millimeters?
            if(abs(command.time) > command.eps)
                action.push_back(command);

            prevIterator = thisIterator;
            thisIterator = nextIterator;
            ++nextIterator;
        }
    }
    
    void RobotControl::StartPassRoute(void)
    {
        //for_each(action.begin(), action.end(), [&](Action a)
        for (list < Action >::iterator a = action.begin(); a != action.end(); ++a)
        {
            char *buf = new char[16];
            sprintf(buf, "%.3f", a->time);
            string command = buf;
            switch(a->action)
            {
                case Robot::RobotControl::Action::ROTATE:
                    command = "SRT=" + command;
                break;

                case Robot::RobotControl::Action::MOVE:
                    command = "SRD=" + command;
                break;

                default: throw InvalidCommandException();
                break;
            }
            command += '\n';
            SendSocket((char *)command.c_str());
            CheckAnswerIsOK();
            delete[] buf;
        }
        action.clear();
    }

    void RobotControl::LightOn(void)
    {
        SendSocket("SSL=1\n");
        CheckAnswerIsOK();
    }

    void RobotControl::LightOff(void)
    {
        SendSocket("SSL=0\n");
        CheckAnswerIsOK();
    }

    void RobotControl::SoundOn(void)
    {
        SendSocket("SSS=1\n");
        CheckAnswerIsOK();
    }
    
    void RobotControl::SoundOff(void)
    {
        SendSocket("SSS=0\n");
        CheckAnswerIsOK();
    }

    wstring RobotControl::GetBattery(void)
    {
        SendSocket("GSC\n");
        return ReceiveSocket();
    }

    DWORD WINAPI InitJavaConnection(LPVOID command)
    {
        system((char *)command);
        return 0;
    }

    void RobotControl::SendSocket(char *command)
    {
        CheckConnection();
        int size = strlen(command);
        if(send(connectSocket, command, size, 0) == SOCKET_ERROR)
            throw SendSocketException();
        
    }

    void RobotControl::InitWSA(void)
    {
        WSADATA wsaData;
        if(WSAStartup(MAKEWORD(2,2), &wsaData))
            throw InitWinSockException();
    }

    void RobotControl::InitSocket(void)
    {
        connectSocket = socket(type, SOCK_STREAM, protocol);
        if(connectSocket == INVALID_SOCKET)
            throw InitSocketException();
    }

    void RobotControl::InitRobotConnection(void)
    {
        sockaddr_in robot; 
        robot.sin_family = type;
        robot.sin_addr.s_addr = inet_addr(ip.c_str());
        robot.sin_port = htons(port);

        if(connect(connectSocket, (SOCKADDR*) &robot, sizeof(robot)) == SOCKET_ERROR)
            throw InitConnectSocketException(connectSocket);
        
        int flag = 1;
        if(setsockopt(connectSocket, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int)) < 0)
            throw InitConnectSocketException(connectSocket);
    }

    wstring RobotControl::ReceiveSocket(void)
    {
        wstring answer;
        const int maxsize = 128;
        int size = 0;
        char buff[maxsize] = {0};
        wchar_t wbuff[maxsize] = {0};

        size=recv(connectSocket, buff, sizeof(buff)-1, 0);

        buff[size]=0;
        mbstowcs(wbuff, buff, maxsize); // mbstowcs или MultiByteToWideChar
        answer += wbuff;
        wcscpy(wbuff, L(""));

        return answer;
    }

    void RobotControl::CheckConnection(void)
    {
        if(!activeConnection)
            throw SocketConnectionIsNotEstablished(L("Connection is not established"));
    }

    void RobotControl::CheckAnswerIsOK(void)
    {
        wstring recv = ReceiveSocket();
        if(recv == L("UnexpectedObstacle"))
            throw UnexpectedObstacleExseption();
        else if(recv == L("NotSupported"))
            throw NotSupportedException();
        else if(recv != L("OK"))
            throw InvalidAnswerException();
    }
}
