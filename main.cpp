#include <iostream>
#include "ClockController.h"
#include "Clock.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window({1280,720}, "Graphic ClockModel Test", sf::Style::Default);
    window.setFramerateLimit(60);

    Clock clock1({100,100});
    Clock clock2({400, 100});
    Clock clock3({100,400});
    Clock clock4({400, 400});
    clock2.model.setKeyControls('r','f','t','g','h');

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
