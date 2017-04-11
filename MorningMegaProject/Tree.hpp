//
//  Tree.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <assert.h>
template <class Type>
class Tree
{
private:
    int height;
    int size;
    bool complete;
    bool balanced;
public:
    Tree();
    virtual ~Tree();
    virtual void printToFile() = 0;
    virtual void inOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    
    int getHeight() const;
    int getSize() const;
    bool isComplete() const;
    bool isBalanced() const;
    
    void setHeight(int height);
    void setSize(int size);
    void setComplete(bool complete);
    void setBalanced(bool balanced);
};

template <class Type>
Tree<Type> :: Tree()
{
    height = 0;
    size = 0;
    balanced = false;
    complete = false;
}

template <class Type>
int Tree<Type> :: getHeight() const
{
    return this->height;
}

template <class Type>
int Tree<Type> :: getSize() const
{
    return this->size;
}

template <class Type>
bool Tree<Type> :: isComplete() const
{
    return this->complete;
}

template <class Type>
bool Tree<Type> :: isBalaceed() const
{
    return this->balanced;
}

template <class Type>
void Tree<Type> :: setHeight(int height)
{
    this->height = height;
}

template <class Type>
void Tree<Type> :: setSize(int size)
{
    this->size = size;
}

template <class Type>
void Tree<Type> :: setComplete(bool complete)
{
    this->complete = complete;
}

template <class Type>
void Tree<Type> :: setBalanced(bool balanced)
{
    this->balanced = balanced;
}

#endif /* Tree_hpp */
