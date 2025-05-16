
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, sf::Vector2f position, sf::Vector2f velocity)
        : velocity(velocity)
    {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }

    void update(const sf::RenderWindow& window) {
        shape.move(velocity);

        sf::Vector2f pos = shape.getPosition();
        float diameter = 2 * shape.getRadius();

        // Bounce off left or right
        if ((pos.x <= 0 && velocity.x < 0) || 
            (pos.x + diameter >= window.getSize().x && velocity.x > 0)) {
            velocity.x = -velocity.x;
        }

        // Bounce off top or bottom
        if ((pos.y <= 0 && velocity.y < 0) || 
            (pos.y + diameter >= window.getSize().y && velocity.y > 0)) {
            velocity.y = -velocity.y;
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};
