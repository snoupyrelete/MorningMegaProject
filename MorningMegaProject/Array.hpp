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
#include <iostream>

/*----
HEADER
----*/

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
    
    // Methods
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};


/*------------
IMPLEMENTATION
------------*/

using namespace std;

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
int Array<Type> :: getSize() const
{
    return size;
}

/*
    Get the value from the specified index.
*/
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

/*
    Set a value at a given index.
*/
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

/*
    The const modifier at the end of the method is used to denote that the method does 
    not impact the state of the object.
*/
template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
    return front;
}


template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        // Move to next node in array
        front = front->getNodePointer();
        cout << "Moving to the next node at: " << count << endl;
        // Delete the front pointer
        delete remove;
        cout << "Deleting the old front pointer." << endl;
        // Move delete to the new front.
        remove = front;
        cout << "Moving to new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    // Build data structure
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNodePointer(front);
        front = temp;
    }
    
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNodePointer();
        copyTemp = copyTemp->getNodePointer();
    }
}

#endif /* Array_hpp */
