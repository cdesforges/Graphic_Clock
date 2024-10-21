//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_CLOCKVIEW_H
#define GRAPHIC_CLOCK_CLOCKVIEW_H

#include <SFML/Graphics.hpp>
#include "ClockModel.h"
#include "CounterView.h"
#include <iostream>

class ClockView : public sf::Drawable
{
private:
    const ClockModel& m_model;
    const sf::Font* m_font;
    CounterView m_hours;
    CounterView m_minutes;
    CounterView m_seconds;
    sf::Text m_hourColon;
    sf::Text m_minuteColon;
    sf::Text m_AMPM;
    sf::Vector2f m_position;
    float m_kerning = 10;
    sf::Color m_color = sf::Color::White;

public:
    ClockView(const ClockModel& clock, const sf::Vector2f& position);

    void initialize();

    // getters
    const sf::Vector2f &getPosition() const;
    int getSize() const;

    // setters
    void setPosition(const sf::Vector2f &position);
    void setFont(const sf::Font* font);
    void setText();
    void setColor(sf::Color color);
    void setCharacterSize(int size);

    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GRAPHIC_CLOCK_CLOCKVIEW_H
