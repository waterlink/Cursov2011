#pragma once
#include "ExceptionHeaders.h"

class InitJavaException : public InitConnectionException
{
public:
    InitJavaException(const wstring error = L("������ ������������� ���������� � �������"))
        :InitConnectionException(error)
    {}
};
