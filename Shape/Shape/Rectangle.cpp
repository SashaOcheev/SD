#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(BigInt a, BigInt b)
{
	if (a <= 0 || b <= 0)
	{
		throw std::domain_error("Rectangle's sides must be a positive numbers");
	}
	m_a = a;
	m_b = b;
}

std::string CRectangle::Accept(IVisitor & visitor)
{
    return visitor.Visit(*this);
}

BigInt CRectangle::GetArea() const
{
	return m_a * m_b;
}

BigInt CRectangle::GetPerimeter() const
{
	return (m_a + m_b) * 2;
}

