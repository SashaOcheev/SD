// Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


using namespace std;

void PrintFigure(ostream &outsream, const IShape &shape, const string &figureName)
{
	outsream << figureName << " ";
	outsream << "area = " << shape.GetArea() << " ";
	outsream << "perimeter = " << shape.GetPerimeter() << endl;
}

void HandleFigureStream(istream &instream, ostream &outstream)
{
	string figure;
	instream >> figure;
	double a, b, c, d, e, f;
	if (figure == "triangle")
	{
		instream >> a >> b >> c >> d >> e >> f;
		PrintFigure(outstream, CreateTriangle({ a, b }, { c, d }, { e, f }), figure);
	}
	else if (figure == "rectangle")
	{
		instream >> a >> b >> c >> d;
		PrintFigure(outstream, CreateRectangle({ a, b }, { c, d }), figure);
	}
	else if (figure == "circle")
	{
		instream >> a >> b >> c;
		PrintFigure(outstream, CreateCircle({ a, b }, c), figure);
	}
}

void RunShapeStream(istream &instream, ostream &outsream)
{
	while (instream)
	{
		try
		{
			HandleFigureStream(instream, outsream);
		}
		catch (const std::domain_error &ex)
		{
			outsream << ex.what() << endl;
		}
	}
}


int main()
{
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	RunShapeStream(inputFile, outputFile);

    return 0;
}

