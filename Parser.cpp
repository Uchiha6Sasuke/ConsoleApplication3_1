#include "pch.h"
#include "Parser.h"
#include "BlockDump.h"
#include "BlockGrep.h"
#include "BlockRead.h"
#include "BlockReplace.h"
#include "BlockSort.h"
#include "BlockWrite.h"
#include <map>


Parser::Parser(std::string const& fileName, std::string const& source, std::string const& dest)
        :FileWorker(fileName, std::ios_base::in)
{
}

auto Parser::BlockInVect(Text &rawInstr, std::vector<IWorker *> &blocks)
{
    auto it = rawInstr.begin();
    ++it;
    for (; it->find("csed") == std::string::npos; ++it) {
        size_t posEq = it->find("=");
        if (posEq == std::string::npos) {
            throw std::logic_error("Bad block description");
        }
        size_t blockNumber = std::stoi(it->substr(0, it->find(' '))); //get ID
        it->erase(0, it->find(' ') + 3);

        std::string blockName = it->substr(0, it->find(' '));
        std::string param = it->substr(it->find(' ') + 1, it->length());;

        IWorker* newWorker = nullptr;
        if (blockName == "readfile") {
            newWorker = new BlockRead(param);
        }
        else if (blockName == "writefile") {
            newWorker = new BlockWrite(param);
        }
        else if (blockName == "grep") {
            newWorker = new BlockGrep(param);
        }
        else if (blockName == "sort") {
            newWorker = new BlockSort();
        }
        else if (blockName == "replace") {
            std::string param2 = param.substr(param.find(' ') + 1, param.length());
            param = param.substr(0, param.find(' '));
            newWorker = new BlockReplace(param, param2);
        }
        else if (blockName == "dump") {
            newWorker = new BlockDump(param);
        }
        else {
            throw std::logic_error("Bad block name");
        }
        if (blocks.capacity() < blockNumber + 1) {
            blocks.resize(blockNumber + 2);
        }
        blocks[blockNumber] = newWorker;
    }
    return it;
}

std::list<IWorker*>& Parser::Parse()
{
    Text rawInstr;
    Read(rawInstr);
    if (rawInstr[0].find("desc") == std::string::npos) {
        throw std::logic_error("Is no 'desc' there!");
    }

    std::list<IWorker*>* instructions = new std::list<IWorker*>;
    if (source_ != "") {
        instructions->push_back(new BlockRead(source_));
    }
    std::vector<IWorker*> blocks;
    auto startStructDesc = BlockInVect(rawInstr, blocks) + 1;
    for (auto it = startStructDesc; it != rawInstr.end(); ++it) {
        while (it->find(' ') != std::string::npos) it->erase(it->find(' '), 1);
        while (it->find("->") != std::string::npos) {
            size_t number = stoi(it->substr(0, it->find("->")));
            it->erase(0, it->find("->") + 2);
            if (number > blocks.capacity()-1) {
                throw std::logic_error("This block does'n exist!");
            }
            instructions->push_back(blocks[number]);
        }
        size_t number = 0;
        try {
            number = stoi(it->substr(0, it->length()));
        }
        catch (const std::exception&) {
            std::cerr << "Wrong shame structure!" << std::endl;
        }
        instructions->push_back(blocks[number]);
    }
    if (dest_ != "") {
        instructions->push_back(new BlockWrite(dest_));
    }
    return *instructions;
}


Parser::~Parser()
{
}