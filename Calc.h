// The main Calculator

#pragma once

#include "Components/Button.h"                  // Include our button class

#include <SFML/Graphics.hpp>                    // SFML Libraries
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class Calc {
    // internal details
    private:
        // Window
        sf::RenderWindow * window;              // a window SFML object
        sf::VideoMode videomode;                // sets our h, w, full screen, title bar, etc.
        sf::Event ev;                           // checks for events on the pc, clicks, push, etc.

        // Fonts
        sf::Font buttonFont;
        sf::Font outputFont;                    // On screen font

        // Colors
        sf::Color backgroundColor;
        sf::Color buttonColor;
        sf::Color numButtonColor;
        sf::Color buttonTextColor;
        sf::Color buttonAboveTextColor;
        sf::Color outputColor;
        sf::Color black;
        sf::Color white;

        // Button
        sf::Texture buttonTexture;              // This is the png file for the rounded rectangle, Button class then puts more into this
        std::vector<Button> buttons;            // Stores mutliple buttons

        // Screen
        sf::Sprite screen;
        sf::Texture screenTexture;              // Same png file for the buttons but it'll be screen sized
        sf::Text output;                        // On screen text

        // Mouse
        sf::Vector2i mousePosRaw;               // Raw position
        sf::Vector2f mousePos;                  // Converted to floats
        bool mouseHeld;                         // bool for if the left click is being held
        
        // Init Functions
        void initVariables();                   // set up our var's to be used later in the program
        void initWindow();                      // set the application window
        void initButtonFont();
        void initOutputFont();
        void initButtonTexture();               // Go to the Button class...
        void initButtons();
        void initScreenTexture();
        void initScreen();

    // anywhere can access this info
    public:
        Calc();                                 // Constructor, sets up the calc intially
        virtual ~Calc();                        // Destructor, cleans everything up at the end

        // Accessor
        const bool running() const;
        
        // Checker from the Button class (button.h and .cpp)
        void getColor();                        // get the button color

        // Functions
        void pollEvents();                      // Checking to see if we have a pc event like ESC, key stroke, etc.
        void getMousePos();                     // Getting the coords of the mouse for later use
        void buttonClick();                     // Checks to see if one of the buttons has been clicked (then flips color combo)
      
        void updateScreen(std::string value);   // Put the argument on the screen         
        void update();                          // Changing things in the backend, will then be pushed to front with render
        
        void renderScreen(sf::RenderTarget &target);
        void render();                          // Pushes changes from backend to the screen
};