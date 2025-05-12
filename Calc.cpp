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


void Calc::initButtons() {
    buttons.emplace_back("##", font, buttonTexture, 10.f, 5.f, buttonColor, buttonTextColor);
    buttons.emplace_back("3", font, buttonTexture, 100.f, 50.f, buttonColor, buttonTextColor);
    buttons.emplace_back("+", font, buttonTexture, 200.f, 100.f, buttonColor, buttonTextColor);

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


void Calc::update() {
    pollEvents();
}


void Calc::render() {
    window->clear(sf::Color(backgroundColor));

    for (auto& button : buttons) {
        button.render(*window);
    }

    window->display();
}