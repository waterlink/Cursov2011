#pragma once
#include "ExceptionHeaders.h"

class SocketException : public RunTimeException
{
public:
    SocketException(const wstring error, int MessageBoxStyle = 0)
        :RunTimeException(error, MessageBoxStyle)
    {}
};
