//
// Created by Chandler Desforges on 10/11/24.
//

#include "Clock.h"

Clock::Clock()
: m_view(m_model, {0,0})
{}

Clock::Clock(sf::Vector2f position)
: m_view(m_model, position)
{}

const sf::Vector2f &Clock::getPosition() const
{
    return m_view.getPosition();
}

int Clock::getCharacterSize() const
{
    return m_view.getSize();
}

void Clock::setPosition(const sf::Vector2f &position)
{
    m_view.setPosition(position);
}

void Clock::setCharacterSize(int size)
{
    m_view.setCharacterSize(size);
}

void Clock::setTime(int hours, int minutes, int seconds)
{
    m_model.setHours(hours);
    m_model.setMinutes(minutes);
    m_model.setSeconds(seconds);
}

void Clock::setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM)
{
    m_model.setKeyControls(incr_hours, decr_hours, incr_mins, decr_mins, switch_AMPM);
}

void Clock::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(m_view);
}

