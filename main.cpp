#include <iostream>
#include "ClockController.h"
#include "Clock.h"
#include <SFML/Graphics.hpp>
#include "Counter.h"
#include "CounterController.h"

int main()
{
    sf::RenderWindow window({1280,720}, "Graphic ClockModel Test", sf::Style::Default);
    window.setFramerateLimit(60);

    Clock clock1({100,100});
    Clock clock2({400, 100});
    Clock clock3({100,400});
    Clock clock4;

    clock4.setPosition({400,400});

    clock2.setKeyControls('r', 'f', 't', 'g', 'h');

    ClockController controller(clock1);
    controller.addClock(clock2);
    controller.addClock(clock3);
    controller.addClock(clock4);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            controller.eventHandler(event);
        }

        window.clear();

        controller.update();

        window.draw(clock1);
        window.draw(clock2);
        window.draw(clock3);
        window.draw(clock4);

        window.display();
    }

    return 0;
}







//Counter test({100,100});
//Counter test2({200, 200});
//
//CounterController controller(test);
//controller.addCounter(test2);