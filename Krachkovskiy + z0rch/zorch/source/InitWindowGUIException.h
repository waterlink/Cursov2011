#pragma once
#include "ExceptionHeaders.h"

class InitWindowGUIException : public InitWindowException
{
public:
    InitWindowGUIException(const wstring error = L"Ошибка инициализации главного окна программы")
        :InitWindowException(error)
    {}
};