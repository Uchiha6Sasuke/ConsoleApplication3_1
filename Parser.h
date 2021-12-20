#pragma once
#include "IValidator.h"
class Validator :
        public IValidator
{
    Validator(Validator const& validator);
    Validator& operator=(Validator const& validator);
public:
    Validator();
    ~Validator();

    virtual bool Validate(std::string const& str);
};