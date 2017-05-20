#pragma once
class AbstractShape
{
public:
	AbstractShape(const std::string &name);
	std::string GetName();
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual ~AbstractShape() = default;

private:
	std::string m_name;
};

