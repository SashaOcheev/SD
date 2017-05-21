// Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

#include "FileHandler.h"
#include "ToStringVisitor.h"
#include <memory>

int main(int argc, char *argv[])
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);
    std::unique_ptr<IVisitor> toStringVisitor = std::make_unique<ToStringVisitor>();

    FileHandler fileHandler(inputFile, outputFile, toStringVisitor.get());
    fileHandler.Run();

    return 0;
}

