#include "pch.h"
#include "BlockReplace.h"


BlockReplace::BlockReplace(std::string const & wordFind, std::string const & wordReplace)
        :wordf_(wordFind)
        , wordr_(wordReplace)
{
}

Text & BlockReplace::Process(Text & text)
{
    for (auto it = text.begin(); it != text.end(); ++it) {
        size_t pos = it->find(wordf_);
        while (pos != std::string::npos) {
            it->replace(pos, wordf_.length(), wordr_);
            pos = it->find(wordf_, pos+wordr_.length());
        }
    }
    return text;
}


BlockReplace::~BlockReplace()
{
}