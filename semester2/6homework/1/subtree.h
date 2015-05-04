#pragma once

/// virtual class for subtree, because it can be operation betwee two subtree or just number
class Subtree
{
public:
    virtual ~Subtree() {}
    /// counts subtree, used in same function in mathtree
    virtual int count() = 0;
    /// prints subtree, used in same function in mathtree
    virtual void print() = 0;
};
