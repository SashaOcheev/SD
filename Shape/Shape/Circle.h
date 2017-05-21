#pragma once
#include "AbstractShape.h"
class CCircle :
	public AbstractShape
{
public:
	CCircle(BigInt radius);

    std::string Accept(IVisitor &visitor) override;
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CCircle() override = default;
private:
	BigInt m_radius;
};

