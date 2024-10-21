//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_COUNTERMODEL_H
#define GRAPHIC_CLOCK_COUNTERMODEL_H


class CounterModel
{
private:
    int m_count;

public:
    CounterModel();
    virtual ~CounterModel() = default;
    CounterModel(int startVal);

    int getCount() const;

    void setCount(int count);

    // operators
    friend CounterModel operator+(const CounterModel& lhs, const CounterModel& rhs);
    friend CounterModel operator-(const CounterModel& lhs, const CounterModel& rhs);
    CounterModel operator++(int);
    void operator++();
    CounterModel operator--(int);
    void operator--();
    void operator+=(int rhs);
    void operator-=(int rhs);
};


#endif //GRAPHIC_CLOCK_COUNTERMODEL_H
