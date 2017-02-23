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
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    bool contains(Type data);
    int getSize() const;
    Node<Type> * getFront() const;
};

/*------------
IMPLEMENTATION
------------*/

template <class Type>
List<Type> :: List()
{
    
}




#endif /* List_hpp */
