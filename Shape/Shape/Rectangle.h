#pragma once
#include "AbstractShape.h"
#include "RectangleFactorySingleton.h"

class CRectangle :
	public AbstractShape
{
public:
    std::string Accept(IVisitor &visitor) override;
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CRectangle() override = default;

    friend RectangleFactorySingleton;
private:
    CRectangle(BigInt a, BigInt b);

    BigInt m_a;
    BigInt m_b;
};


