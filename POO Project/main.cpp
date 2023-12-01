#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:
    static int instanceCount;
    const int instanceId;
    double* dynamicNumbers;
    int dynamicNumbersSize;

public:
    Calculator() : instanceId(++instanceCount), dynamicNumbers(nullptr), dynamicNumbersSize(0) {}

    Calculator(const double* numbers, int size) : instanceId(++instanceCount), dynamicNumbers(nullptr), dynamicNumbersSize(size) {
        if (size > 0) {
            dynamicNumbers = new double[size];
            for (int i = 0; i < size; ++i) {
                dynamicNumbers[i] = numbers[i];
            }
        }
    }

    ~Calculator() {
        delete[] dynamicNumbers;
    }

    static int getInstanceCount() {
        return instanceCount;
    }

    static void performGenericOperation() {
        std::cout << "Performing a generic operation in Calculator class.\n";
    }

    void addNumber(double number) {
        // Realizati validari aici, daca este cazul.
        double* newNumbers = new double[dynamicNumbersSize + 1];
        for (int i = 0; i < dynamicNumbersSize; ++i) {
            newNumbers[i] = dynamicNumbers[i];
        }
        newNumbers[dynamicNumbersSize++] = number;

        delete[] dynamicNumbers;
        dynamicNumbers = newNumbers;
    }

    double* getNumbers() const {
        return dynamicNumbers;
    }

    friend std::ostream& operator<<(std::ostream& os, const Calculator& calc);
    friend std::istream& operator>>(std::istream& is, Calculator& calc);
};



int main() {

	
	cout << endl << "hello!";
}