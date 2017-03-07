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
    void add(Type data);
    Type peek();
    Type dequeue();
    Type remove(int index);
    Type enqueue();
    
};



template <class Type>
Type Queue<Type> :: enqueue()
{
    
}

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
