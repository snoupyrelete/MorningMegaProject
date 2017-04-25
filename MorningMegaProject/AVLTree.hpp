//
//  AVLTree.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 4/19/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTreeNode.hpp"
#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);

    BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent, Type value);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
    int balance;
    int leftHeight = calculateHeight(node->getLeftChildPointer());
    int rightHeight = calculateHeight(node->getRightChildPointer());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChildPointer();
    
    parent->setLeftChildPointer(changedNode->getRightChildPointer());
    
    changedNode->setRightChildPointer(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChildPointer();
    
    parent->setRightChildPointer(changedNode->getLeftChildPointer());
    
    changedNode->setLeftChildPointer(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChildPointer();
    
    parent->setRightChildPointer(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChildPointer();
    
    parent->setLeftChildPointer(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent)
{
    int balanceFactor = heigthDifference(parent);
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftChildPointer()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}


template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template <class Type>
void AVLTree<Type> :: remove(Type value)
{
    delete this->getRoot();
}

template <class Type>
void AVLTree<Type> :: insert(Type value)
{
    insertNode(this->getRoot(), item);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: insertNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinarySearchTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getRightChild(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}
#endif /* AVLTree_hpp */
