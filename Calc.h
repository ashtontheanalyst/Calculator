// Calc class definition, has the var's and functions

#pragma once

#include "Button.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

class Calc {
    // internal details
    private:
        // Window
        sf::RenderWindow * window;      // a window SFML object
        sf::VideoMode videomode;        // sets our h, w, full screen, title bar, etc.
        sf::Event ev;                   // checks for events on the pc, clicks, push, etc.

        // Font and text
        sf::Font font;                  // This font is to be used for the buttons and etc.
        sf::Texture buttonTexture;

        // Colors
        sf::Color backgroundColor;
        sf::Color buttonColor;
        sf::Color buttonTextColor;
        sf::Color buttonAboveTextColor;
        sf::Color outputColor;

        // Stores our buttons
        std::vector<Button> buttons;
        
        // Init Functions
        void initVariables();           // set up our var's to be used later in the program
        void initWindow();              // set the application window
        void initFont();
        void initButtonTexture();        // SFML doesn't have a native rounded rectangle so we're piecing it together with an image of one
        void initButtons();

    // anywhere can access this info
    public:
        Calc();                         // Constructor, sets up the calc intially
        virtual ~Calc();                // Destructor, cleans everything up at the end

        // Accessor
        const bool running() const;

        // Functions
        void pollEvents();              // Checking to see if we have a pc event
        
        void update();                  // Changing things in the backend, will then be pushed to front with render
        
        void render();                  // Pushes changes from backend to the screen
};