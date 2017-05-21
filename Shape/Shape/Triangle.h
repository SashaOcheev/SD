#pragma once
#include "AbstractShape.h"
class CTriangle :
	public AbstractShape
{
public:
	CTriangle(BigInt a, BigInt b, BigInt c);

    std::string Accept(IVisitor &visitor) override;
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CTriangle() override = default;

private:
	void CanConstruct(BigInt a, BigInt b, BigInt c);

	BigInt m_a;
    BigInt m_b;
    BigInt m_c;
};

