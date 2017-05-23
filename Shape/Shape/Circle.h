#pragma once
#include "AbstractShape.h"
#include "CircleFactorySingleton.h"

class CCircle :
	public AbstractShape
{
public:
    std::string Accept(IVisitor &visitor) override;
	BigInt GetArea() const override;
	BigInt GetPerimeter() const override;

	~CCircle() override = default;

    friend CircleFactorySingleton;
private:
    CCircle(BigInt radius);

	BigInt m_radius;
};

