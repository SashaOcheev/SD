#include "stdafx.h"
#include "BigInt.h"
#include <algorithm>
#include <stdexcept>
#include <numeric>

BigInt::BigInt(const std::vector<digit> &number)
{
    m_number = number;
    std::reverse(m_number.begin(), m_number.end());
    removeInsignificant0();
}

BigInt::BigInt(long long number)
{
	do
	{
		Push(number % 10);
		number /= 10;
	} while (number);
}

BigInt::BigInt(const BigInt & source)
{
    *this = source;
}

std::vector<digit>::iterator BigInt::begin()
{
	return m_number.begin();
}

std::vector<digit>::iterator BigInt::end()
{
	return m_number.end();
}

std::vector<digit>::const_iterator BigInt::begin() const
{
    return m_number.cbegin();
}

std::vector<digit>::const_iterator BigInt::end() const
{
    return m_number.end();
}

void BigInt::addInsignificant0(size_t targetSize)
{
	while (GetSize() < targetSize)
		Push(0);
}

void BigInt::removeInsignificant0()
{
	while (GetSize() > 1)
	{
		if (m_number.back() == 0)
			Pop();
		else
			return;
	}
}

const BigInt BigInt::operator++()
{
    *this += 1;
    return *this;
}

const BigInt BigInt::operator++(int)
{
    BigInt res = *this;
    ++*this;
    return res;
}

const BigInt BigInt::operator--()
{
    *this -= 1;
    return *this;
}

const BigInt BigInt::operator--(int)
{
    BigInt res = *this;
    --*this;
    return res;
}

const BigInt BigInt::operator+=(const BigInt & number)
{
    BigInt tempNumber(number);

    size_t maxSize = std::max(tempNumber.GetSize(), GetSize());
    addInsignificant0(maxSize);
    tempNumber.addInsignificant0(maxSize);

    for (size_t i = 0; i < maxSize; i++)
        (*this)[i] = (*this)[i] + tempNumber[i];

    removeInsignificant0();
    tempNumber.removeInsignificant0();

    EditOverflowDigits();
    
    return *this;
}

const BigInt BigInt::operator*=(const BigInt & number)
{
    BigInt tempNumber(number);

    BigInt res;
    res.ResizeAndFill(tempNumber.GetSize() + GetSize(), 0);

    for (size_t i = 0; i < GetSize(); i++)
    {
        for (size_t j = 0; j < tempNumber.GetSize(); j++)
            res[i + j] += m_number[i] * tempNumber[j];
        res.EditOverflowDigits();
    }

    res.removeInsignificant0();
    *this = res;

    return res;
}

const BigInt BigInt::operator-=(const BigInt & number)
{
    BigInt tempNumber(number);

    if (*this <= number)
    {
        *this = BigInt(0);
        return BigInt(0);
    }

    BigInt res = *this;
    for (size_t i = 0; i < tempNumber.GetSize(); i++)
    {
        if (res[i] < tempNumber[i])
        {
            res[i] += 10;
            size_t j;
            for (j = i + 1; res[j] == 0; j++)
                res[j] = 9;
            res[j] -= 1;
        }
        res[i] -= tempNumber[i];
    }

    res.removeInsignificant0();
    *this = res;
    return res;
}

const BigInt BigInt::operator/=(const BigInt & number)
{
    if (number == 0)
    {
        throw std::logic_error("dividing by 0");
    }
    if ((*this) < number)
    {
        *this = 0;
        return *this;
    }

    BigInt res;
    BigInt remaind;
    for (int i = GetSize() - 1; i > -1; i--)
    {
        if (remaind == 0)
        {
            remaind = (*this)[i];
        }
        else
        {
            remaind.PushFront((*this)[i]);
        }

        res.PushFront(0);
        while (remaind >= number)
        {
            remaind -= number;
            ++res;
        }
    }

    *this = res;
    return res;
}

const BigInt BigInt::operator%=(const BigInt & number)
{
    auto divideRes = *this / number;
    *this -= divideRes * number;
    return *this;
}

size_t BigInt::GetSize() const
{
	return m_number.size();
}

void BigInt::ResizeAndFill(size_t size, digit val)
{
	m_number.resize(size);
	std::fill(m_number.begin(), m_number.end(), val);
}

void BigInt::Push(digit val)
{
	m_number.push_back(val);
}

void BigInt::PushFront(digit val)
{
    BigInt t = *this;
    m_number.resize(t.GetSize() + 1);
    m_number[0] = val;
    std::copy(t.begin(), t.end(), begin() + 1);
}

digit BigInt::Pop()
{
	digit t = m_number.back();
	m_number.pop_back();
	return t;
}

void BigInt::EditOverflowDigits()
{
	for (size_t i = 0; i < GetSize(); i++)
	{
		digit t = m_number[i];
		m_number[i] = t % 10;
		if (t / 10 > 0)
		{
			if (i == GetSize() - 1)
				Push(0);
			m_number[i + 1] += t / 10;
		}
	}
}

digit &BigInt::operator[](size_t i)
{
	return m_number[i];
}

const digit &BigInt::operator[](size_t i) const
{
    return m_number[i];
}

const BigInt BigInt::operator+(const BigInt &number) const
{
    BigInt temp;
    temp = *this;
    return temp += number;
}

const BigInt BigInt::operator*(const BigInt &number) const
{
    BigInt temp;
    temp = *this;
    return temp *= number;
}

const BigInt BigInt::operator-(const BigInt &number) const
{
    BigInt temp;
    temp = *this;
    return temp -= number;
}

const BigInt BigInt::operator/(const BigInt & number) const
{
    BigInt res(*this);
    res /= number;
    return res;
}

const BigInt BigInt::operator%(const BigInt & number) const
{
    auto res = *this;
    res %= number;
    return res;
}

bool BigInt::operator==(const BigInt &number) const
{
	return std::equal(begin(), end(), number.begin(), number.end());
}

bool BigInt::operator!=(const BigInt &number) const
{
	return !(*this == number);
}

bool BigInt::operator<(const BigInt &number) const
{
    BigInt tempNumber(number);

	size_t i = tempNumber.GetSize();

	if (GetSize() < i)
		return true;
	if (GetSize() > i)
		return false;

	while (i)
	{
		i--;
		if (m_number[i] < tempNumber[i])
			return true;
		if (m_number[i] > tempNumber[i])
			return false;
	}

	return false;
}

bool BigInt::operator<=(const BigInt &number) const 
{
	return (*this) == number || (*this) < number;
}

bool BigInt::operator>(const BigInt &number) const
{
	return !((*this) <= number);
}

bool BigInt::operator>=(const BigInt &number) const
{
	return !((*this) < number);
}

std::string BigInt::ToString() const
{
    auto str = std::accumulate(begin(), end(), std::string(), [](const std::string &str, digit d) {
        return str + std::to_string(d);
    });
    std::reverse(str.begin(), str.end());
    return str;
}

BigInt sqrt(BigInt number)
{
    if (number < 0)
    {
        throw std::domain_error("can not take sqrt of negative");
    }
    if (number <= 1)
    {
        return number;
    }
    
    auto cur = number / 2;
    auto curInc = cur + 1;
    auto sqr = cur * 2;
    auto sqrInc = curInc * 2;

    while (!(sqr <= number && sqrInc >= number))
    {
        if (sqr < number)
        {
            cur *= 2;
            sqr = cur * cur;
            curInc = cur + 1;
            sqrInc = curInc * curInc;
        }
        else
        {
            cur /= 2;
            sqr = cur * cur;
            curInc = cur + 1;
            sqrInc = curInc * curInc;
        }
    }
}