#pragma once
#include "ExceptionHeaders.h"

class NotSupportedException : public Exception
{
public:
    NotSupportedException(const wstring error = L("This functionality is not supported"))
        :Exception(error)
    {}
};
