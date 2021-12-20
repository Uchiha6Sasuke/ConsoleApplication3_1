#pragma once
#include <string>
class IValidator
{
public:
    IValidator();
    virtual ~IValidator();

    virtual bool Validate(std::string const& str) = 0;
};
