//
// Created by Chandler Desforges on 10/14/24.
//

#ifndef GRAPHIC_CLOCK_COUNTERCONTROLLER_H
#define GRAPHIC_CLOCK_COUNTERCONTROLLER_H

#include "Counter.h"

class CounterController
{
private:
    std::vector<Counter*> m_counters;
    sf::Clock m_time;
    bool m_pause = false;
    bool m_reverseTime = false; // easter egg!

public:
    CounterController(Counter& counter);

    void addCounter(Counter& counter);

    void eventHandler(sf::Event& event);

    void update();
};


#endif //GRAPHIC_CLOCK_COUNTERCONTROLLER_H
