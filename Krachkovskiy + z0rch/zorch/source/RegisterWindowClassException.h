#pragma once
#include "ExceptionHeaders.h"

class RegisterWindowClassException : public InitWindowException
{
public:
    RegisterWindowClassException(const wstring error = L("Ошибка регистрации класса главного окна"))
        :InitWindowException(error)
    {}
};
