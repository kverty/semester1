#pragma once

/// smart pointer with counting of references
template<typename T>
class SharedPtr
{
public:
    SharedPtr() : mPtrData(nullptr, 0) {}
    SharedPtr(T *object) : mPtrData(new PtrData(object, 1)) {}
    /// copy constructor
    SharedPtr(SharedPtr<T> &ptr) : mPtrData(ptr.mPtrData)
    {
        mPtrData->mRefCount++;
    }

    ~SharedPtr()
    {
        mPtrData->mRefCount--;
        if (mPtrData->mRefCount == 0)
            delete mPtrData;
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
    SharedPtr<T> operator=(SharedPtr<T> &ptr)
    {
        mPtrData->mRefCount--;
        if (mPtrData->mRefCount == 0)
            delete mPtrData;

        if (mPtrData != ptr.mPtrData)
        {
            mPtrData = ptr.mPtrData;
            mPtrData->mRefCount++;
        }
        return *this;
    }

private:
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
