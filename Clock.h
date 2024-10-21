//
// Created by Chandler Desforges on 10/11/24.
//

#ifndef GRAPHIC_CLOCK_CLOCK_H
#define GRAPHIC_CLOCK_CLOCK_H

#include "ClockModel.h"
#include "ClockView.h"

class Clock : public sf::Drawable
{
private:
    ClockModel m_model;
    ClockView m_view;

public:
    Clock();
    explicit Clock(sf::Vector2f position);

    // getters
    const sf::Vector2f& getPosition() const;
    int getCharacterSize() const;

    // setters
    void setPosition(const sf::Vector2f& position);
    void setCharacterSize(int size);
    void setTime(int hours, int minutes, int seconds);
    void setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM);

    // inherited
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // friend classes
    friend class ClockController;
};


#endif //GRAPHIC_CLOCK_CLOCK_H
