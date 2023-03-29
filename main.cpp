#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));
    int rectangle_size = 1;

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    triangle.setPosition(600.0, 100.0);

    // create velocities for each shape
    sf::Vector2f circle_velocity(100, -100);
    sf::Vector2f rectangle_velocity(50, 200);
    float rectangle_angular_velocity = 10;
    sf::Vector2f triangle_velocity(-150, 50);

    // set flags for collision detection
    bool flag_y = false;
    bool flag_x = false;

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = window.getElapsedTime();
        float dt = elapsed.asSeconds();

        // update circle
        circle.move(circle_velocity * dt);
        if (circle.getPosition().x + circle.getRadius() >= window.getSize().x || circle.getPosition().x - circle.getRadius() <= 0) {
            circle_velocity.x = -circle_velocity.x;
            circle.setRadius(rand() % 100 + 10);
            circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if (circle.getPosition().y + circle.getRadius() >= window.getSize().y || circle.getPosition().y - circle.getRadius() <= 0) {
            circle_velocity.y = -circle_velocity.y;
            circle.setRadius(rand() % 100 + 10);
            circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        // update rectangle
        rectangle.move(rectangle_velocity * dt);
        if (rectangle.getPosition().x + rectangle.getSize().x >= window.getSize().x || rectangle.getPosition().x <= 0) {
            rectangle_velocity.x = -rectangle_velocity.x;
            rectangle_size = rand() % 3 + 1;
            rectangle.setSize(sf::Vector2f(40 * rectangle_size, 20 * rectangle_size));
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if (rectangle.getPosition().y + rectangle.getSize().y >= window.getSize().y || rectangle.getPosition().y <= 0) {
            rectangle_velocity.y = -rectangle_velocity.y;
            rectangle_size = rand() % 3 + 1;
            rectangle.setSize(sf::Vector2f(40 * rectangle_size, 20 * rectangle
