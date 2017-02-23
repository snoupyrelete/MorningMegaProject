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
        insertedNode->setNodePointer(current)l
        
        size++;
    }
}


template <class Type>
void List<Type> :: addFront(Type value)
{
    if (size == 0)
    {
        // DEFAULT CASE - have to set the single node to both front & end pointers.
        Node<Type> * first = new Node(value)
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node(value)
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
    Node<Type> * added = new Node<Type>(data);
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



#endif /* List_hpp */
