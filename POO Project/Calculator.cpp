#include "Calculator.h"
#include <iostream>
#include <string>

void Calculator::executaCalcul() {
    std::string expresie;
    while (true) {
        std::cout << "Introduceti o expresie matematica sau 'exit' pentru a iesi: ";
        std::getline(std::cin, expresie);

        if (expresie == "exit") {
            break;
        }

        Expresie expr(expresie);
        std::cout << "Rezultatul este: " << static_cast<double>(expr) << std::endl;
        std::cout << "Starea expresiei: " << expr << std::endl;
    }
}

