#pragma once
#include "ExceptionHeaders.h"

class InvalidCommandException : public SocketException
{
public:
    InvalidCommandException(const wstring error = L"������� ��������� ����������� �������")
        :SocketException(error)
    {}
};