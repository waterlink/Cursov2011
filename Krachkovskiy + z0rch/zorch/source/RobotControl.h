#pragma once
#include "headers.h"
#include "IRobotConsoleControl.h"
#include "IRobotHasLight.h"
#include "IRobotHasSound.h"

namespace Robot
{
    //-------------------------------------------------------------------------------
    //          Управление LEGO-роботом   
    //
    // Поддерживает следующие интерфейсы:
    // 1. IRobotConsoleControl
    //      Открытие соединения с роботом.      (OpenConnection)
    //      Закрытие соединения с роботом.      (CloseConnection)
    //      Проверка на активное соединение.    (IsConnected)
    //      Движение по маршруту.               (PassRoute)
    //      Получение заряда батареи.           (GetBattery)
    // 2. IRobotHasLight                     
    //      Включение фонаря.                   (LightOn)
    //      Выключение фонаря.                  (LightOff)
    // 3. IRobotHasSound                     
    //      Включить подачу звукового сигнала.  (SoundOn)
    //      Выключить подачу звукового сигнала. (SoundOff)
    //
    // Параметры методов:
    //    PassRoute:   Пользовательский маршрут, реализующий интерфейс IRobotRoute.
    //
    // Генерируемые исключения:
    //    OpenConnection
    //        Семейство исключений инициализации.     (InitException)
    //    PassRoute
    //    LightOn
    //    LightOff
    //    SoundOn
    //    SoundOff
    //    GetBattery
    //        Семейство исключений работы с сокетами. (SocketException)
    //
    // Особенности:
    //    Синглтон.
    //   
    //                                                 Copyright © Базь Максим, 2011
    //                                                        ...also known as z0rch
    //------------------------------------------------------------------------------
    class RobotControl : 
        public IRobotConsoleControl, public IRobotHasLight, public IRobotHasSound
    {
    public:
        static RobotControl *InitInstance(void);
        ~RobotControl(void) {}

        void OpenConnection(void);
        void CloseConnection(void);

        void PassRoute(IRobotRoute &route);
        wstring GetBattery(void);
        bool IsConnected(void) { return activeConnection; }

        void LightOn(void);
        void LightOff(void);

        void SoundOn(void);
        void SoundOff(void);

    private:
        RobotControl(void);
        static RobotControl *instance;

        SOCKET connectSocket;
        bool activeConnection;

        // private methods
        void OpenConsole(void);
        wstring ReceiveSocket(void);

        void InitSocket(void);
        void InitWSA(void);
        void InitRobotConnection(void);
        
        void SendSocket(char *command);
        void CheckConnection(void);
        void CheckAnswerIsOK(void);

        // pass route
        struct Action
        {
            Action(int action = 0, double time = 0) : action(action), time(time), eps(0.001) {}
            enum {ROTATE, MOVE};
            int action;
            double time;
            const double eps;
        };

        void ParseRoute(IRobotRoute &route);
        void StartPassRoute(void);

        double angle;
        list<Action> action;

        // constants
        static const string ip;
        static const string pathToJavaBat;
        static const int    port;
        static const int    type; 
        static const int    protocol; 
    };

    DWORD WINAPI InitJavaConnection(LPVOID command);
}
