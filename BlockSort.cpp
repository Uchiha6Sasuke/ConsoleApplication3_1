#include "pch.h"
#include "BlockSort.h"


BlockSort::BlockSort()
{
}

Text & BlockSort::Process(Text & text)
{
    std::sort(text.begin(), text.end());
    return text;
}


BlockSort::~BlockSort()
{
}