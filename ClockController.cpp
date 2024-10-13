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
            if (event.text.unicode == clock->model.getKeyControls().incr_mins)
                clock->model.incrMinutes();
            else if (event.text.unicode == clock->model.getKeyControls().decr_mins)
                clock->model.decrMinutes();
            else if (event.text.unicode == clock->model.getKeyControls().incr_hours)
                clock->model.incrHours();
            else if (event.text.unicode == clock->model.getKeyControls().decr_hours)
                clock->model.decrHours();
            else if (event.text.unicode == clock->model.getKeyControls().switch_AMPM)
                clock->model.shiftHours(12);
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
            m_reverseTime ? clock->model.decrSeconds() : clock->model.incrSeconds();
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
    if(clock.model.getHours() >= 12)
        clock.model.setAMPM("PM");
    else
        clock.model.setAMPM("AM");

    // handle overflow
    if(clock.model.getSeconds() >= 60)
    {
        clock.model.shiftSeconds(-60);
        clock.model.incrMinutes();
    }
    if(clock.model.getMinutes() >= 60)
    {
        clock.model.shiftMinutes(-60);
        clock.model.incrHours();
    }
    if(clock.model.getHours() >= 24)
    {
        clock.model.shiftHours(-24);
    }

    // handle underflow
    if(clock.model.getSeconds() < 0)
    {
        clock.model.decrMinutes();
        clock.model.setSeconds(59);
    }
    if(clock.model.getMinutes() < 0)
    {
        clock.model.decrHours();
        clock.model.setMinutes(59);
    }
    if(clock.model.getHours() < 0)
    {
        clock.model.setHours(23);
    }
}

void ClockController::updateView(Clock& clock)
{
    // sorry dave I thought this was funny
    clock.view.setText((clock.model.getHours() % 12 == 0) ? 12 : clock.model.getHours() % 12,
                       clock.model.getMinutes(),
                       clock.model.getSeconds(),
                       clock.model.getAMPM());
}
