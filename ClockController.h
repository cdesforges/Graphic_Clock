//
// Created by Chandler Desforges on 10/8/24.
//

#ifndef GRAPHIC_CLOCK_CLOCKCONTROLLER_H
#define GRAPHIC_CLOCK_CLOCKCONTROLLER_H

#include "Clock.h"
#include <SFML/Graphics.hpp>

class ClockController
{
private:
    std::vector<Clock*> m_clocks;
    sf::Clock m_time;
    bool m_pause = false;
    bool m_reverseTime = false; // easter egg!

public:
    explicit ClockController(Clock& clock);

    // fns
    void addClock(Clock& clock);
    void eventHandler(sf::Event event);
    void update();
    static void updateModel(Clock& clock);
    static void updateView(Clock& clock);
};


#endif //GRAPHIC_CLOCK_CLOCKCONTROLLER_H
