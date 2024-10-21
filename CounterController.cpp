//
// Created by Chandler Desforges on 10/14/24.
//

#include "CounterController.h"

CounterController::CounterController(Counter &counter)
{
    m_counters.push_back(&counter);
}

void CounterController::addCounter(Counter &counter)
{
    m_counters.push_back(&counter);
}

void CounterController::eventHandler(sf::Event &event)
{
    for(auto& counter : m_counters)
    {
        if(event.text.unicode == counter->m_inputs.incr)
            counter->m_model++;
        if(event.text.unicode == counter->m_inputs.decr)
            counter->m_model--;
        if(event.text.unicode == '~')
            m_reverseTime = !m_reverseTime;
        if(event.text.unicode == ' ')
            m_pause = !m_pause;
    }
}

void CounterController::update()
{
    if(m_time.getElapsedTime().asSeconds() > 1 && !m_pause)
    {
        m_time.restart();
        for(auto& counter : m_counters)
            m_reverseTime ? counter->m_model-- : counter->m_model++;
    }

    for(auto& counter : m_counters)
        counter->m_view.update();
}
