#include "Button.h"

// The constructor, building each indiv. button based on the argmuents passed from Calc.cpp
Button::Button(const std::string &text, sf::Font &font, sf::Texture &texture,
               float x, float y, sf::Color buttonColor, sf::Color buttonTextColor) {
    
    
    // Setting up the sprite
    rect.setTexture(texture);
    rect.setColor(buttonColor);
    rect.setScale(0.25f, 0.25f); // adjust the png image to a 64X64px rounded rectangle
    rect.setPosition(x, y);

    // Text in the button
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(24);
    label.setFillColor(buttonTextColor);

    // Center the text inside the rect
    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                    textBounds.top + textBounds.height / 2.0f);

    sf::FloatRect rectBounds = rect.getGlobalBounds();
    label.setPosition(rectBounds.left + rectBounds.width / 2.0f,
                      rectBounds.top + rectBounds.height / 2.0f);
}


// Render the button with the text, put it on screen
void Button::render(sf::RenderTarget &target) {
    target.draw(rect);
    target.draw(label);
}