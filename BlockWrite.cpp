#include "pch.h"
#include "BlockWrite.h"


BlockWrite::BlockWrite(std::string const& fileName)
        :FileWorker(fileName, std::ios_base::out)
{
}

Text& BlockWrite::Process(Text& text)
{
    Write(text);
    text.clear();
    return text;
}


BlockWrite::~BlockWrite()
{
}