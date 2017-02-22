#pragma once
#include "IShape.h"

class CCircle :
	public AbstractShape
{
public:
	CCircle(double radius);

	double GetArea() const override;
	double GetPerimeter() const override;

	~CCircle() override = default;
private:
	double m_radius;
};

CCircle CreateCircle(const std::pair<double, double> &centerPosition, const double radius);
