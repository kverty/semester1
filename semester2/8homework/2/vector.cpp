#include "vector.h"

template <typename T>
Vector<T>::Vector(int dim, T *coordinates) : dim(dim)
{
    T *newCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
    {
        newCoordinates[i] = coordinates[i];
    }

    this->coordinates = newCoordinates;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->coordinates;
}

template <typename T>
bool Vector<T>::isZero()
{
    bool allCoordinatesZero = true;

    for (int i = 0; i < dim; i++)
        allCoordinatesZero = allCoordinatesZero && (coordinates[i] == 0);

    return allCoordinatesZero;
}

template <typename T>
T *Vector<T>::mCoordinates()
{
    T *newCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
    {
        newCoordinates[i] = coordinates[i];
    }

    return newCoordinates;
}

template <typename T>
int Vector<T>::mDim()
{
    return dim;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &arg) throw (differentDim)
{
    if (this->dim != arg.mDim())
        throw DifferentDim;

    T *resultCoordinates = new T[this->dim];

    for (int i = 0; i < this->dim; i++)
        resultCoordinates[i] = this->coordinates[i] + arg.mCoordinates()[i];

    return Vector<T>(this->dim, resultCoordinates);
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &arg) throw (differentDim)
{
    if (this->dim != arg.mDim())
        throw DifferentDim;

    T *resultCoordinates = new T[this->dim];

    for (int i = 0; i < this->dim; i++)
        resultCoordinates[i] = this->coordinates[i] - arg.mCoordinates()[i];

    return Vector<T>(this->dim, resultCoordinates);
}

template <typename T>
T operator*(const Vector<T> &arg)
{
    if (this->dim != arg.mDim())
        throw DifferentDim;

    T result = 0;

    for (int i = 0; i < this->dim; i++)
        result += this->coordinates[i] * arg.mCoordinates()[i];

    return result;
}
