// Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

#include "FileHandler.h"

int main(int argc, char *argv[])
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

    FileHandler fileHandler(inputFile, outputFile);
    fileHandler.Run();

    return 0;
}

