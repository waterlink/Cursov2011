#pragma once
#include "ExceptionHeaders.h"

class ReadRouteFileException : public MainWindowException
{
public:
    ReadRouteFileException(const wstring error = L"Ошибка чтения файла маршрута")
        :MainWindowException(error)
    {}
};