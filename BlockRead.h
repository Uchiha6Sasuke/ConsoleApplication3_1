#pragma once
#include "FileWorker.h"
#include "IWorker.h"

class BlockRead :
        public IWorker, public FileWorker
{
    BlockRead(BlockRead const& read);
    BlockRead& operator=(BlockRead const& read) {}
    void Process(Text& text, int = 0) {}
public:
    BlockRead(std::string const& fileName);
    Text& Process(Text& text);
    ~BlockRead();
};
