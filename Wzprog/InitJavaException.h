#pragma once
#include "ExceptionHeaders.h"

class InitJavaException : public InitConnectionException
{
public:
    InitJavaException(const wstring error = L("Ошибка инициализации соединения с роботом"))
        :InitConnectionException(error)
    {}
};
