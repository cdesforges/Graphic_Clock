//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_COUNTERVIEW_H
#define GRAPHIC_CLOCK_COUNTERVIEW_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "CounterModel.h"
#include "FontManager.h"

class CounterView : public sf::Drawable
{
private:
    const CounterModel& m_model;
    sf::Text m_text;
    const sf::Font* m_font;
    sf::Color m_color = sf::Color::White;
    sf::Vector2f m_position;
    int m_size = 30;
    int m_numDigits = 2;
    int m_offset;
    int m_modulus;

private:
    void initialize();
    std::string buildString();
    std::string buildString(int val) const;

public:
    CounterView(const CounterModel& model);
    CounterView(const CounterModel& model, int modulus);
    CounterView(const CounterModel &model, int modulus, int offset);
    CounterView(const CounterModel &model, int modulus, int offset, const sf::Vector2f &position);

    // getters
    const sf::Color &getColor() const;
    const sf::Vector2f &getPosition() const;
    int getCharacterSize() const;
    sf::FloatRect getGlobalBounds() const;
    int getVal() const;

    // setters
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setCharacterSize(int size);
    void setString(int val);
    void setFont(const sf::Font* font);

    //fns
    void update();

    //inherited
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GRAPHIC_CLOCK_COUNTERVIEW_H
