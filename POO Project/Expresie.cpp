#include "Expresie.h"

double Expresie::Operator(double operand1, double operand2, char op) {
    switch (op) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 != 0.0) {
            return operand1 / operand2;
        }
        else {
            std::cerr << "Eroare: Impartire la zero!" << std::endl;
            return 0.0;
        }
    case '^': return std::pow(operand1, operand2);
    default:
        std::cerr << "Eroare: Operator necunoscut!" << std::endl;
        return 0.0;
    }
}


int Expresie::getOrdine(char op) {
    if (op == '(' || op == '[') {
        return 0; 
    }
    else if (op == ')' || op == ']') {
        return 4; 
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    return 0;
}

bool Expresie::esteOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool Expresie::esteCifra(char ch) {
    return std::isdigit(static_cast<unsigned char>(ch));
}

bool Expresie::esteFunctie(const std::string& functie) {
    return functie == "sqrt" || functie == "sin" || functie == "cos" || functie == "tan";
}

double Expresie::Functie(const std::string& function, double operand) {
    if (function == "sqrt") {
        return std::sqrt(operand);
    }
    else if (function == "sin") {
        return std::sin(operand);
    }
    else if (function == "cos") {
        return std::cos(operand);
    }
    else if (function == "tan") {
        return std::tan(operand);
    }
    else {
        std::cerr << "Eroare: Functie necunoscuta!" << std::endl;
        return 0.0;
    }
}
