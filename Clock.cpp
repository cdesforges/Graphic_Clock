//
// Created by Chandler Desforges on 10/11/24.
//

#include "Clock.h"

Clock::Clock(sf::Vector2f position)
: view(model, position)
{}

void Clock::setKeyControls(char incr_hours, char decr_hours, char incr_mins, char decr_mins, char switch_AMPM)
{
    model.setKeyControls(incr_hours, decr_hours, incr_mins, decr_mins, switch_AMPM);
}

