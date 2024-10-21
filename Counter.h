//
// Created by Chandler Desforges on 10/14/24.
//

#ifndef GRAPHIC_CLOCK_COUNTER_H
#define GRAPHIC_CLOCK_COUNTER_H

#include <SFML/Graphics.hpp>
#include "CounterModel.h"
#include "CounterView.h"
#include "CounterInputKeys.h"

class Counter : public sf::Drawable
{
private:
    CounterModel m_model;
    CounterView m_view;
    CounterInputKeys m_inputs;

public:
    explicit Counter(sf::Vector2f position);

    // getters
    const sf::Vector2f& getPosition() const;
    int getCharacterSize() const;

    // setters
    void setPosition(const sf::Vector2f& position);
    void setCharacterSize(int size);
    void setKeyControls(char incr, char decr);

    // inherited
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // friend classes
    friend class CounterController;
};


#endif //GRAPHIC_CLOCK_COUNTER_H
