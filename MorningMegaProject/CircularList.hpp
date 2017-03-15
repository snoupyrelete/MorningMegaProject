//
//  CircularList.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.

#ifndef CircularList_hpp
#define CircularList_hpp

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    BiDirectionalNode<Type> * findNode(int index);
public:
    CircularList();
    ~CircularList();
    void add(Type data);
    Type emove(int index);
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
};

// CircularList just calls the constructor of DoublyLinkedList
template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
CircularList<Type> :: ~CircularList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

template <class Type>
BiDirectionalNode<Type> * CircularList<Type> :: findNode(int index)
{
    BiDirectionalNode<Type> * nodeToFind;
    if(index < this->getSize() /2)
    {
        nodeToFind  = this->getFront();
        for(int spot = 0; spot < index; spot++)
        {
            nodeToFind = removed->getNextPointer();
        }
    }
    else
    {
        removed = this->getEnd();
        for(int spot = this->getSize() - 1; spot < index; spot--)
        {
            nodeToFind = removed->getPreviousPointer();
        }
    }
    return nodeToFind;
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    BiDirectionalNode<Type> * addMe = new BiDirectionalNode<Type>(data);
    
    if(this->getSize() == 0)
    {
        this->setFront(addMe);
        this->setEnd(addMe);
        addMe->setPreviousPointer(this->getFront());
        this->getFront->setNextPointer(this->getEnd());
    }
    else
    {
        this->getEnd()->setNextPointer(addMe);
        addMe->setPreviousPointer(this->getEnd());
        addMe->setNextPointer(this->getFront());
        this->getFront()->setPreviousPointer(addMe);
        this->setEnd(addMe);
    }
}

template <class Typee>
Type CircularList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->getSize());
    
    Type removedValue;
    
    BiDirectionalNode<Type> * removed = findNode(index);
    
    removedValue = removed->getNodeData();
    
    BiDirectionalNodeType * oldPrevious = removed->getPreviousPointer();
    BiDirectionalNodeType * oldNext = removed->getNextPointer();
    
    if(this->getSize() > 1)
    {
        oldPrevious->setNextPointer(oldNext);
        oldNext->setPreviousPointer(oldPrevious);
    
        //ADJUST FRONT & END IF NEEDED
        if(index == 0)
        {
            this->setFront(getFront()->getNextPointer());
        }
        else if(index == this->getSize() -1)
        {
            this->setEnd(getEnd()->getPreviousPointer());
        }
        
    }
    else
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    
    delete removed;
    this->setSize(this->getSize() -1);
}

template <class Type>
Type CircularList<Type> :: getFromIndex(int index)
{
    assert >= 0 && index < this->getSize());
    
    Type retreieved;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    retreieved = current->getNodeData();
    return retreieved;
}

template <class Type>
Type CircularList<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < this->getSize());
    Type replaced;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    replaced = current->getNodeData();
    current->setNodeData(data)
    
    return replaced;
}


#endif /* CircularList_hpp */
