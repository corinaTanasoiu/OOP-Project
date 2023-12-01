#pragma once
#include <iostream>

class VectorDinamic {
private:
    double* vector;
    int dimensiune;

public:
    VectorDinamic();
    VectorDinamic(int dim);
    ~VectorDinamic();

    double& operator[](int index);
    int getDimensiune() const;

    static VectorDinamic adunaVectori(const VectorDinamic& v1, const VectorDinamic& v2);
    static VectorDinamic scadeVectori(const VectorDinamic& v1, const VectorDinamic& v2);
    static VectorDinamic inmultesteVectorScalar(const VectorDinamic& v, double scalar);
    static VectorDinamic imparteVectorScalar(const VectorDinamic& v, double scalar);

    // Supraincarcare operatori
    VectorDinamic operator+(const VectorDinamic& v) const;
    VectorDinamic operator-(const VectorDinamic& v) const;
    VectorDinamic operator*(double scalar) const;
    VectorDinamic operator/(double scalar) const;
    double& operator++();    // pre-incrementare
    double& operator--();    // pre-decrementare
    VectorDinamic operator++(int); // post-incrementare
    VectorDinamic operator--(int); // post-decrementare
    VectorDinamic operator!() const;  // Supraincarcare operator de negatie (!)

    friend std::ostream& operator<<(std::ostream& os, const VectorDinamic& v);
    friend std::istream& operator>>(std::istream& is, VectorDinamic& v);
};
