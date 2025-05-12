#include <iostream>
#include "Calc.h"

// PRIVATE FUNCTIONS ----------------------------------------------------------------------

void Calc::initVariables() {
    window = nullptr;

    backgroundColor = sf::Color(44, 55, 68, 255);
    buttonColor = sf::Color(65, 79, 101, 255);
    buttonTextColor = sf::Color(149, 243, 248, 255);
    buttonAboveTextColor = sf::Color(255, 255, 0, 255);
    outputColor = sf::Color(148, 140, 123, 255);
}
        

void Calc::initWindow() {
    // set calculator window size in px
    videomode.height = 650;
    videomode.width = 425;

    // create the window itself, nothing within it yet (sizing, titlebar, close button)
    window = new sf::RenderWindow(videomode, "Scientific Calulator by Ashton Smith", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(40); // limit to make sure it's not using tons of cpu power
}


// Initialize/load in the font ttf
void Calc::initFont() {
    if (!font.loadFromFile("/home/dementus/code/cpp/Calculator/RobotoCondensed-VariableFont_wght.ttf")) {
        std::cout << "ERROR: Failure to load in font ttf file..." << '\n';
    }
}


// Initialize our rounded rectangle
void Calc::initButtonTexture() {
    // Making sure it loads in, if not shoot an error
    // png from: https://www.iconsdb.com/white-icons/rounded-rectangle-icon.html
    if (!buttonTexture.loadFromFile("roundedRectangle.png")) {
        std::cout << "ERROR: Couldn't load in rounded rectangle object file..." << '\n';
    }
}


// BUTTONS, from here look at Button.h and Button.cpp
void Calc::initButtons() {
    buttons.emplace_back("1", font, buttonTexture, 13.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 567.f, buttonColor, buttonTextColor);

    buttons.emplace_back("1", font, buttonTexture, 13.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 494.f, buttonColor, buttonTextColor);

    buttons.emplace_back("1", font, buttonTexture, 13.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 421.f, buttonColor, buttonTextColor);

    buttons.emplace_back("1", font, buttonTexture, 13.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 348.f, buttonColor, buttonTextColor);

    buttons.emplace_back("1", font, buttonTexture, 13.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 275.f, buttonColor, buttonTextColor);

    buttons.emplace_back("1", font, buttonTexture, 13.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("4", font, buttonTexture, 262.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("5", font, buttonTexture, 345.f, 202.f, buttonColor, buttonTextColor);
}





// PUBLIC FUNCTIONS -----------------------------------------------------------------------

// Constructor, run the initialization
Calc::Calc() {
    // Call out initialization functions to build the class
    initVariables();
    initWindow();
    initFont();
    initButtonTexture();
    initButtons();
}


// Destructor, clean everything up at the end
Calc::~Calc() {
    delete window;
}


// Accessor, return private value to public side
const bool Calc::running() const {
    return window->isOpen();
}


// Checking for inputs from computer, actions (for now just 'ESC' and close button)
void Calc::pollEvents() {
    while(window->pollEvent(ev)) {
        switch (ev.type) {
            // If the close button is pressed in the window, close it
            case sf::Event::Closed:
                window->close();
                break;
            
            // If the 'ESC' key is pressed, do the same thing
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
            break;
        }
    }
}


// This is our backend logic where the changes happen value wise
void Calc::update() {
    pollEvents();
}


// This taked those backend changes and pushes them to the screen
void Calc::render() {
    window->clear(sf::Color(backgroundColor));  // between frames put a black screen

    // Render the buttons from the Button class and it's render function
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].render(*window);
    }

    window->display();
}