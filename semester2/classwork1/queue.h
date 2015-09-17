#pragma once
#include <algorithm>

template<typename T>
class Queue
{
public:
    Queue()  : head(nullptr) {}
    ~Queue();
    /// adds value to the queue with priority
    /// priority function needs to be positive
    void enqueue(T value, std::function<int(T)> priority);
    /// removes the most priority value
    T dequeue(std::function<int(T)> priority);

private:
    ///queue with pointers
    class QueueElement
    {
    public:
        QueueElement(T value, QueueElement *next) : value(value), next(next) {}
        ~QueueElement() {}
        T value;
        QueueElement *next;
    };

    QueueElement *head;

    void recursiveAdd(T value, std::function<int(T)> priority, QueueElement *element);
};

template<typename T>
Queue<T>::~Queue()
{
    QueueElement *element = head;

    while(element != nullptr)
    {
        QueueElement *nextElement = element->next;
        delete element;
        element = nextElement;
    }
}

template<typename T>
void Queue<T>::recursiveAdd(T value, std::function<int(T)> priority, QueueElement *element)
{
    if (element->next == nullptr || priority(value) > priority(element->value))
    {
        element->next = new QueueElement(value, element->next);
        return;
    }
    recursiveAdd(value, priority, element->next);
}


template<typename T>
void Queue<T>::enqueue(T value, std::function<int(T)> priority)
{
    if (head == nullptr)
    {
        head = new QueueElement(value, nullptr);
        return;
    }
    if (priority(value) > priority(head->value))
    {
        head = new QueueElement(value, head);
        return;
    }
    recursiveAdd(value, priority, head);
}

template<typename T>
T Queue<T>::dequeue(std::function<int(T)> priority)
{
    QueueElement *element = head;
    int maxPriority = 0;
    T value;

    while(element != nullptr)
    {
        if (maxPriority < priority(element->value))
            maxPriority = priority(element->value);
        element = element->next;
    }

    if (priority(head->value) == maxPriority)
    {
        value = head->value;
        head = head->next;
        return value;
    }

    QueueElement *currentElement = head;
    while (currentElement->next != nullptr)
    {
        if (priority(currentElement->value) == maxPriority)
        {
            value = currentElement->value;
            QueueElement *element = currentElement->next->next;
            delete currentElement->next;
            currentElement->next = element;
            break;
        }
        currentElement = currentElement->next;
    }
    return value;
}

