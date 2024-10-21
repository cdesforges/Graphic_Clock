//
// Created by Chandler Desforges on 10/8/24.
//

#include "CounterModel.h"

CounterModel::CounterModel()
: m_count(0)
{}

CounterModel::CounterModel(int startVal)
: m_count(startVal)
{}

int CounterModel::getCount() const
{
    return m_count;
}

void CounterModel::setCount(int count)
{
    m_count = count;
}

CounterModel operator+(const CounterModel &lhs, const CounterModel &rhs)
{
    return {lhs.m_count + rhs.m_count};
}

CounterModel operator-(const CounterModel &lhs, const CounterModel &rhs)
{
    return {lhs.m_count - rhs.m_count};
}

CounterModel CounterModel::operator++(int)
{
    CounterModel preIncr(m_count);
    m_count++;

    return preIncr;
}

void CounterModel::operator++()
{
    ++m_count;
}

CounterModel CounterModel::operator--(int)
{
    CounterModel preIncr(m_count);
    m_count--;

    return preIncr;
}

void CounterModel::operator--()
{
    --m_count;
}

void CounterModel::operator+=(int rhs)
{
    m_count += rhs;
}

void CounterModel::operator-=(int rhs)
{
    m_count -= rhs;
}
