//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_CLOCKVIEW_H
#define GRAPHIC_CLOCK_CLOCKVIEW_H

#include <SFML/Graphics.hpp>
#include "ClockModel.h"
#include <iostream>

class ClockView : public sf::Drawable
{
private:
    ClockModel& m_clock;
    sf::Font m_font;
    sf::Text m_hours;
    sf::Text m_minutes;
    sf::Text m_seconds;
    sf::Text m_AMPM;
    sf::Vector2f m_position;
    float m_kerning = 5;
    sf::Color m_color = sf::Color::White;

public:
    ClockView(ClockModel& clock, const sf::Vector2f& position);

    void initialize();

    void setFont(const sf::Font& font);
    void setText(int hours, int minutes, int seconds, const std::string& AMPM);
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);

    static std::string buildString(int val);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GRAPHIC_CLOCK_CLOCKVIEW_H
