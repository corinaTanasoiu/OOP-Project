#include "StivaOperator.h"
#include "StivaValori.h"
#include "Expresie.h"

int main() {
    std::string expression;
    std::cout << "Introduceti expresia matematica: ";
    std::getline(std::cin, expression);

    std::stack<double> values;
    StivaOperator operators;

    std::istringstream iss(expression);

    char token;
    while (iss >> token) {
        if (Expresie::esteCifra(token)) {
            iss.putback(token);
            double value;
            iss >> value;
            values.push(value);
        }
        else if (Expresie::esteOperator(token)) {
            while (!operators.empty() &&
                Expresie::getOrdine(operators.top()) >=
                Expresie::getOrdine(token)) {
                double operand2 = values.top();
                values.pop();
                double operand1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(Expresie::Operator(operand1, operand2, op));
            }
            operators.push(token);
        }
        else if (token == '(') {
            operators.push(token);
        }
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = values.top();
                values.pop();
                double operand1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(Expresie::Operator(operand1, operand2, op));
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        double operand2 = values.top();
        values.pop();
        double operand1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(Expresie::Operator(operand1, operand2, op));
    }

    if (!values.empty()) {
        std::cout << "Rezultatul expresiei este: " << values.top() << std::endl;
    }
    else {
        std::cerr << "Eroare: Expresie invalida!" << std::endl;
    }

    return 0;
}
