//
// Created by Chandler Desforges on 10/8/24.
//

#include "ClockView.h"

ClockView::ClockView(const ClockModel &clock, const sf::Vector2f& position)
: m_model(clock), m_position(position), m_hours(clock.getHoursRef(), 12, 1), m_minutes(clock.getMinutesRef(), 60), m_seconds(clock.getSecondsRef(), 60)
{
    initialize();
}

void ClockView::initialize()
{
    m_font = FontManager::getInstance().getFont("Soccer Scoreboard.otf");

    m_hourColon.setString(":");
    m_minuteColon.setString(":");

    setFont(m_font);
    setText();
    setColor(m_color);
    setPosition(m_position);
}

void ClockView::setFont(const sf::Font* font)
{
    m_hours.setFont(font);
    m_minutes.setFont(font);
    m_seconds.setFont(font);
    m_AMPM.setFont(*font);
    m_hourColon.setFont(*font);
    m_minuteColon.setFont(*font);
}

void ClockView::setText()
{
    m_hours.setString(m_model.getHours());
    m_minutes.setString(m_model.getMinutes());
    m_seconds.setString(m_model.getSeconds());
    m_AMPM.setString(m_model.getAMPM());
}

void ClockView::setColor(sf::Color color)
{
    m_hours.setColor(color);
    m_minutes.setColor(color);
    m_seconds.setColor(color);
    m_AMPM.setFillColor(color);
    m_hourColon.setFillColor(color);
    m_minuteColon.setFillColor(color);
}

void ClockView::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_hours);
    window.draw(m_hourColon);
    window.draw(m_minutes);
    window.draw(m_minuteColon);
    window.draw(m_seconds);
    window.draw(m_AMPM);
}

void ClockView::update()
{
    m_hours.update();
    m_minutes.update();
    m_seconds.update();
    m_AMPM.setString(m_model.getAMPM());
}

const sf::Vector2f &ClockView::getPosition() const
{
    return m_position;
}

void ClockView::setPosition(const sf::Vector2f &position)
{
    m_hours.setPosition(position);
    m_hourColon.setPosition(m_hours.getPosition().x + m_hours.getGlobalBounds().width + m_kerning, position.y);
    m_minutes.setPosition({m_hourColon.getPosition().x + m_hourColon.getGlobalBounds().width + m_kerning, position.y});
    m_minuteColon.setPosition(m_minutes.getPosition().x + m_minutes.getGlobalBounds().width + m_kerning, position.y);
    m_seconds.setPosition({m_minuteColon.getPosition().x + m_minuteColon.getGlobalBounds().width + m_kerning, position.y});
    m_AMPM.setPosition({m_seconds.getPosition().x + m_seconds.getGlobalBounds().width + (m_kerning * 2), position.y});
}

int ClockView::getSize() const
{
    return m_hours.getCharacterSize();
}

void ClockView::setCharacterSize(int size)
{
    m_hours.setCharacterSize(size);
    m_hourColon.setCharacterSize(size);
    m_minutes.setCharacterSize(size);
    m_minuteColon.setCharacterSize(size);
    m_seconds.setCharacterSize(size);
    m_AMPM.setCharacterSize(size);
}
