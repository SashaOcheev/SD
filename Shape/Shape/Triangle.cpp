#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double a, double b, double c)
	: AbstractShape("triangle")
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		CanConstruct(a, b, c);
		throw std::domain_error("Triangle's sides must be a positive numbers");
	}
	m_a = a;
	m_b = b;
	m_c = c;
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}

double CTriangle::GetPerimeter() const
{
	return m_a + m_b + m_c;
}


void CTriangle::CanConstruct(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw std::invalid_argument("The sum of two sides of the triangle must be greater than a third side");
	}
}

double CalculateVectorLength(const std::pair<double, double>& A, const std::pair<double, double>& B)
{
	return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

CTriangle CreateTriangle(const std::pair<double, double>& A, const std::pair<double, double>& B, const std::pair<double, double>& C)
{
	return CTriangle(
		CalculateVectorLength(A, B),
		CalculateVectorLength(A, C),
		CalculateVectorLength(B, C)
	);
}
