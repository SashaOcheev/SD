#pragma once
#include "AbstractShape.h"
#include "TriangleFactorySingleton.h"

class CTriangle :
	public AbstractShape
{
public:
    std::string Accept(IVisitor &visitor) override;
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CTriangle() override = default;

    friend TriangleFactorySingleton;
private:
    CTriangle(BigInt a, BigInt b, BigInt c);

	void CanConstruct(BigInt a, BigInt b, BigInt c);

	BigInt m_a;
    BigInt m_b;
    BigInt m_c;
};

