#pragma once
#include "IShape.h"
class CTriangle :
	public AbstractShape
{
public:
	CTriangle(double a, double b, double c);

	double GetArea() const override;
	double GetPerimeter() const override;

	~CTriangle() override = default;

private:
	void CanConstruct(double a, double b, double c);

	double m_a;
	double m_b;
	double m_c;
};


double CalculateVectorLength(const std::pair<double, double> &A, const std::pair<double, double> &B);


CTriangle CreateTriangle(const std::pair<double, double> &A, const std::pair<double, double> &B, const std::pair<double, double> &C);
