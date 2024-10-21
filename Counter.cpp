//
// Created by Chandler Desforges on 10/14/24.
//

#include "Counter.h"

Counter::Counter(sf::Vector2f position)
: m_view(m_model)
{}

const sf::Vector2f &Counter::getPosition() const
{
    return m_view.getPosition();
}

int Counter::getCharacterSize() const
{
    return m_view.getCharacterSize();
}

void Counter::setPosition(const sf::Vector2f &position)
{
    m_view.setPosition(position);
}

void Counter::setCharacterSize(int size)
{
    m_view.setCharacterSize(size);
}

void Counter::setKeyControls(char incr, char decr)
{
    m_inputs.decr = decr;
    m_inputs.incr = incr;
}

void Counter::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_view);
}
