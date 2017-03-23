//
//  DoubleList.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef DoubleList_hpp
#define DoubleList_hpp

#include "DoublyLinkedList.hpp"

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
};
#endif /* DoubleList_hpp */

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    
}
/*
 You add a node and set the current end's next pointeer to the added node,
 then you set the added's previous to the old end,
 then you point the end pointer to the node you added - which is now set as the end
 then you increase size++
*/
template <class Type>
void DubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
    }
    else
    {
        // Sets the ends next pointer to added
        // Then sets added's previous pointer to the old end
        this->getEnd()->setNextPointer(addedNode);
        addedNode->setPreviousPointer(this->getEnd());
    }
    // Then makes the added the new end!
    this->setEnd(addeddNode);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    for(int spot = 0; spot < index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp = nodeToTakeOut->getNodeData();
    
    BiDirectionalNode<Type> * prev = nodeToTakeOut->getPrevious();
    BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();
    
    // Reconnect these by setting their next/prev to what was nodeToTakeOut's next/prev - fill the gap
    prev->setNextPointer(next);
    next->setPreviousPointer(previous);
    
    delete nodeToTakeOut;
    
    this->setSize(this->getSize() - 1);
    return derp;
}

template <class Type>
Type Double<Type> :: getFromImdexFast(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
        else
        {
            reference = this->getEnd();
            for(int position = this->getsize() - 1; position > index; position--)
            {
                reference = refeerence->getPreviousPointer();
            }
        }
        
    }
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}

