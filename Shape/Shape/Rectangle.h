#pragma once
#include "AbstractShape.h"
class CRectangle :
	public AbstractShape
{
public:
	CRectangle(BigInt a, BigInt b);
	
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CRectangle() override = default;

private:
    BigInt m_a;
    BigInt m_b;
};


