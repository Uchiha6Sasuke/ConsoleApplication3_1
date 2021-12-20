#pragma once
#include "IWorker.h"
#include "FileWorker.h"
class BlockDump :
        public IWorker, public FileWorker
{
    BlockDump(BlockDump const& dump);
    BlockDump& operator=(BlockDump const& dump);
    void Process(Text& text, int = 0) {}
public:
    BlockDump(std::string const& fileName);
    Text& Process(Text & text);
    ~BlockDump();
};