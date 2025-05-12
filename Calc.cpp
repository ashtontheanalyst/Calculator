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

    black = sf::Color(0, 0, 0, 255);
    white = sf::Color(255, 255, 255, 255);
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
    // Bottom Row
    buttons.emplace_back("0", font, buttonTexture, 13.f, 567.f, black, white);                      // first button, on far left
    buttons.emplace_back(".", font, buttonTexture, 96.f, 567.f, black, white);
    buttons.emplace_back("( - )", font, buttonTexture, 179.f, 567.f, black, white);
    buttons.emplace_back("+", font, buttonTexture, 262.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("[-EQL-]", font, buttonTexture, 345.f, 567.f, white, black);               // last button, on far right

    // Second row from bottom
    buttons.emplace_back("1", font, buttonTexture, 13.f, 494.f, black, white);
    buttons.emplace_back("2", font, buttonTexture, 96.f, 494.f, black, white);
    buttons.emplace_back("3", font, buttonTexture, 179.f, 494.f, black, white);
    buttons.emplace_back("-", font, buttonTexture, 262.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("Ans", font, buttonTexture, 345.f, 494.f, buttonColor, buttonTextColor);

    // Third from bottom
    buttons.emplace_back("4", font, buttonTexture, 13.f, 421.f, black, white);
    buttons.emplace_back("5", font, buttonTexture, 96.f, 421.f, black, white);
    buttons.emplace_back("6", font, buttonTexture, 179.f, 421.f, black, white);
    buttons.emplace_back("x", font, buttonTexture, 262.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("Del", font, buttonTexture, 345.f, 421.f, buttonColor, buttonTextColor);

    // Fourth from bottom
    buttons.emplace_back("7", font, buttonTexture, 13.f, 348.f, black, white);
    buttons.emplace_back("8", font, buttonTexture, 96.f, 348.f, black, white);
    buttons.emplace_back("9", font, buttonTexture, 179.f, 348.f, black, white);
    buttons.emplace_back("/", font, buttonTexture, 262.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("Clear", font, buttonTexture, 345.f, 348.f, buttonColor, buttonTextColor);

    // Fifth from bottom
    buttons.emplace_back("sin", font, buttonTexture, 13.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("cos", font, buttonTexture, 96.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("tan", font, buttonTexture, 179.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("log", font, buttonTexture, 262.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("ln", font, buttonTexture, 345.f, 275.f, buttonColor, buttonTextColor);

    // Top row, sixth from bottom
    buttons.emplace_back("sq", font, buttonTexture, 13.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("pow", font, buttonTexture, 96.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("sqrt", font, buttonTexture, 179.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("abs", font, buttonTexture, 262.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("hash", font, buttonTexture, 345.f, 202.f, buttonColor, buttonTextColor);
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


// Checking (getting) the button color
void Calc::checkColor() {
    // This is the accessor function from Button.h
    sf::Color color = buttons[1].getColor();

    // Output for now, gives us an idea of what's going on
    //std::cout << (int)color.r << " ";
    //std::cout << (int)color.g << " ";
    //std::cout << (int)color.b << '\n';
}


// Checking (getting) the boundary
// Shoukd this actually return the rect?
void Calc::checkBoundary() {
    sf::FloatRect bounds = buttons[1].getGlobalBounds();

    //std::cout << bounds.left << " " << bounds.width << '\n';
    //std::cout << bounds.top << " " << bounds.height << '\n';

    bool checker = buttons[0].clicked(mousePos);
    std::cout << checker << '\n';
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


// Get mouse pos coords
void Calc::getMousePos() {
    mousePosRaw = sf::Mouse::getPosition(*window);
    mousePos = window->mapPixelToCoords(mousePosRaw);
}


// flip button color if button has been clicked
void Calc::buttonClick() {
    // If left click...
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Making sure button is not being held
        if (mouseHeld == false) {
            mouseHeld = true;
            
            // Do this...
            checkColor();

            // Check for click on button here
            checkBoundary();

            // Run through the list
            for (int i = 0; i < buttons.size(); i++) {
                if (buttons[i].clicked(mousePos)) {
                    std::cout << "Clicked" << '\n';
                }
            }
        }
    }
    else {
        mouseHeld = false;
    }
}


// This is our backend logic where the changes happen value wise
void Calc::update() {
    pollEvents();
    getMousePos();
    buttonClick();
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