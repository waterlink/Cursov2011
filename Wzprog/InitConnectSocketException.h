#pragma once
#include "ExceptionHeaders.h"

class InitConnectSocketException : public InitConnectionException
{
public:
    InitConnectSocketException(SOCKET connectSocket, const wstring error = L("Ошибка подключения сокета"))
        :InitConnectionException(error)
    {
        closesocket(connectSocket);
        WSACleanup();
    }
};
