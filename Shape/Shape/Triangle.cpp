#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(BigInt a, BigInt b, BigInt c)
	: AbstractShape("TRIANGLE")
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw std::domain_error("Triangle's sides must be a positive numbers");
	}
    CanConstruct(a, b, c);
	m_a = a;
	m_b = b;
	m_c = c;
}

BigInt CTriangle::GetArea() const
{
	BigInt p = GetPerimeter() / 2;
	return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}

BigInt CTriangle::GetPerimeter() const
{
	return m_a + m_b + m_c;
}


void CTriangle::CanConstruct(BigInt a, BigInt b, BigInt c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw std::domain_error("The sum of two sides of the triangle must be greater than a third side");
	}
}

