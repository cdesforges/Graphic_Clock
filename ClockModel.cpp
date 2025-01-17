//
// Created by Chandler Desforges on 10/8/24.
//

#include "ClockModel.h"

ClockModel::ClockModel()
: m_hours(CounterModel(0)), m_minutes(CounterModel(0)), m_seconds(CounterModel(0)), m_AMPM("AM")
{}

ClockModel::ClockModel(int hours, int minutes, int seconds)
: m_hours(CounterModel(hours)), m_minutes(CounterModel(minutes)), m_seconds(CounterModel(seconds)), m_AMPM("AM")
{}

int ClockModel::getSeconds() const
{
    return m_seconds.getCount();
}

void ClockModel::setSeconds(const CounterModel &mSeconds)
{
    m_seconds = mSeconds;
}

int ClockModel::getMinutes() const
{
    return m_minutes.getCount();
}

void ClockModel::setMinutes(const CounterModel &mMinutes)
{
    m_minutes = mMinutes;
}

int ClockModel::getHours() const
{
    return m_hours.getCount();
}

const ClockInputKeys &ClockModel::getKeyControls()
{
    return m_controls;
}

void ClockModel::setHours(const CounterModel &mHours)
{
    m_hours = mHours;
}

void ClockModel::shiftHours(int numHours)
{
    m_hours.setCount(m_hours.getCount() + numHours);
}

void ClockModel::shiftMinutes(int numMins)
{
    m_minutes.setCount(m_minutes.getCount() + numMins);
}

void ClockModel::shiftSeconds(int numSeconds)
{
    m_seconds.setCount(m_seconds.getCount() + numSeconds);
}

ClockModel ClockModel::operator++(int)
{
    ClockModel preIncr(*this);

    m_minutes++;

    return preIncr;
}

ClockModel ClockModel::operator--(int)
{
    ClockModel preIncr(*this);

    m_minutes--;

    return preIncr;
}

void ClockModel::operator++()
{
    m_minutes++;
}

void ClockModel::operator--()
{
    m_minutes--;
}

void ClockModel::operator+=(int rhs)
{
    m_minutes += rhs;
}

void ClockModel::operator-=(int rhs)
{
    m_minutes += rhs;
}

const std::string &ClockModel::getAMPM() const
{
    return m_AMPM;
}

void ClockModel::setAMPM(const std::string &AMPM)
{
    m_AMPM = AMPM;
}

void ClockModel::setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM)
{
    m_controls.incr_hours = incr_hours;
    m_controls.decr_hours = decr_hours;
    m_controls.incr_mins = incr_mins;
    m_controls.decr_mins = decr_mins;
    m_controls.switch_AMPM = switch_AMPM;
}

void ClockModel::incrSeconds()
{
    m_seconds++;
}

void ClockModel::incrMinutes()
{
    m_minutes++;
}

void ClockModel::incrHours()
{
    m_hours++;
}

void ClockModel::decrSeconds()
{
    m_seconds--;
}

void ClockModel::decrMinutes()
{
    m_minutes--;
}

void ClockModel::decrHours()
{
    m_hours--;
}

const CounterModel &ClockModel::getHoursRef() const
{
    return m_hours;
}

const CounterModel &ClockModel::getMinutesRef() const
{
    return m_minutes;
}

const CounterModel &ClockModel::getSecondsRef() const
{
    return m_seconds;
}

const std::string &ClockModel::getAMPMRef() const
{
    return m_AMPM;
}
