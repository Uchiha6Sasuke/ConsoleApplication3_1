#pragma once
#include "FileWorker.h"
#include "IWorker.h"
class BlockWrite :
        public IWorker, public FileWorker
{
    BlockWrite(BlockWrite const& write);
    BlockWrite& operator=(BlockWrite const& write) {}
public:
    BlockWrite(std::string const& fileName);
    Text& Process(Text& text);
    ~BlockWrite();
};
