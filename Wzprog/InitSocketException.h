#pragma once
#include "ExceptionHeaders.h"

class InitSocketException : public InitConnectionException
{
public:
    InitSocketException(const wstring error = L("Ошибка инициализации сокета"))
        :InitConnectionException(error)
    {
        WSACleanup();
    }
};
