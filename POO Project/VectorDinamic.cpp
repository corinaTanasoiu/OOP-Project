#include "VectorDinamic.h"

VectorDinamic::VectorDinamic() : vector(nullptr), dimensiune(0) {}

VectorDinamic::VectorDinamic(int dim) : dimensiune(dim) {
    vector = new double[dim];
}

VectorDinamic::~VectorDinamic() {
    delete[] vector;
}

double& VectorDinamic::operator[](int index) {
    return vector[index];
}

int VectorDinamic::getDimensiune() const {
    return dimensiune;
}

VectorDinamic VectorDinamic::adunaVectori(const VectorDinamic& v1, const VectorDinamic& v2) {
    if (v1.dimensiune != v2.dimensiune) {
        throw std::runtime_error("Dimensiunile vectorilor nu coincid pentru adunare.");
    }

    VectorDinamic rezultat(v1.dimensiune);

    for (int i = 0; i < v1.dimensiune; ++i) {
        rezultat.vector[i] = v1.vector[i] + v2.vector[i];
    }

    return rezultat;
}

VectorDinamic VectorDinamic::scadeVectori(const VectorDinamic& v1, const VectorDinamic& v2) {
    if (v1.dimensiune != v2.dimensiune) {
        throw std::runtime_error("Dimensiunile vectorilor nu coincid pentru scadere.");
    }

    VectorDinamic rezultat(v1.dimensiune);

    for (int i = 0; i < v1.dimensiune; ++i) {
        rezultat.vector[i] = v1.vector[i] - v2.vector[i];
    }

    return rezultat;
}

VectorDinamic VectorDinamic::inmultesteVectorScalar(const VectorDinamic& v, double scalar) {
    VectorDinamic rezultat(v.dimensiune);

    for (int i = 0; i < v.dimensiune; ++i) {
        rezultat.vector[i] = v.vector[i] * scalar;
    }

    return rezultat;
}

VectorDinamic VectorDinamic::imparteVectorScalar(const VectorDinamic& v, double scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Impartire la zero.");
    }

    VectorDinamic rezultat(v.dimensiune);

    for (int i = 0; i < v.dimensiune; ++i) {
        rezultat.vector[i] = v.vector[i] / scalar;
    }

    return rezultat;
}

VectorDinamic VectorDinamic::operator+(const VectorDinamic& v) const {
    return adunaVectori(*this, v);
}

VectorDinamic VectorDinamic::operator-(const VectorDinamic& v) const {
    return scadeVectori(*this, v);
}

VectorDinamic VectorDinamic::operator*(double scalar) const {
    return inmultesteVectorScalar(*this, scalar);
}

VectorDinamic VectorDinamic::operator/(double scalar) const {
    return imparteVectorScalar(*this, scalar);
}

double& VectorDinamic::operator++() {
    for (int i = 0; i < dimensiune; ++i) {
        ++vector[i];
    }
    return vector[0];
}

double& VectorDinamic::operator--() {
    for (int i = 0; i < dimensiune; ++i) {
        --vector[i];
    }
    return vector[0];
}

VectorDinamic VectorDinamic::operator++(int) {
    VectorDinamic temp(*this);
    ++(*this);
    return temp;
}

VectorDinamic VectorDinamic::operator--(int) {
    VectorDinamic temp(*this);
    --(*this);
    return temp;
}

VectorDinamic VectorDinamic::operator!() const {
    VectorDinamic rezultat(dimensiune);

    for (int i = 0; i < dimensiune; ++i) {
        rezultat.vector[i] = -vector[i];
    }

    return rezultat;
}

std::ostream& operator<<(std::ostream& os, const VectorDinamic& v) {
    for (int i = 0; i < v.dimensiune; ++i) {
        os << v.vector[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, VectorDinamic& v) {
    for (int i = 0; i < v.dimensiune; ++i) {
        is >> v.vector[i];
    }
    return is;
}