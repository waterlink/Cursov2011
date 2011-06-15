#pragma once
#include "ExceptionHeaders.h"

class OpenRouteFileException : public MainWindowException
{
public:
    OpenRouteFileException(const wstring error = L("������ �������� ����� ��������"))
        :MainWindowException(error)
    {}
};
