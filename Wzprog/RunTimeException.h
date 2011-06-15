#pragma once
#include "ExceptionHeaders.h"

class RunTimeException : public Exception
{
public:
    RunTimeException(const wstring error, int MessageBoxStyle = 0)
        :Exception(error, MessageBoxStyle)
    {}
};
