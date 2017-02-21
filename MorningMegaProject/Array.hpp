//
//  Array.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp
#include <assert.h>
#include "Node.hpp"


template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
public:
    // Constructors
    Array<Type>();
    Array<Type>(int size);
    
    // Destructor
    ~Array<Type>();
    // Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    
    
    
    
    
    
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};

template <class Type>
Array<Type> :: Array()
{
    // Do not use!
    // Implemented only for compilation
}

/*
 Creates an Array of specified size by linking Node<Type> together.
 */
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;

    this->front = new Node<Type>();
    
    for(int index = 1; index < size; index++)
    {
        Node<Type> * currentNode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

template <class Type>
int Array<Type> :: getSize()
{
    return size;
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
}


#endif /* Array_hpp */
