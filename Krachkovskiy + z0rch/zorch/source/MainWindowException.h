#pragma once
#include "ExceptionHeaders.h"

class MainWindowException : public RunTimeException
{
public:
    MainWindowException(const wstring error, int MessageBoxStyle = 0)
        :RunTimeException(error, MessageBoxStyle)
    {}
};