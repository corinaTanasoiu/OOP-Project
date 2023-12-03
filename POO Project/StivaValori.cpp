#include "StivaValori.h"
#include <algorithm>  
#include<cmath>
StivaValori::StivaValori(int capacitateInitiala) : capacity(capacitateInitiala), size(0) {
    values = new double[capacity];
}

StivaValori::~StivaValori() {
    delete[] values;
}

double StivaValori::top() const {
    if (size > 0) {
        return values[size - 1];
    }
    return 0.0;
}

void StivaValori::pop() {
    if (size > 0) {
        size--;
    }
}

void StivaValori::push(double value) {
    if (size == capacity) {
        capacity *= 2;
        double* newValues = new double[capacity];
        std::copy(values, values + size, newValues);
        delete[] values;
        values = newValues;
    }

    values[size++] = value;
}

double* StivaValori::getValori() const {
    return values;
}

int StivaValori::getCapacitate() const {
    return capacity;
}

int StivaValori::getDimensiune() const {
    return size;
}

void StivaValori::setValori(double* newValues) {
    values = newValues;
}

void StivaValori::setCapacitate(int newCapacity) {
    capacity = newCapacity;
}

void StivaValori::setDimensiune(int newSize) {
    size = newSize;
}

bool StivaValori::operator==(const StivaValori& other) const {
    return (size == other.size && capacity == other.capacity &&
        std::equal(values, values + size, other.values, [](double a, double b) {
            return std::fabs(a - b) < 1e-9;
            }));
}

bool StivaValori::operator!=(const StivaValori& other) const {
    return !(*this == other);
}
