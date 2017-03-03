//
//  Stack.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:
public:
    Stack();
    ~Stack();
    void add(Type data);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
};

/*
Add method only adds to the end on a stack. Never at an index 
*/
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}

/* 
Push adds the supplied object to the end of the stack.
Set new object to point to end
Increases the size by 1.
Adjusts the end pointer to reflect the new end of the stack.

*/
template <class Type>
void Stack<Type> :: push(Type valueToPush)
{
    BiDirectionalNode<Type> * newNode = new BiDirectionalNode(valueToPush);
    if(this->size == 0 || this->front == nullptr || this->end == nullptr)
    {
        this->front = newNode;
    }
    else
    {
        this->end->setNextPointer(newNode);
        newNode->setPreviousPointer(this->end);
    }

    this->end = newNode;
    this->size++;
}

#endif /* Stack_hpp */
