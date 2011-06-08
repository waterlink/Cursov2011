#pragma once
#include "ExceptionHeaders.h"

class InitWindowCopyException : public InitWindowException
{
public:
    InitWindowCopyException(const wstring error = L("Программа уже запущена!"))
        :InitWindowException(error, MB_SYSTEMMODAL)
    {}
};
