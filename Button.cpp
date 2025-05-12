#include "Button.h"

// The constructor, building each indiv. button based on the argmuents passed from Calc.cpp
Button::Button(const std::string &text, sf::Font &font, sf::Texture &texture,
               float x, float y, sf::Color buttonColor, sf::Color buttonTextColor) {
    
    
    // Setting up the sprite, the visual representation of our png file (texture)
    rect.setTexture(texture);
    rect.setColor(buttonColor);
    rect.setScale(0.2734375f, 0.2734375f);    // png from 256x256 to 70x70
    rect.setPosition(x, y);                   // Button pos. passed from argument

    // Text in the button
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(24);
    label.setFillColor(buttonTextColor);

    // Center the text inside the rect
    sf::FloatRect textBounds = label.getLocalBounds();
    // The text will have a movable position from the center center instead of top lft pixel now (centering text on box)
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