#pragma once
#include "ExceptionHeaders.h"

class SendSocketException : public SocketException
{
public:
    SendSocketException(const wstring error = L("������ �������� ������"))
        :SocketException(error)
    {}
};
