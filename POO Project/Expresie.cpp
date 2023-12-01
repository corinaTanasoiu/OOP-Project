#include "Expresie.h"
#include <iostream>
#include <cmath>
#include <string>

Expresie::Expresie() {}

Expresie::Expresie(const std::string& expresie) {
    vectorCaractere = VectorDinamic(expresie.size());
    vectorOperand1 = VectorDinamic(1);
    vectorOperand2 = VectorDinamic(1);
}

Expresie::~Expresie() {}

bool Expresie::esteCaracterOperand(char caracter) {
    return (caracter >= '0' && caracter <= '9') || caracter == '.' || caracter == 'v';
}

void Expresie::parseazaExpresia() {
    int indexCaractere = 0;

    for (int i = 0; i < vectorCaractere.getDimensiune(); ++i) {
        char caracter = getCaracterAt(i);

        if (esteCaracterOperand(caracter)) {
            if (caracter == 'v') {
                int dimensiuneVector = 0;
                std::cout << "Introduceti dimensiunea vectorului: ";
                std::cin >> dimensiuneVector;

                std::cout << "Introduceti elementele vectorului (separate prin spatii): ";
                vectorOperand1 = VectorDinamic(dimensiuneVector);
                for (int j = 0; j < dimensiuneVector; ++j) {
                    std::cin >> vectorOperand1[j];
                }
            }
            else {
                vectorOperand1[0] = std::stod(std::string(1, caracter));
            }
        }
        else {
            vectorCaractere[indexCaractere++] = caracter;
        }
    }
}


double Expresie::ridicareLaPutere(double baza, double exponent) {
    return std::pow(baza, exponent);
}

double Expresie::extragereRadical(double radicand, double indice) {
    if (radicand < 0 && std::fmod(indice, 2) == 0) {
        throw std::runtime_error("Extragerea radicalului dintr-un numar negativ nu este definita pentru un indice par.");
    }
    return std::pow(radicand, 1 / indice);
}

double Expresie::evalueazaExpresia() {
    int index = 0;
    double rezultat = 0.0;

    for (int i = 0; i < vectorCaractere.getDimensiune(); ++i) {
        char caracter = getCaracterAt(i);

        if (esteCaracterOperand(caracter)) {
            // ...
        }
        else {
            switch (caracter) {
            case '+':
            case '-':
            case '*':
            case '/':
                // Implementa?i aici opera?iile aritmetice
                break;
            case '^':
                ++index;
                double exponent = evalueazaExpresiaRecursiv(index);
                rezultat = ridicareLaPutere(rezultat, exponent);
                break;
            case 'r':
                ++index;
                double indice = evalueazaExpresiaRecursiv(index);
                rezultat = extragereRadical(rezultat, indice);
                break;
            }
        }
    }

    return rezultat;
}


Expresie::operator double() const {
    return evalueazaExpresia();
}

std::ostream& operator<<(std::ostream& os, const Expresie& expr) {
    os << "Expresie: ";
    for (int i = 0; i < expr.getVectorCaractere().size(); ++i) {
        os << expr.getCaracterAt(i);
    }
    os << std::endl;

    os << "Operand1: " << expr.vectorOperand1 << std::endl;
    os << "Operand2: " << expr.vectorOperand2 << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Expresie& expr) {
    std::string expresie;
    std::getline(is, expresie);
    expr = Expresie(expresie);
    return is;
}

char Expresie::getCaracterAt(int index) const {
    return vectorCaractere[index];
}
