#pragma once

#include <exception>
#include <iostream>

/// exception, thorwn when we are trying to sum or multiple two vectors with different number of dimensions
class DifferentDimensionException
{

};

/// vector with changable number of coordinates. Coordinates should have operation + - and *, in other words you should be able to add one coordinate to another

template <typename T>
class Vector
{
public:
    /// constructor with no paramters creates 2 dimensional null-vector
    explicit Vector() : mDim(2)
    {
        mCoordinates = new T[2];
        mCoordinates[0] = 0;
        mCoordinates[1] = 0;
    }
    /// constructor with one integer paramter dim creates dim-dimensional null-vector
    explicit Vector(int dim) : mDim(dim)
    {
        mCoordinates = new T[mDim];
        for (int i = 0; i < mDim; i++)
            mCoordinates[i] = 0;
    }

    explicit Vector(int dim, T* coordinates);
    /// copy-constructor
    Vector(Vector<T> &arg) : mDim(arg.dim()), mCoordinates(arg.coordinates()) {}
    ~Vector();
    /// some operators
    Vector<T> operator+(const Vector<T> &arg) throw (DifferentDimensionException);
    Vector<T> operator-(const Vector<T> &arg) throw (DifferentDimensionException);
    Vector<T> operator*(const T &scalar);
    T operator*(const Vector<T> &arg) throw (DifferentDimensionException);
    bool operator==(const Vector<T> &arg);
    ///checks if vector is zero
    bool isZero() const;

private:
    int dim() const;
    T *coordinates() const;
    int mDim;
    T *mCoordinates;

};

template <typename T>
Vector<T>::Vector(int dim, T *coordinates) : mDim(dim)
{
    T *newCoordinates = new T[mDim];

    for (int i = 0; i < mDim; i++)
    {
        newCoordinates[i] = coordinates[i];
    }

    this->mCoordinates = newCoordinates;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->mCoordinates;
}

template <typename T>
bool Vector<T>::isZero() const
{
    bool allCoordinatesZero = true;

    for (int i = 0; i < mDim; i++)
        allCoordinatesZero = allCoordinatesZero && (mCoordinates[i] == 0);

    return allCoordinatesZero;
}

template <typename T>
T *Vector<T>::coordinates() const
{
    T *newCoordinates = new T[mDim];

    for (int i = 0; i < mDim; i++)
    {
        newCoordinates[i] = mCoordinates[i];
    }

    return newCoordinates;
}

template <typename T>
int Vector<T>::dim() const
{
    return mDim;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &arg) throw (DifferentDimensionException)
{
    if (mDim != arg.dim())
        throw DifferentDimensionException();

    T *resultCoordinates = new T[mDim];

    for (int i = 0; i < mDim; i++)
        resultCoordinates[i] = mCoordinates[i] + arg.coordinates()[i];

    Vector<T> result(mDim, resultCoordinates);
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &arg) throw (DifferentDimensionException)
{
    if (mDim != arg.dim())
        throw DifferentDimensionException();

    T *resultCoordinates = new T[mDim];

    for (int i = 0; i < mDim; i++)
        resultCoordinates[i] = mCoordinates[i] - arg.coordinates()[i];

    Vector<T> result(mDim, resultCoordinates);
    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T> &arg) throw (DifferentDimensionException)
{
    if (mDim != arg.dim())
        throw DifferentDimensionException();

    T result = 0;

    for (int i = 0; i < mDim; i++)
        result += mCoordinates[i] * arg.coordinates()[i];

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T &scalar)
{
    T *resultCoordinates = new T[mDim];

    for (int i = 0; i < mDim; i++)
        resultCoordinates[i] = mCoordinates[i] * scalar;

    Vector<T> result(mDim, resultCoordinates);
    return result;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &arg)
{
    if (mDim != arg.dim())
        return false;

    bool areEqual = true;

    for (int i = 0; i < mDim; i++)
        areEqual = areEqual && (mCoordinates[i] == arg.coordinates()[i]);

    return areEqual;
}
