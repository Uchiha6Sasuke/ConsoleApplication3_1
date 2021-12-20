#pragma once
#include "IWorker.h"
#include <list>
class IParser
{
public:
    IParser();
    virtual std::list<IWorker*>& Parse() = 0;
    virtual ~IParser();
};