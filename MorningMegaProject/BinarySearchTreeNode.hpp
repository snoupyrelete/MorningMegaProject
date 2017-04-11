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
    BinarySearchTreeNode(Type data)
    
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChildPointer();
    BinarySearchTreeNode<Type> * getRightChildPointer();
    
    void setRootPointer(BinarySearchTreeNoce<Type> * root);
    void setLeftChildPointer(BinarySearchTreeNoce<Type> * left);
    void setRightChildPointer(BinarySearchTreeNoce<Type> * right);
};

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
void BinarySearchTreeNode<Type> :: setLeftChildPointed(BinarySearchTreeNode<Type> * left)
{
    this->leftChild = left;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * right)
{
    this->rightChild = right;
}
#endif /* BinarySearchTreeNode_hpp */
