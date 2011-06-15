#pragma once
#include "ExceptionHeaders.h"

class InitConnectionException : public SocketException
{
public:
    InitConnectionException(const wstring error, int MessageBoxStyle = 0)
        :SocketException(error, MessageBoxStyle)
    {}
};
