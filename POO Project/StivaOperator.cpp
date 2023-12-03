#include "StivaOperator.h"
#include <algorithm> 

StivaOperator::StivaOperator(int capacitateInitiala) : capacity(capacitateInitiala), size(0) {
    operators = new char[capacity];
}

StivaOperator::~StivaOperator() {
    delete[] operators;
}

char StivaOperator::top() const {
    if (size > 0) {
        return operators[size - 1];
    }
    return '\0';
}

bool StivaOperator::empty() const {
    return size == 0;
}

void StivaOperator::pop() {
    if (size > 0) {
        size--;
    }
}

void StivaOperator::push(char op) {
    if (size == capacity) {
        capacity *= 2;
        char* newOperators = new char[capacity];
        for (int i = 0; i < size; i++) {
            newOperators[i] = operators[i];
        }
        delete[] operators;
        operators = newOperators;
    }

    operators[size++] = op;
}

char* StivaOperator::getOperatori() const {
    return operators;
}

int StivaOperator::getCapacitate() const {
    return capacity;
}

int StivaOperator::getDimensiune() const {
    return size;
}

void StivaOperator::setOperatori(char* newOperators) {
    operators = newOperators;
}

void StivaOperator::setCapacitate(int newCapacity) {
    capacity = newCapacity;
}

void StivaOperator::setDimensiune(int newSize) {
    size = newSize;
}

bool StivaOperator::operator==(const StivaOperator& other) const {
    return (size == other.size && capacity == other.capacity &&
        std::equal(operators, operators + size, other.operators));
}

bool StivaOperator::operator!=(const StivaOperator& other) const {
    return !(*this == other);
}

