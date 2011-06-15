#pragma once
#include "ExceptionHeaders.h"

class OpenRouteFileException : public MainWindowException
{
public:
    OpenRouteFileException(const wstring error = L("Ошибка открытия файла маршрута"))
        :MainWindowException(error)
    {}
};
