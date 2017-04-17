//
//  BinarySearchTreeNode.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BinarySearchTreeNode_hpp
#define BinarySearchTreeNode_hpp

#include "Node.hpp"

template <class Type>
class BinarySearchTreeNode : public Node<Type> {
private:
    BinarySearchTreeNode<Type> * root;
    BinarySearchTreeNode<Type> * leftChild;
    BinarySearchTreeNode<Type> * rightChild;
    

public:
    BinarySearchTreeNode<Type>();
    BinarySearchTreeNode(Type data);
    ~BinarySearchTreeNode();
    
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChildPointer();
    BinarySearchTreeNode<Type> * getRightChildPointer();
    
    void setRootPointer(BinarySearchTreeNode<Type> * root);
    void setLeftChildPointer(::BinarySearchTreeNode<Type> * left);
    void setRightChildPointer(BinarySearchTreeNode<Type> * right);
};

template <class Type>
BinarySearchTreeNode<Type> :: ~BinarySearchTreeNode()
{
    delete leftChild;
    delete rightChild;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode()
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode(Type data) : Node<Type>(data)
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRootPointer()
{
    return this->root;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getLeftChildPointer()
{
    return this->leftChild;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRightChildPointer()
{
    return this->rightChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setLeftChildPointer(BinarySearchTreeNode<Type> * left)
{
    this->leftChild = left;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRightChildPointer(BinarySearchTreeNode<Type> * right)
{
    this->rightChild = right;
}
#endif /* BinarySearchTreeNode_hpp */
