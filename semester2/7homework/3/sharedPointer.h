#pragma once

/// smart pointer with counting of references
template<typename T>
class SharedPtr
{
public:
    SharedPtr() : mPtrData(nullptr, 0) {}
    SharedPtr(T *object) : mPtrData(new PtrData(object, 1)) {}
    /// copy constructor
    SharedPtr(SharedPtr<T> const &ptr) : mPtrData(ptr.mPtrData)
    {
        mPtrData->mRefCount++;
    }

    ~SharedPtr()
    {
        deletePtr();
    }

    /// two fuctions for better testing
    T *object()
    {
        return mPtrData->mObject;
    }

    int refCount()
    {
        return mPtrData->mRefCount;
    }

    /// operator =
    SharedPtr<T> &operator=(SharedPtr<T> const &ptr);

private:
    void deletePtr();
    /// this structure is needed to change at once all the pointers with same object
    struct PtrData
    {
    public:
        T *mObject;
        int mRefCount;

        PtrData(T *mObject, int mRefCount) : mObject(mObject), mRefCount(mRefCount) {}
        ~PtrData()
        {
            delete mObject;
        }
    };

    PtrData *mPtrData;
};

template<typename T>
void SharedPtr<T>::deletePtr()
{
    mPtrData->mRefCount--;
    if (mPtrData->mRefCount == 0)
        delete mPtrData;
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> const &ptr)
{
    deletePtr();

    if (mPtrData != ptr.mPtrData)
    {
        mPtrData = ptr.mPtrData;
        mPtrData->mRefCount++;
    }
    return *this;
}
