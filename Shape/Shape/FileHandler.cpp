#include "stdafx.h"
#include "FileHandler.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include "ShapeSimpleFactory.h"
#include <stdarg.h>
#include <stdexcept>

FileHandler::FileHandler(std::ifstream & inputFile, std::ofstream & outputFile)
{
    input = std::move(inputFile);
    output = std::move(outputFile);
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
        auto doubles = ReadDoubles(line);
        if (stringType == "CIRCLE")
        {
            try
            {
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::CIRCLE, doubles);
                PrintFigure(shape);
            }
            catch (std::domain_error &er)
            {
                output << er.what() << std::endl;
            }
        }
        else if (stringType == "RECTANGLE")
        {
            doubles = { doubles[1], doubles[2], doubles[4] , doubles[5] };
            try
            {
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::RECTANGLE, doubles);
                PrintFigure(shape);
            }
            catch (std::domain_error &er)
            {
                output << er.what() << std::endl;
            }
        }
        else if (stringType == "TRIANGLE")
        {
            doubles = { doubles[1], doubles[2], doubles[4] , doubles[5], doubles[7] , doubles[8] };
            try
            {
                auto shape = ShapeSimpleFactory::CreateShape(ShapeType::TRIANGLE, doubles);
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
    output << shape->GetName() << " P=" << shape->GetPerimeter() << " S=" << shape->GetArea() << std::endl;
}

std::vector<double> FileHandler::ReadDoubles(const std::string &str)
{
    std::vector<double> doubles;
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
        doubles.push_back(std::strtod(currentString.c_str(), nullptr));
        start = end;
    }

    return doubles;
}

