#include "pch.h"
#include "FileWorker.h"


FileWorker::FileWorker(std::string const& fileName, std::ios_base::openmode const& mode)
{
    file_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        file_.open(fileName, mode);
    }
    catch (const std::ifstream::failure& e) {
        std::cerr << "Exception opening file" << std::endl;
    }
}

void FileWorker::Write(Text const& text)
{
    file_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        size_t i = 0;
        for (auto i = text.begin(); i != text.end(); ++i) {
            file_ << *i << std::endl;
        }
    }
    catch (const std::ifstream::failure& e) {
        std::cerr << "Couldn't write file!" << std::endl;
    }
}

Text& FileWorker::Read(Text& text)
{
    file_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        size_t i = 0;
        while (!file_.eof()) {
            std::string str;
            std::getline(file_, str);
            text.push_back(str);
        }
    }
    catch (const std::ifstream::failure& e) {
        std::cerr << "Couldn't read file!" << std::endl;
    }
    return text;
}


FileWorker::~FileWorker()
{
    file_.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        file_.close();
    }
    catch (const std::ifstream::failure& e) {
        std::cerr << "Exception closing file" << std::endl;
    }
}