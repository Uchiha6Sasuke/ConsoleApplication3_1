#include "pch.h"
#include "BlockGrep.h"


BlockGrep::BlockGrep(std::string const& word):
        word_(word)
{
}

Text & BlockGrep::Process(Text & text)
{
    Text* greppedText = new Text;
    for (auto it = text.begin(); it != text.end(); ++it) {
        size_t pos = it->find(word_);
        if (pos != std::string::npos) {
            greppedText->push_back(*it);
        }
    }
    text.clear();
    return *greppedText;
}


BlockGrep::~BlockGrep()
{
}