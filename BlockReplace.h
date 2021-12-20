#pragma once
#include "IWorker.h"
#include "definitions.h"
class BlockReplace :
        public IWorker
{
    std::string wordf_;
    std::string wordr_;

    void Process(Text& text, int = 0) {}
    BlockReplace(BlockReplace const& replace);
    BlockReplace& operator=(BlockReplace const& replace);
public:
    BlockReplace(std::string const& wordFind, std::string const& wordReplace);
    Text& Process(Text& text);
    ~BlockReplace();
};
