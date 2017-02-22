#pragma once
#include "IShape.h"
class CRectangle :
	public AbstractShape
{
public:
	CRectangle(double a, double b);
	
	double GetArea() const override;
	double GetPerimeter() const override;

	~CRectangle() override = default;

private:
	double m_a;
	double m_b;
};

CRectangle CreateRectangle(const std::pair<double, double> &leftTop, const std::pair<double, double> &rightBottom);

