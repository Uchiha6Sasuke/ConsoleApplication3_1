#pragma once
#include "ICalculator.h"
#include "Parser.h"
class Calculator :
        public ICalculator
{
    Parser* parser_;
    std::list<IWorker*> instr_;
    Text text_;
public:
    Calculator(std::string const& instrFile);
    void Calculate();
    ~Calculator();
};
