#pragma once

///this type is to make comparison more undertandable
enum Comp
{
    smaller = -1,
    equall,
    bigger
};

/// objects that can be compared with general field - size
class ComparableWithSize
{
public:
    ComparableWithSize();
    virtual ~ComparableWithSize() {}
    /// how to compare
    int compareTo(ComparableWithSize *list);
    /// i have print-method in SortedSet, so ComparableWithSize objects need to be printable
    virtual void print() = 0;

protected:
    /// general field
    int size;
};
