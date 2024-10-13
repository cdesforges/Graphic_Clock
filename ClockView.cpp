//
// Created by Chandler Desforges on 10/8/24.
//

#include "ClockView.h"

ClockView::ClockView(ClockModel &clock, const sf::Vector2f& position)
: m_clock(clock), m_position(position)
{
    initialize();
}

void ClockView::initialize()
{
    setText(0,0,0,"AM");

    if(!m_font.loadFromFile("Soccer Scoreboard.otf"))
        std::cout << "Font load failed!\n";

    setFont(m_font);
    setColor(m_color);
    setPosition(m_position);
}

void ClockView::setFont(const sf::Font& font)
{
    m_hours.setFont(font);
    m_minutes.setFont(font);
    m_seconds.setFont(font);
    m_AMPM.setFont(font);
}

void ClockView::setText(int hours, int minutes, int seconds, const std::string& AMPM)
{
    m_hours.setString(buildString(hours) + ":");
    m_minutes.setString(buildString(minutes) + ":");
    m_seconds.setString(buildString(seconds));
    m_AMPM.setString(AMPM);
}

void ClockView::setColor(sf::Color color)
{
    m_hours.setFillColor(color);
    m_minutes.setFillColor(color);
    m_seconds.setFillColor(color);
    m_AMPM.setFillColor(color);
}

void ClockView::setPosition(sf::Vector2f position)
{
    m_hours.setPosition(position);
    m_minutes.setPosition(m_hours.getPosition().x + m_hours.getGlobalBounds().width + m_kerning, position.y);
    m_seconds.setPosition(m_minutes.getPosition().x + m_minutes.getGlobalBounds().width + m_kerning, position.y);
    m_AMPM.setPosition(m_seconds.getPosition().x + m_seconds.getGlobalBounds().width + (m_kerning * 2), position.y);
}

void ClockView::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_hours);
    window.draw(m_minutes);
    window.draw(m_seconds);
    window.draw(m_AMPM);
}

std::string ClockView::buildString(int val)
{
    if(val < 10)
        return "0" + std::to_string(val);
    else
        return std::to_string(val);
}
