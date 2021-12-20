#include "pch.h"
#include "BlockDump.h"

BlockDump::BlockDump(std::string const & fileName)
        :FileWorker(fileName, std::ios_base::out)
{
}

Text & BlockDump::Process(Text & text)
{
    Write(text);
    return text;
}


BlockDump::~BlockDump()
{
}