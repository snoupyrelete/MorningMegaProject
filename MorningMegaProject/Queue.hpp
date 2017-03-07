//
//  Queue.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "DoublyLinkedList.hpp"

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
private:
public:
    Queue();
    ~Queue(0);
    void add(Type data);
    Type remove(int index);
    Type peek();
    Type dequeue();
    void enqueue(Type data);
};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{
    
}

/*
 Same destructor as list, array, stack, etc. since it's a linear data structure.
 */
template <class Type>
Queue<Type> :: ~Queue()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

/*
 Call the enqueue method
 Method implemented to ensure the
 child class is NOT abstract.
 (Have to implement all virtual methods)
 */
template <class Type>
Type Queue<Type> :: add(Type value)
{
    enqueue(value);
}

/*
 1. Create a new Node pointer.
 2. If size == 0, adjust front to point to new node
 3. Else, set new node to ends next, and connect node's previous to end
 4. Move end to new node
 5. Adjust size
 */
template <class Type>
Type Queue<Type> :: enqueue(Type instertedValue)
{
    BiDirectionalNode<Type> * added = new BiDirectionalNode<Type>();
    
    if(this->getSize() == 0 || this->getfront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this->getEnd()->setNextPointer(added);
        added->setPreviousPointer(this->getEnd());
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}

/*
 Call the dequeue method
 Method implemented to ensure the
 child class is NOT abstract.
 (Have to implement all virtual methods)
 */
template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index  == 0 && this->getSize() > 0)
    return dequeue();
}

/*
 1. Assert size is valid
 2. Get data from front node
 3. If size == 1, set end to nullptr
 4. Else, move front to front's next
 4a. Set front's previous to nullptr
 5. Delete old front node
 6. Adjust size --
 7. Return old value that was dequeued
 */
template <class Type>
Type Queue<Type> :: dequeue()
{
    // 1
    assert(this->getSize() > 0);
    // 2
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<Type> * removeMe = this->getFront();
    // 3
    if(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    // 4
    else
    {
        this->setFront(removeMe->getNextPointer());
    }
    this->setFront()->setPreviousPointer(nullptr);
    // 5
    delete removeMe;
    //6
    this->setSize(this->getSize() - 1);
    // 7
    return removedValue;
}

/*
 1. Check that size is greather than 0
 2. Return the front object's data
 */
template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->getSize() > 0);
    
    return this->getFront()->getNodeData();
}


#endif /* Queue_hpp */
