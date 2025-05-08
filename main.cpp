#include <iostream>
#include "Calc.h"

int main() {

    Calc calc; // create out calc

    // "Game loop"
    while (calc.running()) {
        // Backend logic, contains various functions
        calc.update();

        // Displaying our back end to the front
        calc.render();
    }


    return 0;
}