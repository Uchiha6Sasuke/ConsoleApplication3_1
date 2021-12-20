#pragma once
#include "IWorker.h"
#include "definitions.h"
#include <algorithm>
class BlockSort :
        public IWorker
{
    BlockSort(BlockSort const& sort);
    BlockSort& operator=(BlockSort const& sort);
    void Process(Text& text, int = 0){}
public:
    BlockSort();
    Text& Process(Text& text);
    ~BlockSort();
};