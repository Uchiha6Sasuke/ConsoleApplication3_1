#pragma once
#include "IWorker.h"
#include "definitions.h"
class BlockGrep :
        public IWorker
{
    BlockGrep(BlockGrep const& grep);
    BlockGrep& operator=(BlockGrep const& grep);
    std::string word_;
    void Process(Text& text, int = 0) {}
public:
    BlockGrep(std::string const & word);
    Text& Process(Text& text);
    ~BlockGrep();
};
