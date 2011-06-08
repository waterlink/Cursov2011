#pragma once
#include "ExceptionHeaders.h"

class SocketConnectionIsNotEstablished : public SocketException
{
public:
    SocketConnectionIsNotEstablished(const wstring error = L"Connection is not established")
        :SocketException(error)
    {}
};