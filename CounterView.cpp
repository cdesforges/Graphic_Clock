//
// Created by Chandler Desforges on 10/8/24.
//

#include "CounterView.h"

CounterView::CounterView(const CounterModel &model)
: CounterView(model, INT_MAX, 0, {0,0})
{

}

CounterView::CounterView(const CounterModel &model, int modulus)
: CounterView(model, modulus, 0, {0,0})
{

}

CounterView::CounterView(const CounterModel &model, int modulus, int offset)
: CounterView(model, modulus, offset, {0,0})
{

}

CounterView::CounterView(const CounterModel &model, int modulus, int offset, const sf::Vector2f &position)
: m_model(model), m_modulus(modulus), m_offset(offset), m_position(position)
{
    initialize();
}

void CounterView::initialize()
{
    m_font = FontManager::getInstance().getFont("Soccer Scoreboard.otf");

    setColor(m_color);
    m_text.setFont(*m_font);
    m_text.setString(buildString());
}

void CounterView::setColor(sf::Color color)
{
    m_color = color;
}

void CounterView::setPosition(sf::Vector2f position)
{
   m_position = position;
}

void CounterView::setCharacterSize(int size)
{
    m_size = size;
}

std::string CounterView::buildString()
{
    // get the value of the counter
    int value = m_model.getCount() % m_modulus;

    // if the value is less than our offset, add our mod to it
    if(value < m_offset)
        value += m_modulus;

    // build a string from that value
    std::string res = buildString(value);

    // skip the leading minus sign
    auto it = res.begin();
    if(*it == '-')
        it++;

    // fill out empty digits with zeros
    while(res.size() < m_numDigits)
        res.insert(it, '0');

    return res;
}

std::string CounterView::buildString(int val) const
{
    std::string res = std::to_string(val);

    auto it = res.begin();

    // skip the leading minus sign
    if(*it == '-')
        it++;

    // fill out empty digits with zeros
    while(res.size() < m_numDigits)
        res.insert(it, '0');

    return res;
}

void CounterView::update()
{
    m_text.setString(buildString());
    m_text.setFillColor(m_color);
    m_text.setPosition(m_position);
    m_text.setCharacterSize(m_size);
}

void CounterView::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_text);
}

const sf::Color &CounterView::getColor() const
{
    return m_color;
}

const sf::Vector2f &CounterView::getPosition() const
{
    return m_position;
}

int CounterView::getCharacterSize() const
{
    return m_size;
}

void CounterView::setString(int val)
{
    m_text.setString(buildString(val));
}

sf::FloatRect CounterView::getGlobalBounds() const
{
    return m_text.getGlobalBounds();
}

void CounterView::setFont(const sf::Font* font)
{
    m_font = font;
}

int CounterView::getVal() const
{
    return m_model.getCount();
}
