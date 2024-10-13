//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_COUNTER_H
#define GRAPHIC_CLOCK_COUNTER_H


class Counter
{
private:
    int m_count;

public:
    Counter();
    virtual ~Counter() = default;
    Counter(int startVal);

    int getCount() const;

    void setCount(int count);

    // operators
    friend Counter operator+(const Counter& lhs, const Counter& rhs);
    friend Counter operator-(const Counter& lhs, const Counter& rhs);
    Counter operator++(int);
    void operator++();
    Counter operator--(int);
    void operator--();
    void operator+=(int rhs);
    void operator-=(int rhs);
};


#endif //GRAPHIC_CLOCK_COUNTER_H
