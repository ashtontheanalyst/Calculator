#include <iostream>
#include "Calc.h"

// PRIVATE FUNCTIONS ----------------------------------------------------------------------

void Calc::initVariables() {
    window = nullptr;

    backgroundColor = sf::Color(44, 55, 68, 255);
    buttonColor = sf::Color(65, 79, 101, 255);
    numButtonColor = sf::Color(18, 25, 32, 255);
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


// Initialize/load in the font ttf for buttons
void Calc::initButtonFont() {
    if (!buttonFont.loadFromFile("/home/dementus/code/cpp/Calculator/Assets/RobotoCondensed-VariableFont_wght.ttf")) {
        std::cout << "ERROR: Failure to load in font ttf file for buttons..." << '\n';
    }
}


// Output font initialization
void Calc::initOutputFont() {
    if (!outputFont.loadFromFile("/home/dementus/code/cpp/Calculator/Assets/digital-7.monoitalic.ttf")) {
        std::cout << "ERROR: Failure to load in font ttf file for screen/output..." << '\n';
    }
}


// Initialize our rounded rectangle
void Calc::initButtonTexture() {
    // Making sure it loads in, if not shoot an error
    // png from: https://www.iconsdb.com/white-icons/rounded-rectangle-icon.html
    if (!buttonTexture.loadFromFile("Assets/roundedRectangle.png")) {
        std::cout << "ERROR: Couldn't load in rounded rectangle object file for buttons..." << '\n';
    }
}


// BUTTONS, from here look at Button.h and Button.cpp
void Calc::initButtons() {
    // Bottom Row
    buttons.emplace_back("0", buttonFont, buttonTexture, 13.f, 567.f, numButtonColor, white);             // first button, on far left
    buttons.emplace_back(".", buttonFont, buttonTexture, 96.f, 567.f, numButtonColor, white);
    buttons.emplace_back("'( - )", buttonFont, buttonTexture, 179.f, 567.f, numButtonColor, white);
    buttons.emplace_back("+", buttonFont, buttonTexture, 262.f, 567.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'[-EQL-]", buttonFont, buttonTexture, 345.f, 567.f, white, black);               // last button, on far right

    // Second row from bottom
    buttons.emplace_back("1", buttonFont, buttonTexture, 13.f, 494.f, numButtonColor, white);
    buttons.emplace_back("2", buttonFont, buttonTexture, 96.f, 494.f, numButtonColor, white);
    buttons.emplace_back("3", buttonFont, buttonTexture, 179.f, 494.f, numButtonColor, white);
    buttons.emplace_back("-", buttonFont, buttonTexture, 262.f, 494.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'Ans", buttonFont, buttonTexture, 345.f, 494.f, buttonColor, buttonTextColor);

    // Third from bottom
    buttons.emplace_back("4", buttonFont, buttonTexture, 13.f, 421.f, numButtonColor, white);
    buttons.emplace_back("5", buttonFont, buttonTexture, 96.f, 421.f, numButtonColor, white);
    buttons.emplace_back("6", buttonFont, buttonTexture, 179.f, 421.f, numButtonColor, white);
    buttons.emplace_back("*", buttonFont, buttonTexture, 262.f, 421.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'Del", buttonFont, buttonTexture, 345.f, 421.f, buttonColor, buttonTextColor);

    // Fourth from bottom
    buttons.emplace_back("7", buttonFont, buttonTexture, 13.f, 348.f, numButtonColor, white);
    buttons.emplace_back("8", buttonFont, buttonTexture, 96.f, 348.f, numButtonColor, white);
    buttons.emplace_back("9", buttonFont, buttonTexture, 179.f, 348.f, numButtonColor, white);
    buttons.emplace_back("/", buttonFont, buttonTexture, 262.f, 348.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'Clear", buttonFont, buttonTexture, 345.f, 348.f, buttonColor, buttonTextColor);

    // Fifth from bottom
    buttons.emplace_back("'sin", buttonFont, buttonTexture, 13.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'cos", buttonFont, buttonTexture, 96.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'tan", buttonFont, buttonTexture, 179.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'log", buttonFont, buttonTexture, 262.f, 275.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'ln", buttonFont, buttonTexture, 345.f, 275.f, buttonColor, buttonTextColor);

    // Top row, sixth from bottom
    buttons.emplace_back("'sq", buttonFont, buttonTexture, 13.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'pow", buttonFont, buttonTexture, 96.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'sqrt", buttonFont, buttonTexture, 179.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'abs", buttonFont, buttonTexture, 262.f, 202.f, buttonColor, buttonTextColor);
    buttons.emplace_back("'hash", buttonFont, buttonTexture, 345.f, 202.f, buttonColor, buttonTextColor);
}


// Initialize our screen
void Calc::initScreenTexture() {
    if (!screenTexture.loadFromFile("Assets/screenRectangle.png")) {
        std::cout << "ERROR: Couldn't load in rounded rectangle object file for screen..." << '\n';
    }
}


// Build out the screen base
void Calc::initScreen() {
    // The screen itself, the background
    screen.setTexture(screenTexture);
    screen.setColor(black);
    screen.setScale(1.0f, 0.55f);                   // Turns the png from 256x256 to 399x126
    screen.setPosition(13.0, -7.0);

    // The text on the screen
    output.setFont(outputFont);
    output.setPosition(sf::Vector2f(25.f, 0.f));    // There's already 20px of padding on the y-axis, so the actual pos. is (25, 20ish)
    output.setCharacterSize(60);
    output.setFillColor(outputColor);
    output.setString("");                           // Intro message
}





// PUBLIC FUNCTIONS -----------------------------------------------------------------------

// Constructor, run the initialization
Calc::Calc() {
    // Call out initialization functions to build the class
    initVariables();
    initWindow();
    initButtonFont();
    initOutputFont();
    initButtonTexture();
    initButtons();
    initScreenTexture();
    initScreen();
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
void Calc::getColor() {
    // This is the accessor function from Button.h
    sf::Color color = buttons[1].getColor();

    // Output for now, gives us an idea of what's going on
    //std::cout << (int)color.r << " ";
    //std::cout << (int)color.g << " ";
    //std::cout << (int)color.b << '\n';
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


// Get mouse pos coords for buttonClick()
void Calc::getMousePos() {
    mousePosRaw = sf::Mouse::getPosition(*window);
    mousePos = window->mapPixelToCoords(mousePosRaw);
}


// See what button was clicked and return it's value
void Calc::buttonClick() {
    // If left click...
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Making sure button is not being held
        if (mouseHeld == false) {
            mouseHeld = true;

            // Run through the list of buttons and compare it to the clicked mouse pos.
            // If the mouse is clicking a button, then do this...
            for (int i = 0; i < buttons.size(); i++) {
                // .clicked() is in Button.h
                if (buttons[i].clicked(mousePos)) {

                    // get the value from the Buttons class
                    input = buttons[i].getValue();

                    // Put that the button value to input
                    updateScreen(input);
                }
            }
        }
    }
    else {
        mouseHeld = false;
    }
}


// Key presses, similar logic to buttonClick()
void Calc::keyClick() {
    // 0 - 9 and .
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
        // Make sure button is not being held, has to be indiv. click each time
        if (!keyHeld) {
            keyHeld = true;
            // Assigns the string value "0" to the kyboard key 0
            input = "0";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "1";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "2";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "3";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "4";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "5";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "6";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "7";
            updateScreen(input);
        }
    }
    // multiply (this is above 8 because they both use the Num8 value)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
            if (keyHeld == false) {
                keyHeld = true;
                input = "*";
                updateScreen(input);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "8";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "9";
            updateScreen(input);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
        if (!keyHeld) {
            keyHeld = true;
            input = ".";
            updateScreen(input);
        }
    }

    // Math
    // plus
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
            if (keyHeld == false) {
                keyHeld = true;
                input = "+";
                updateScreen(input);
            }
        }
    }
    // subtract
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "-";
            updateScreen(input);
        }
    }
    // multiply - This is above the 8 key since they both use Num8 and it uses shift
    // divide
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)) {
        if (!keyHeld) {
            keyHeld = true;
            input = "/";
            updateScreen(input);
        }
    }

    // Reset keyHeld
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Period) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Dash) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Slash) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
    
    keyHeld = false;
    }
}


// This will put the passed argument onto the screen, the value in the button
void Calc::updateScreen(std::string input) {
    runningInput = output.getString();                  // gets the most current string value from on screen
    
    runningInput += input;                              // add the new value to it
    
    output.setString(runningInput);                     // assigns output to the updated string
}


// This is our backend logic where the changes happen value wise
void Calc::update() {
    pollEvents();
    getMousePos();
    buttonClick();
    keyClick();
}


// Render the screen and text
void Calc::renderScreen(sf::RenderTarget &target) {
    target.draw(screen);
    target.draw(output);
}


// This taked those backend changes and pushes them to the screen
void Calc::render() {
    window->clear(sf::Color(backgroundColor));  // between frames put a black screen

    // Render the buttons from the Button class and it's render function
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].render(*window);
    }

    // Render the screen
    renderScreen(*window);

    window->display();
}