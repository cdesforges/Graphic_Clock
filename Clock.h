//
// Created by Chandler Desforges on 10/11/24.
//

#ifndef GRAPHIC_CLOCK_CLOCK_H
#define GRAPHIC_CLOCK_CLOCK_H

#include "ClockModel.h"
#include "ClockView.h"

class Clock : public sf::Drawable
{
public:
    ClockModel model;
    ClockView view;

    explicit Clock(sf::Vector2f position);

    void setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GRAPHIC_CLOCK_CLOCK_H
