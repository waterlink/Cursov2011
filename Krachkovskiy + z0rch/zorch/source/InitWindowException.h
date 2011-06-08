#pragma once
#include "ExceptionHeaders.h"

class InitWindowException : public MainWindowException
{
public:
    InitWindowException(const wstring error, int MessageBoxStyle = 0)
        :MainWindowException(error, MB_SYSTEMMODAL)
    {}
};