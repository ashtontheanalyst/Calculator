// Calc class definition, has the var's and functions

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Calc {
    // internal details
    private:
        // Window
        sf::RenderWindow * window;      // a window SFML object
        sf::VideoMode videomode;        // sets our h, w, full screen, title bar, etc.
        sf::Event ev;                   // checks for events on the pc, clicks, push, etc.

        // Colors
        sf::Color backgroundColor;
        sf::Color buttonColor;
        sf::Color buttonTextColor;
        sf::Color buttonAboveTextColor;
        sf::Color outputColor;

        // Rounded Rectangle Buttons
        sf::Texture recTex;
        sf::Sprite roundedRec;
        int xrr;                        // initial rounded rec x pos. for testing
        int yrr;                        // same for y pos.
        
        // Init Functions
        void initVariables();           // set up our var's to be used later in the program
        void initWindow();              // set the application window
        void initRoundedRec();          // SFML doesn't have a native rounded rectangle so we're piecing it together with an image of one

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