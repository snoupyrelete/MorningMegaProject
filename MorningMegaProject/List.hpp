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
        
        // Node<Type> * newFirst = new Node<Type>(value, front);
        
        // Point the front to the new front.
        front = newFirst;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addFront(Type value)
{
    
}



#endif /* List_hpp */
