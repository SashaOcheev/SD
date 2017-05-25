#include "stdafx.h"
#include "FileHandler.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include "ShapeSimpleFactory.h"
#include <stdarg.h>
#include <stdexcept>

FileHandler::FileHandler(std::ifstream & inputFile, std::ofstream & outputFile, IVisitor *toStringVisitor)
{
    input = std::move(inputFile);
    output = std::move(outputFile);
    toStringConverter = toStringVisitor;
}

FileHandler::~FileHandler()
{
}

void FileHandler::Run()
{
    std::string line;
    while (std::getline(input, line))
    {
        std::istringstream stringStream(line);
        std::string stringType;
        stringStream >> stringType;
        stringType = std::string(stringType.begin(), stringType.end() - 1);
        auto BigInts = ReadBigInts(line);
        if (stringType == "CIRCLE")
        {
            try
            {
                BigInts = { BigInts[2] };
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::CIRCLE, BigInts);
                PrintFigure(shape);
            }
            catch (std::domain_error &er)
            {
                output << er.what() << std::endl;
            }
        }
        else if (stringType == "RECTANGLE")
        {
            BigInts = { BigInts[1], BigInts[2], BigInts[4] , BigInts[5] };
            try
            {
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::RECTANGLE, BigInts);
                PrintFigure(shape);
            }
            catch (std::domain_error &er)
            {
                output << er.what() << std::endl;
            }
        }
        else if (stringType == "TRIANGLE")
        {
            BigInts = { BigInts[1], BigInts[2], BigInts[4] , BigInts[5], BigInts[7] , BigInts[8] };
            try
            {
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::TRIANGLE, BigInts);
                PrintFigure(shape);
            }
            catch (std::domain_error &er)
            {
                output << er.what() << std::endl;
            }
        }
    }
}

void FileHandler::PrintFigure(std::unique_ptr<AbstractShape>& shape)
{
    output << shape->Accept(*toStringConverter) << std::endl;
}

std::vector<BigInt> FileHandler::ReadBigInts(const std::string &str)
{
    std::vector<BigInt> BigInts;
    auto start = str.begin();
    while (start != str.end())
    {
        start = std::find_if(start, str.end(), [](char ch) { return ch >= '0' && ch <= '9'; });
        if (start == str.end())
        {
            break;
        }
        auto end = std::find_if(start, str.end(), [](char ch) { return ch < '0' || ch > '9'; });
        std::string currentString(start, end);
        std::vector<digit> num;
        for (auto & i : currentString)
        {
            num.push_back(i - '0');
        }
        start = end;
        BigInts.push_back(BigInt(num));
    }

    return BigInts;
}

