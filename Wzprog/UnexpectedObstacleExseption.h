#pragma once
#include "ExceptionHeaders.h"

class UnexpectedObstacleExseption : public SocketException
{
public:
    UnexpectedObstacleExseption(const wstring error = L("���������� ����������� �����������"))
        :SocketException(error)
    {}
};
