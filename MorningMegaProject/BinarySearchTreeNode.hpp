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
    void setLeftChildPointer(BinarySearchTreeNoce<Type> * root);
    void setRightChildPointer(BinarySearchTreeNoce<Type> * root);
};

#endif /* BinarySearchTreeNode_hpp */
