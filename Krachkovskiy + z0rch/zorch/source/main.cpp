/*----------------------------------------------
 Базь Максим Витальевич — ИСПР09 Программисты

                Курсовая работа 
 Модель ситуационного управления LEGO-роботом
----------------------------------------------*/

#include "MainWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, UINT wParam, LONG lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpszCmdParam,  int nCmdShow)
{
    try  { MainWindow::InitMainWindow(&WndProc, hInstance, nCmdShow); }
    catch(Exception) { return 0; }

    MSG Msg;

    while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{
    static MainWindow *window = MainWindow::GetMainWindowHandle();

    switch(Message)
    {
        case WM_COMMAND:
            return window -> OnCommand(hWnd, Message, wParam, lParam);
        case WM_ACTIVATE:
            return window -> OnActivate(hWnd, Message, wParam, lParam);
        case WM_DESTROY:
            PostQuitMessage(0);
           return 0;
        default: return DefWindowProc(hWnd,Message,wParam,lParam);
    }
}