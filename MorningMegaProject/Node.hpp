//
//  Node.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData();
    Node<Type> * getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type> * nextPointer);
    
};

// Implementation of the template class

template <class Type>
Node<Type> :: Node()
{
    nextPointer = nullptr;
    
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data, Node<Type> * nextNode)
{
    this->nodeData= data;
    this->nextPointer = nextNode;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
void Node<Type> :: setNodeData(Type nodeData)
{
    this->nodeData = nodeData;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type> * next)
{
    this->nextPointer = next;
}

template <class Type>
Node<Type> * Node<Type> :: getNextPointer()
{
    return nextPointer;
}










#endif /* Node_hpp */
