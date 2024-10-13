//
// Created by Chandler Desforges on 10/8/24.
//

#include "Counter.h"

Counter::Counter()
: m_count(0)
{}

Counter::Counter(int startVal)
: m_count(startVal)
{}

int Counter::getCount() const
{
    return m_count;
}

void Counter::setCount(int count)
{
    m_count = count;
}

Counter operator+(const Counter &lhs, const Counter &rhs)
{
    return {lhs.m_count + rhs.m_count};
}

Counter operator-(const Counter &lhs, const Counter &rhs)
{
    return {lhs.m_count - rhs.m_count};
}

Counter Counter::operator++(int)
{
    Counter preIncr(m_count);
    m_count++;

    return preIncr;
}

void Counter::operator++()
{
    ++m_count;
}

Counter Counter::operator--(int)
{
    Counter preIncr(m_count);
    m_count--;

    return preIncr;
}

void Counter::operator--()
{
    --m_count;
}

void Counter::operator+=(int rhs)
{
    m_count += rhs;
}

void Counter::operator-=(int rhs)
{
    m_count -= rhs;
}
