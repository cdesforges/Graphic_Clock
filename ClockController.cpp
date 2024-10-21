//
// Created by Chandler Desforges on 10/8/24.
//

#include "ClockController.h"

ClockController::ClockController(Clock& clock)
{
    m_clocks.emplace_back(&clock);
}

void ClockController::addClock(Clock& clock)
{
    m_clocks.emplace_back(&clock);
}

void ClockController::eventHandler(sf::Event event)
{
    // for the clocks
    for(auto& clock : m_clocks)
    {
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode == clock->m_model.getKeyControls().incr_mins)
                clock->m_model.incrMinutes();
            else if (event.text.unicode == clock->m_model.getKeyControls().decr_mins)
                clock->m_model.decrMinutes();
            else if (event.text.unicode == clock->m_model.getKeyControls().incr_hours)
                clock->m_model.incrHours();
            else if (event.text.unicode == clock->m_model.getKeyControls().decr_hours)
                clock->m_model.decrHours();
            else if (event.text.unicode == clock->m_model.getKeyControls().switch_AMPM)
                clock->m_model.shiftHours(12);
        }
    }

    // global
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == ' ')
            m_pause = !m_pause;
        else if (event.text.unicode == '~')
            m_reverseTime = !m_reverseTime;
    }
}

void ClockController::update()
{
    // GLOBAL : increment seconds
    if(m_time.getElapsedTime().asSeconds() > 1 && !m_pause)
    {
        m_time.restart();
        for(auto& clock : m_clocks)
            m_reverseTime ? clock->m_model.decrSeconds() : clock->m_model.incrSeconds();
    }

    for(auto& clock : m_clocks)
    {
        updateModel(*clock);
        updateView(*clock);
    }
}

void ClockController::updateModel(Clock& clock)
{
    // handle AMPM
    if(clock.m_model.getHours() >= 12)
        clock.m_model.setAMPM("PM");
    else
        clock.m_model.setAMPM("AM");

    // handle overflow
    if(clock.m_model.getSeconds() >= 60)
    {
        clock.m_model.shiftSeconds(-60);
        clock.m_model.incrMinutes();
    }
    if(clock.m_model.getMinutes() >= 60)
    {
        clock.m_model.shiftMinutes(-60);
        clock.m_model.incrHours();
    }
    if(clock.m_model.getHours() >= 24)
    {
        clock.m_model.shiftHours(-24);
    }

    // handle underflow
    if(clock.m_model.getSeconds() < 0)
    {
        clock.m_model.decrMinutes();
        clock.m_model.setSeconds(59);
    }
    if(clock.m_model.getMinutes() < 0)
    {
        clock.m_model.decrHours();
        clock.m_model.setMinutes(59);
    }
    if(clock.m_model.getHours() < 0)
    {
        clock.m_model.setHours(23);
    }
}

void ClockController::updateView(Clock& clock)
{
    clock.m_view.update();
}
