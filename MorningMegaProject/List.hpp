//
//  List.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/21/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <assert.h>
#include "Node.hpp"
#include <iostream>

/*----
HEADER
----*/

template <class Type>
class List
{
private:
    Node<Type> * front;
    Node<Type> * end;
    int size;
public:
    // Constructors
    List<Type>();
    
    // Destructor
    ~List<Type>();
    
    // Copy Constructor
    List<Type>(const List<Type> & source);
    
    // Methods
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    void addEnd(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    bool contains(Type data);
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
};

/*------------
IMPLEMENTATION
------------*/

template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}

template <class Type>
List<Type> :: ~List()
{
    Node<Type> * destruction = front;
    while (front != nullptr)
    {
        front = front->getNodePointer();
        delete destruction;
        destruction = front;
    }
}

template <class Type>
int List<Type> :: getSize() const
{
    return this->size;
}

template<class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if (index == size)
    {
        addEnd(value);
    }
    else if (index == 0)
    {
        addFront(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for (int position = 0; position < index; position++)
        {
            // Keep track of previous to link previous to current and then current to next
            previous = current;
            // Gets the pointer to the node next of current.
            current = current->getNodePointer();
        }
        
        previous->setNodePointer(insertedNode);
        insertedNode->setNodePointer(current);
        
        size++;
    }
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    return value;
}

template <class Type>
Type List<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Type removedData;
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
    
    return removedData;
}

template <class Type>
void List<Type> :: addFront(Type value)
{
    if (size == 0)
    {
        // DEFAULT CASE - have to set the single node to both front & end pointers.
        Node<Type> * first = new Node<Type>(value);
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node<Type>(value);
        newFirst->setNodeData(value);
        
        // Set the new Node to point to the previously first Node
        newFirst->setNodePointer(front);
        
        // Could use this instead?...
        // Node<Type> * newFirst = new Node<Type>(value, front);
        
        // Point the front to the new front.
        this->front = newFirst;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addEnd(Type value)
{
    Node<Type> * added = new Node<Type>(value);
    if (size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        // Set the end to point to the next node
        end->setNodePointer(added);
        // Set the end pointer to point at the new end
        this->end = added;
    }
    size++;
}

template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    if (index == 0)
    {
        toBeRemoved = front;
        front = front->getNodePointer();
        
    }
    else if(index == size -1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        previous->setNodePointer(nullptr);
        end = previous;

    }
    else
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNodePointer();
        previous->setNodePointer(current);
    }
    
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    
    size--;
    return removed;
}



#endif /* List_hpp */
