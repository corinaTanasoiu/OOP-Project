#pragma once

class StivaOperator {
private:
    char* operators;
    int capacity;
    int size;

public:
    StivaOperator(int capacitateInitiala = 10);
    ~StivaOperator();

    char top() const;
    bool empty() const;
    void pop();
    void push(char op);

    char* getOperatori() const;
    int getCapacitate() const;
    int getDimensiune() const;

    void setOperatori(char* newOperators);
    void setCapacitate(int newCapacity);
    void setDimensiune(int newSize);

    bool operator==(const StivaOperator& other) const;
    bool operator!=(const StivaOperator& other) const;
};
