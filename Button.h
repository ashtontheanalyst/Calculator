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
        
        // Renders the button, puts it on screen
        void render(sf::RenderTarget &target);

        // Accessors
        sf::Color getColor() const;
        std::string getValue() const;
        bool clicked(sf::Vector2f mousePos) const;
};