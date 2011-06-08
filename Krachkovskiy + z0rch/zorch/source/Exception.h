#pragma once
#include "headers.h"

class Exception
{
public:
    Exception(const wstring error, int MessageBoxStyle = 0)
    {
        MessageBox(0, error.c_str(), 0, MB_ICONASTERISK | MessageBoxStyle);
    }
};

