#pragma once
#include "ExceptionHeaders.h"

class InvalidAnswerException : public SocketException
{
public:
    InvalidAnswerException(const wstring error = L"Invalid answer from server")
        :SocketException(error)
    {}
};