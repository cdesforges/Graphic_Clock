//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_CLOCKMODEL_H
#define GRAPHIC_CLOCK_CLOCKMODEL_H

#include "Counter.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "KeyControls.h"

class ClockModel
{
private:
    Counter m_seconds;
    Counter m_minutes;
    Counter m_hours;
    std::string m_AMPM;
    KeyControls m_controls;

public:
    ClockModel();
    ClockModel(int hours, int minutes, int seconds);

    // getters
    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;
    const std::string &getAMPM() const;
    const KeyControls& getKeyControls();


    // setters
    void setSeconds(const Counter &mSeconds);
    void setMinutes(const Counter &mMinutes);
    void setHours(const Counter &mHours);
    void setAMPM(const std::string &AMPM);
    void setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM);

    // function
    void incrSeconds();
    void incrMinutes();
    void incrHours();
    void shiftHours(int numHours);
    void shiftMinutes(int numMins);
    void shiftSeconds(int numSeconds);
    void decrSeconds();
    void decrMinutes();
    void decrHours();

    // operators
    ClockModel operator++(int);
    ClockModel operator--(int);
    void operator++();
    void operator--();
    void operator+=(int rhs);
    void operator-=(int rhs);
};


#endif //GRAPHIC_CLOCK_CLOCKMODEL_H
