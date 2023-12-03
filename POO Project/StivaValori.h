#pragma once

class StivaValori {
private:
    double* values;
    int capacity;
    int size;

public:
    StivaValori(int capacitateInitiala = 10);
    ~StivaValori();

    double top() const;
    void pop();
    void push(double value);

    double* getValori() const;
    int getCapacitate() const;
    int getDimensiune() const;

    void setValori(double* newValues);
    void setCapacitate(int newCapacity);
    void setDimensiune(int newSize);

    bool operator==(const StivaValori& other) const;
    bool operator!=(const StivaValori& other) const;
};

