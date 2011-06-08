#include "MainWindow.h"
using namespace Robot;

MainWindow * MainWindow::instance = 0;

void MainWindow::InitMainWindow(LRESULT (CALLBACK *WndProc)(HWND hWnd, UINT Message, UINT wParam, LONG lParam),
                                       HINSTANCE hInstance, int nCmdShow)
{
    if(!instance)
    {
        instance = new MainWindow();

        instance -> hInstance = hInstance;
        instance -> WndProc   = WndProc;
        instance -> className = L"LEGO-robot";

        instance -> CheckIsAlreadyOpened();
        instance -> RegisterWindowClass();
        instance -> InitGUI(nCmdShow);
    }
}

int MainWindow::OnCommand(HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{
    IRobotConsoleControl *robot = RobotControl::InitInstance();

    switch(LOWORD(wParam))
    {
        case buttonConnection:
        {
            try
            {
                if(IsDlgButtonChecked(hWnd, buttonConnection))
                {
                    SetDlgItemText(hWnd, buttonConnection, L"Прервать соединение с роботом");
                    robot -> OpenConnection();
                    EnableWindow(childWindows[buttonLight],     true);
                    EnableWindow(childWindows[buttonSound],     true);
                    if((int)SendMessage(childWindows[listboxRouteSelect], LB_GETCURSEL, 0, 0) != -1)
                        EnableWindow(childWindows[buttonPassRoute], true);
                }
                else
                {
                    SetDlgItemText(hWnd, buttonConnection, L"Установить соединение с роботом");
                    robot -> CloseConnection();
                    EnableWindow(childWindows[buttonLight],     false);
                    EnableWindow(childWindows[buttonSound],     false);
                    EnableWindow(childWindows[buttonPassRoute], false);
                }
                UpdateStatusbarText();
            }
            catch(...) {}
        }
        break;

        case buttonPassRoute:
        {
            EnableWindow(childWindows[buttonPassRoute], false);
            
            IRobotRoute *route = GenerateRouteFromFile((int)SendMessage(childWindows[listboxRouteSelect], LB_GETCURSEL, 0, 0));
            try{ robot->PassRoute(*route); }
            catch(...) {}

            delete route;
            EnableWindow(childWindows[buttonPassRoute], true);
        }
        break;

        case buttonLight:
        {
            try
            {
                if(IsDlgButtonChecked(hWnd, buttonLight))
                {
                    SetDlgItemText(hWnd, buttonLight, L"Выключить фонарь");
                    IRobotHasLight *lightRobot = dynamic_cast<IRobotHasLight *>(robot);
                    if(lightRobot) 
                        lightRobot->LightOn(); 
                }
                else
                {
                    SetDlgItemText(hWnd, buttonLight, L"Включить фонарь");
                    IRobotHasLight *lightRobot = dynamic_cast<IRobotHasLight *>(robot);
                    if(lightRobot) 
                        lightRobot->LightOff(); 
                }
            }
            catch(...) {}
        }
        break;
        
        case buttonSound:
        {
            try
            {
                if(IsDlgButtonChecked(hWnd, buttonSound))
                {
                    SetDlgItemText(hWnd, buttonSound, L"Прекратить подачу звукового сигнала");
                    IRobotHasSound *soundRobot = dynamic_cast<IRobotHasSound *>(robot);
                    if(soundRobot) 
                        soundRobot->SoundOn(); 
                }
                else
                {
                    SetDlgItemText(hWnd, buttonSound, L"Подать звуковой сигнал");
                    IRobotHasSound *soundRobot = dynamic_cast<IRobotHasSound *>(robot);
                    if(soundRobot) 
                        soundRobot->SoundOff(); 
                }
            }
            catch(...) {}
        }
        break;

        case listboxRouteSelect:
        {
            int a = HIWORD(wParam);
            switch(HIWORD(wParam))
            {
                case LBN_SELCHANGE:
                {
                    if((int)SendMessage(childWindows[listboxRouteSelect],LB_GETCURSEL, 0, 0) != -1)// && IsDlgButtonChecked(hWnd, buttonConnection))
                        EnableWindow(childWindows[buttonPassRoute],true);
                    else
                        EnableWindow(childWindows[buttonPassRoute],false);
                }
                return TRUE;
            }
        }
    }
    return 0;
}

int MainWindow::OnActivate(HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{
    if(wParam)
        StopWindowFlash();
    return 0;
}

void MainWindow::RegisterWindowClass(void)
{
    WNDCLASS WndClass; 

    WndClass.style         = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc   = WndProc;
    WndClass.cbClsExtra    = 0;
    WndClass.cbWndExtra    = 0;
    WndClass.hInstance     = hInstance;
    WndClass.hIcon         = LoadIcon(0, IDI_SHIELD);
    WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    WndClass.lpszMenuName  = NULL;
    WndClass.lpszClassName = className.c_str();
    
    if(!RegisterClass(&WndClass))
        throw RegisterWindowClassException();
}

void MainWindow::CheckIsAlreadyOpened(void)
{
    if (HWND MyWindow = FindWindow(className.c_str(), 0))
    {   
        SetForegroundWindow(MyWindow);
        if(IsIconic(MyWindow))
            ShowWindow(MyWindow,SW_RESTORE);  
        StartWindowFlash(MyWindow);
        throw InitWindowCopyException();
    }
}

IRobotRoute *MainWindow::GenerateRouteFromFile(int id)
{
    const int lineSize = 16384;
    DWORD lineSizeRead = -1;

    HANDLE hFile;
    wchar_t curdir[lineSize] = {0};
    GetCurrentDirectory(lineSize, curdir);
    wstring filepath = curdir;
    filepath += L"\\routes\\" + files[id];
    if((hFile = CreateFile(filepath.c_str(), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)) == INVALID_HANDLE_VALUE)
        throw OpenRouteFileException();
    
    char *line = new char[lineSize];
    if(!ReadFile(hFile, line, lineSize, &lineSizeRead, 0))
        throw ReadRouteFileException();

    double scale = 0;
    int xs = 0, ys = 0, xo = 0, yo = 0;
    sscanf(line, "%lf %d %d %d %d", &scale, &xs, &ys, &xo, &yo);

    class FileRoute : public IRobotRoute
    {
    public:
        FileRoute(double scale, Point startPos, Point offset)
            :IRobotRoute(scale), start(startPos), offset(offset)
        {}

        RouteIterator Begin(void) { return route.begin(); }
        RouteIterator End(void)   { return route.end();   }
        Point GetStartPos(void)   { return start;         }
        Point GetOffset(void)     { return offset;        }

        void Push(Point p)        { route.push_back(p);   }
    private:
        list<Point> route;
        Point start, offset;

    } *fileRoute = new FileRoute(scale, Point(xs, ys), Point(xo, yo));
    
        
    char *pline = line;
    while(*pline != 's' && *pline)
        ++pline;    // дойдем до первого пробела
    pline++;
    while(*pline == ' ' && *pline)
        ++pline; // до начала следующего символа
    
    while(*pline)
    {
        int x = 0, y = 0;
        sscanf(pline, "%d %d", &x, &y);
        fileRoute -> Push(Point(x,y));
        for(int i=0; i<2; i++)
        {
            while(*pline != ' ' && *pline)
                ++pline;    // дойдем до первого пробела
            while(*pline == ' ' && *pline)
                ++pline; // до начала следующего символа
        }
    }

    delete[] line;
    CloseHandle(hFile);
    return fileRoute;
}

void MainWindow::InitGUI(int nCmdShow)
{
    InitCommonControls();
    hWnd = CreateWindow(className.c_str(), L"Управление LEGO-роботом",
                        WS_SYSMENU | WS_MINIMIZEBOX,
                        (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2,
                        (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2,
                        windowWidth, windowHeight,
                        NULL, NULL,
                        hInstance, NULL);

    if(!hWnd)
        throw InitWindowGUIException();
    
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    AppendChildWindow(editGuide,          L"Edit",         L"Выберите маршрут",                WS_CHILD | WS_VISIBLE | ES_CENTER    | ES_READONLY, 7, 7, 180, 20);
    AppendChildWindow(listboxRouteSelect, WC_LISTBOX,      L"",                                WS_CHILD | WS_VISIBLE |  WS_VSCROLL  | LBS_NOTIFY      | LBS_NOINTEGRALHEIGHT, 7, 30, 180, 210, WS_EX_DLGMODALFRAME | WS_EX_TRANSPARENT | WS_EX_CLIENTEDGE);
    AppendChildWindow(buttonConnection,   L"Button",       L"Установить соединение с роботом", WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_AUTOCHECKBOX | BS_PUSHLIKE, 200,  20, 170, 50);
    AppendChildWindow(buttonLight,        L"Button",       L"Включить фонарь",                 WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_AUTOCHECKBOX | BS_PUSHLIKE, 200,  80, 170, 50);
    AppendChildWindow(buttonSound,        L"Button",       L"Подать звуковой сигнал",          WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_AUTOCHECKBOX | BS_PUSHLIKE, 200, 140, 170, 50);
    AppendChildWindow(buttonPassRoute,    L"Button",       L"Начать движение по маршруту",     WS_CHILD | WS_VISIBLE | BS_COMMANDLINK, 200, 200, 170, 50);
    AppendChildWindow(statusbar,          STATUSCLASSNAME, L"",                                WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0);

    GetDirFiles();
    int index = 0;
    for_each(files.begin(), files.end(), [&](wstring &file)
    {
        int pos = SendMessage(childWindows[listboxRouteSelect], LB_ADDSTRING, 0, (LPARAM)file.c_str());
        SendMessage(childWindows[listboxRouteSelect], LB_SETITEMDATA, pos, (LPARAM) index); 
        ++index;
    });

    int coord[2] = { 225, -1 };
    SendMessage(childWindows[statusbar], SB_SETPARTS, 2, (LPARAM)&coord);
    SendMessage(childWindows[statusbar], SB_SETTEXT, MAKEWPARAM(0,SBT_NOBORDERS), (LPARAM)L"LEGO-робот не подключен");
    SendMessage(childWindows[statusbar], SB_SETTEXT, MAKEWPARAM(1,SBT_NOBORDERS), (LPARAM)L"Батарея: неизвестно");
    EnableWindow(childWindows[buttonLight], false);
    EnableWindow(childWindows[buttonSound], false);
    EnableWindow(childWindows[buttonPassRoute], false);
}

void MainWindow::UpdateStatusbarText(void)
{
    wstring first;
    wstring second = L"Батарея: ";
    IRobotConsoleControl *robot = RobotControl::InitInstance();
    if(robot -> IsConnected())
    {
        first   = L"Подключение выполнено";
        second += robot -> GetBattery() + L"В";
    }
    else
    {
        first   = L"LEGO-робот не подключен";
        second += L"неизвестно";
    }
    SendMessage(childWindows[statusbar], SB_SETTEXT, MAKEWPARAM(0,SBT_NOBORDERS), (LPARAM)first.c_str());
    SendMessage(childWindows[statusbar], SB_SETTEXT, MAKEWPARAM(1,SBT_NOBORDERS), (LPARAM)second.c_str());
}

void MainWindow::AppendChildWindow(int id, wstring className, wstring text, int style, int x, int y, int cx, int cy, int styleEx)
{
    childWindows.insert(ID_HWND(id, 
        CreateWindowEx(styleEx, className.c_str(), text.c_str(), style,
                     x, y, cx, cy,
                     hWnd, (HMENU)id, 
                     hInstance, 0)));
}

void MainWindow::StartWindowFlash(HWND hWnd)
{
    FLASHWINFO flash = { sizeof(flash), hWnd, FLASHW_ALL | FLASHW_TIMER, 0, 0};
    FlashWindowEx(&flash);
}

void MainWindow::StopWindowFlash(void)
{
    FLASHWINFO flash = { sizeof(flash), hWnd, FLASHW_STOP, 0, 0};
    FlashWindowEx(&flash);
}

void MainWindow::GetDirFiles(void)
{
    const int size = 1024;
    wchar_t curDir[size] = {0};
    GetCurrentDirectory(size, curDir);
    wcscat(curDir, L"\\routes\\*.txt");

    WIN32_FIND_DATA ffd;
    HANDLE hFind = FindFirstFile(curDir, &ffd);
 
    if (INVALID_HANDLE_VALUE == hFind) 
    {
        //MessageBox(0, L"Cannot see any route files in the directory", L"Error", 0);
        return;
    }
    else
        files.push_back(ffd.cFileName);

    while (FindNextFile(hFind, &ffd) != 0)
        files.push_back(ffd.cFileName);

    FindClose(hFind);
}