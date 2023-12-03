#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cmath>

class Expresie {
public:
    static double Operator(double operand1, double operand2, char op);
    static int getOrdine(char op);
    static bool esteOperator(char ch);
    static bool esteCifra(char ch);
    static bool esteFunctie(const std::string& function);
    static double Functie(const std::string& function, double operand);
};
