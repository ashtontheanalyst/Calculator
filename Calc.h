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

        void initVariables();           // set up our var's to be used later in the program
        void initWindow();              // set the application window

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