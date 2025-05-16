
#include <SFML/Graphics.hpp>
#include "Ball.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // set framerate
    window.setFramerateLimit(60);

    Ball ball(30.f, {100.f, 100.f}, {5.f, 4.f}); // radius, pos, velocity

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

	ball.update(window);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        ball.draw(window);

        // end the current frame
        window.display();
    }
}
