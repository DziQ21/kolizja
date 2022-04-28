//
// Created by Paweł on 2022-04-28.
//

#ifndef SQUAREANDCIRCLE_RECTANGLE_HPP
#define SQUAREANDCIRCLE_RECTANGLE_HPP


#include <SFML/Graphics.hpp>


class Rectangle:public sf::RectangleShape{
private:
public:
    sf::Vector2<float> size;
    void setSize(sf::Vector2<float> size_){size=size_;sf::RectangleShape::setSize(size_);}
    sf::Vector2<float> getSize(){return size;}
};


#endif //SQUAREANDCIRCLE_RECTANGLE_HPP
