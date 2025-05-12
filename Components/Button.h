// Button class

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <string>

class Button {
    private:
        sf::Sprite rect;
        sf::Text label;


    public:
        // This is it's constructor, taking in arguments from Calc.cpp to build the class out fully
        Button(const std::string &text, sf::Font &font, sf::Texture &texture,
               float x, float y, sf::Color buttonColor, sf::Color buttonTextColor);
        
        void render(sf::RenderTarget &target);              // Renders the button, puts it on screen

        // Accessors
        sf::Color getColor() const;                         // gets the color of the button, for use in Calc.cpp
        std::string getValue() const;                       // gets the value of the button, for use in Calc.cpp
        bool clicked(sf::Vector2f mousePos) const;          // Check to see if the mouse pos is over and button and it's been clicked
};