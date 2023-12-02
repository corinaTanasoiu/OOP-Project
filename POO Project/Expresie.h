#pragma once
#include "VectorDinamic.h"

class Expresie {
private:
    VectorDinamic vectorCaractere;
    VectorDinamic vectorOperand1;
    VectorDinamic vectorOperand2;

    bool esteCaracterOperand(char caracter) const;  // Adăugat const
    void parseazaExpresia();

    double ridicareLaPutere(double baza, double exponent);
    double extragereRadical(double radicand, double indice);

    double evalueazaExpresiaRecursiv(int& index) const;  // Adăugat const

public:
    Expresie();
    Expresie(const std::string& expresie);
    ~Expresie();

    double evalueazaExpresia() const;  // Adăugat const

    // Supraincarcare operatori
    explicit operator double() const;  // Supraincarcare operator de cast explicit

    friend std::ostream& operator<<(std::ostream& os, const Expresie& expr);
    friend std::istream& operator>>(std::istream& is, Expresie& expr);

    // Funcție pentru a obține caracterul la un anumit index
    char getCaracterAt(int index) const;
};
