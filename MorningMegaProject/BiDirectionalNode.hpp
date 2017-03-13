//
//  BiDirectionalNode.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/27/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BiDirectionalNode_hpp
#define BiDirectionalNode_hpp
#include "Node.hpp"

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
// Type data;
    BiDirectionalNode<Type> * previousPointer;
    BiDirectionalNode<Type> * nextPointer;
public:
    BiDirectionalNode<Type>();
    BiDirectionalNode<Type>(Type data);
    BiDirectionalNode<Type>(Type data, BiDirectionalNode<Type> * prev, BiDirectionalNode<Type> * next);

  //  Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
  //  void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * prev);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
    this->nextPointer = nullptr;
    this->previousPointer = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node<Type>(data)
{
    this->nextPointer = nullptr;
    this->previousPointer = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node<Type>(data, next)
{
    this->previousPointer = previous;
    this->nextPointer = next;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer()
{
    return this->nextPointer;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer()
{
    return this->previousPointer;
}

template <class Type>
void BiDirectionalNode<Type> :: setNextPointer(BiDirectionalNode<Type> * next)
{
    this->nextPointer = next;
}

template <class Type>
void BiDirectionalNode<Type> :: setPreviousPointer(BiDirectionalNode<Type> * previous)
{
    this->previousPointer = previous;
}




#endif /* BiDirectionalNode_hpp */
