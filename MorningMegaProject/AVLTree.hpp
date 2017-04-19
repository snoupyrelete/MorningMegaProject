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
    BinarySearchTree<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTree<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTree<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTree<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);

    BinarySearchTree<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTree<Type> * insertNode(BinarySearchTreeNode<Type> * parent);
    BinarySearchTree<Type> * removeNode(BinarySearchTreeNode<Type> * parent);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

#endif /* AVLTree_hpp */
