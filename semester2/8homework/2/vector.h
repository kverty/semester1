#pragma once

#include <exception>
#include <iostream>

/// exception, thorwn when we are trying to sum or multiple two vectors with different number of dimensions
class DifferentDim
{

};

/// vector with changable number of coordinates. Coordinates should have operation + - and *, in other words you should be able to add one coordinate to another

template <typename T>
class Vector
{
public:
    /// constructor with no paramters creates 2 dimensional null-vector
    explicit Vector() : dim(2)
    {
        coordinates = new T[2];
        coordinates[0] = 0;
        coordinates[1] = 0;
    }
    /// constructor with one integer paramter dim creates dim-dimensional null-vector
    explicit Vector(int dim) : dim(dim)
    {
        coordinates = new T[dim];
        for (int i = 0; i < dim; i++)
            coordinates[i] = 0;
    }

    explicit Vector(int dim, T* coordinates);
    /// copy-constructor
    Vector(Vector<T> &arg) : dim(arg.mDim()), coordinates(arg.mCoordinates()) {}
    ~Vector();
    /// some operators
    Vector<T> operator+(const Vector<T> &arg) throw (DifferentDim);
    Vector<T> operator-(const Vector<T> &arg) throw (DifferentDim);
    Vector<T> operator*(T scalar);
    T operator*(const Vector<T> &arg) throw (DifferentDim);
    bool operator==(const Vector<T> &arg);
    ///checks if vector is zero
    bool isZero() const;

private:
    int mDim() const;
    T *mCoordinates() const;
    int dim;
    T *coordinates;

};

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
bool Vector<T>::isZero() const
{
    bool allCoordinatesZero = true;

    for (int i = 0; i < dim; i++)
        allCoordinatesZero = allCoordinatesZero && (coordinates[i] == 0);

    return allCoordinatesZero;
}

template <typename T>
T *Vector<T>::mCoordinates() const
{
    T *newCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
    {
        newCoordinates[i] = coordinates[i];
    }

    return newCoordinates;
}

template <typename T>
int Vector<T>::mDim() const
{
    return dim;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &arg) throw (DifferentDim)
{
    if (dim != arg.mDim())
        throw DifferentDim();

    T *resultCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
        resultCoordinates[i] = coordinates[i] + arg.mCoordinates()[i];

    Vector<T> result(dim, resultCoordinates);
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &arg) throw (DifferentDim)
{
    if (dim != arg.mDim())
        throw DifferentDim();

    T *resultCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
        resultCoordinates[i] = coordinates[i] - arg.mCoordinates()[i];

    Vector<T> result(dim, resultCoordinates);
    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T> &arg) throw (DifferentDim)
{
    if (dim != arg.mDim())
        throw DifferentDim();

    T result = 0;

    for (int i = 0; i < dim; i++)
        result += coordinates[i] * arg.mCoordinates()[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(T scalar)
{
    T *resultCoordinates = new T[dim];

    for (int i = 0; i < dim; i++)
        resultCoordinates[i] = coordinates[i] * scalar;

    Vector<T> result(dim, resultCoordinates);
    return result;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &arg)
{
    if (dim != arg.mDim())
        return false;

    bool areEqual = true;

    for (int i = 0; i < dim; i++)
        areEqual = areEqual && (coordinates[i] == arg.mCoordinates()[i]);

    return areEqual;
}
