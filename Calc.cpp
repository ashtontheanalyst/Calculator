#include <iostream>
#include "Calc.h"

// PRIVATE FUNCTIONS ----------------------------------------------------------------------

void Calc::initVariables() {
    this->window = nullptr;

    this->backgroundColor = sf::Color(44, 55, 68, 255);
    this->buttonColor = sf::Color(65, 79, 101, 255);
    this->buttonTextColor = sf::Color(149, 243, 248, 255);
    this->buttonAboveTextColor = sf::Color(255, 255, 0, 255);
    this->outputColor = sf::Color(148, 140, 123, 255);
}
        

void Calc::initWindow() {
    // set calculator window size in px
    this->videomode.height = 650;
    this->videomode.width = 425;

    // create the window itself, nothing within it yet (sizing, titlebar, close button)
    this->window = new sf::RenderWindow(this->videomode, "Scientific Calulator by Ashton Smith", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(40); // limit to make sure it's not using tons of cpu power
}


// Initialize our rounded rectangle
void Calc::initRoundedRec() {
    // Making sure it loads in, if not shoot an error
    // png from: https://www.iconsdb.com/white-icons/rounded-rectangle-icon.html
    // The original px is (256, 256) (x, y)
    if (!this->recTex.loadFromFile("roundedRectangle.png")) {
        std::cout << "ERROR: Couldn't load in rounded rectangle object file" << '\n';
    }

    this->xrr = 10;
    this->yrr = 5;

    this->roundedRec.setTexture(this->recTex);                  // set the svg file
    this->roundedRec.scale(0.25f, 0.25f);                       // 256x256 is now 64x64
    this->roundedRec.setColor(sf::Color(this->buttonColor));    // init. w/ button color
    this->roundedRec.setPosition(this->xrr, this->yrr);         // set the initial pos.
}





// PUBLIC FUNCTIONS -----------------------------------------------------------------------

// Constructor, run the initialization
Calc::Calc() {
    // Call out initialization functions to build the class
    this->initVariables();
    this->initWindow();
    this->initRoundedRec();
}


// Destructor, clean everything up at the end
Calc::~Calc() {
    delete this->window;
}


// Accessor, return private value to public side
const bool Calc::running() const {
    return this->window->isOpen();
}


// Checking for inputs from computer, actions (for now just 'ESC' and close button)
void Calc::pollEvents() {
    while(this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            // If the close button is pressed in the window, close it
            case sf::Event::Closed:
                this->window->close();
                break;
            
            // If the 'ESC' key is pressed, do the same thing
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
            break;
        }
    }
}


void Calc::update() {
    this->pollEvents();
}


void Calc::render() {
    this->window->clear(sf::Color(this->backgroundColor));

    this->window->draw(this->roundedRec);

    this->window->display();
}