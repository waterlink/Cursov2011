#pragma once
#include "ExceptionHeaders.h"

class InitWinSockException : public InitConnectionException
{
public:
    InitWinSockException(const wstring error = L("Ошибка инициализации WSAStartup"))
        :InitConnectionException(error)
    {}
};
