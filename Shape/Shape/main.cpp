// Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


using namespace std;

void PrintFigure(ostream &outsream, const shared_ptr<AbstractShape> &shape)
{
	outsream << shape->GetName() << " ";
	outsream << "area = " << shape->GetArea() << " ";
	outsream << "perimeter = " << shape->GetPerimeter() << endl;
}

shared_ptr<AbstractShape> GetFigure(istream &instream)
{
	string figure;
	instream >> figure;
	double a, b, c, d, e, f;
	if (figure == "triangle")
	{
		instream >> a >> b >> c >> d >> e >> f;
		return make_shared<CTriangle>(CreateTriangle({ a, b }, { c, d }, { e, f }));
	}
	else if (figure == "rectangle")
	{
		instream >> a >> b >> c >> d;
		return make_shared<CRectangle>(CreateRectangle({ a, b }, { c, d }));
	}
	else if (figure == "circle")
	{
		instream >> a >> b >> c;
		return make_shared<CCircle>(CreateCircle({ a, b }, c));
	}
}

void RunShapeStream(istream &instream, ostream &outstream)
{
	while (instream)
	{
		try
		{
			auto figure = GetFigure(instream);
			if (figure)
			{
				PrintFigure(outstream, figure);
			}
		}
		catch (const std::domain_error &ex)
		{
			outstream << ex.what() << endl;
		}
	}
}


int main(int argc, char *argv[])
{
	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

	RunShapeStream(inputFile, outputFile);

    return 0;
}

