#pragma once
#include "headers.h"
#include "RobotControl.h"
#include "DummyRoute.h"

class MainWindow
{
public:
    static void InitMainWindow(LRESULT (CALLBACK *WndProc)(HWND, UINT, UINT, LONG),
                                      HINSTANCE hInstance, int nCmdShow = SW_SHOW);
    static MainWindow *GetMainWindowHandle(void) { return instance; }

    HINSTANCE GetWindowInstance(void) { return hInstance; }
    HWND GetWindowHandle(void) { return hWnd; }
    ~MainWindow(void) {}

    int OnCommand (HWND hWnd, UINT Message, UINT wParam, LONG lParam);
    int OnActivate(HWND hWnd, UINT Message, UINT wParam, LONG lParam);

    typedef pair<int, HWND> ID_HWND;
private:
    MainWindow(void) {}
    static MainWindow *instance;

    HINSTANCE hInstance;
    HWND hWnd;
    LRESULT (CALLBACK *WndProc)(HWND, UINT, UINT, LONG);
    wstring className;
    map<int, HWND> childWindows;

    void RegisterWindowClass(void);
    void CheckIsAlreadyOpened(void);
    void InitGUI(int nCmdShow);
    void AppendChildWindow(int id, wstring className, wstring text, int style, int x, int y, int cx, int cy, int styleEx = 0);
    void UpdateStatusbarText(void);

    void StartWindowFlash(HWND hWnd);
    void StopWindowFlash(void);

    void GetDirFiles(void);
    vector<wstring> files;

    IRobotRoute *GenerateRouteFromFile(int id);

    static const int windowWidth  = 400;
    static const int windowHeight = 305;
    static const int buttonConnection   = WM_USER + 1;
    static const int buttonPassRoute    = WM_USER + 2;
    static const int buttonLight        = WM_USER + 3;
    static const int buttonSound        = WM_USER + 4;
    static const int listboxRouteSelect = WM_USER + 5;
    static const int editGuide          = WM_USER + 6;
    static const int statusbar          = WM_USER + 7;
};