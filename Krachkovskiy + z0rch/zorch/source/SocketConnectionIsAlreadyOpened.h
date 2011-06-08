#pragma once
#include "ExceptionHeaders.h"

class SocketConnectionIsAlreadyOpened : public SocketException
{
public:
    SocketConnectionIsAlreadyOpened(const wstring error = L"Connection is already established")
        :SocketException(error)
    {}
};