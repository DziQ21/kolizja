#include <SFML/Graphics.hpp>
#include <memory>
#include <cmath>
#include <iostream>
#include "include/rectangle.hpp"


bool isColliding(sf::CircleShape const &circle,Rectangle &rect);
sf::Vector2<float> translatePosByDegree(sf::Vector2<float> const &pos,float degree);


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    //becouse of this three line of code wi will be alble to build up more advanced thing with
    //more than one circle and rectangle
    std::vector<std::shared_ptr<Rectangle>> rectangles;
    std::vector<std::shared_ptr<sf::CircleShape>> circles;
    std::vector<std::shared_ptr<sf::Shape>> elementsToDraw;
    circles.push_back(std::make_shared<sf::CircleShape>(sf::CircleShape()));
    circles[0]->setPosition(400,400);
    circles[0]->setOrigin({50,50});
    circles[0]->setRadius(50);

    rectangles.push_back(std::make_shared<Rectangle>(Rectangle()));
    rectangles[0]->setSize({50,300});
    rectangles[0]->setOrigin(rectangles[0]->getSize().x/2,rectangles[0]->getSize().y/2);
    rectangles[0]->setPosition({300,400});

    for(const auto& i : rectangles)
        elementsToDraw.push_back(i);
    for(const auto& i : circles)
        elementsToDraw.push_back(i);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            for (const auto& i : rectangles)
                i->rotate(-2);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            for(const auto& i : rectangles)
                i->rotate(2);
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
        for(auto& i : elementsToDraw)
            i->setFillColor(sf::Color::Black);

        for(auto& rectangle : rectangles)
            for(auto& circle : circles)
                if(isColliding(*circle,*rectangle)){
                    circle->setFillColor(sf::Color::Red);
                    rectangle->setFillColor(sf::Color::Red);
                }

        for(auto &i:elementsToDraw){
            window.draw(*i);
        }
        // end the current frame
        window.display();
    }

    return 0;
}
//function checks collision by simplifying situation to rectangle that stays at point(0,0)
bool isColliding(sf::CircleShape const &circle,Rectangle &rect){
    auto circleTranslatedPos =circle.getPosition()-rect.getPosition();
    sf::Vector2<float> rotatedCirclePos=translatePosByDegree(circleTranslatedPos,rect.getRotation()/360*2*M_PI);
    if(fabs(rotatedCirclePos.x)-circle.getRadius()<rect.getSize().x/2&&fabs(rotatedCirclePos.y)-circle.getRadius()<rect.getSize().y/2)
        return true;
    return false;
}
//this function rotates coordinates by degree for example if we move point (1,1) by do degree we get (-1 1)
sf::Vector2<float> translatePosByDegree(sf::Vector2<float> const &pos,float degree){
    return {pos.x*cosf(degree)-pos.y*sinf(degree),pos.x*sinf(degree)+pos.y*cosf(degree)};
}