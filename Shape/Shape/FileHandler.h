#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "AbstractShape.h"
#include <memory>

class FileHandler
{
public:
    FileHandler(std::ifstream &inputFile, std::ofstream &outputFile, IVisitor *toStringVisitor);
    ~FileHandler();

    void Run();

private:
    std::ifstream input;
    std::ofstream output;
    IVisitor* toStringConverter;

    void PrintFigure(std::unique_ptr<AbstractShape> &shape);
    std::vector<BigInt> ReadBigInts(const std::string &str);
};
