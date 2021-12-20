#pragma once

#include "definitions.h"

struct IWorker
{
    IWorker();
    virtual Text& Process(std::vector<std::string>& text) = 0;
    virtual ~IWorker();
};