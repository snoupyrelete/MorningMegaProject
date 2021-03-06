//
//  BinarySearchTree.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include "BinarySearchTreeNode.hpp"
#include <iostream>
#include <algorithm>

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    int calculateHeight(BinarySearchTreeNode<Type> * root);
    bool isBalanced(BinarySearchTreeNode<Type> * root);
    bool isComplete(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    BinarySearchTreeNode<Type> * getRightMostChild(BinarySearchTreeNode<Type> * current);
    BinarySearchTreeNode<Type> * getLeftMostChild(BinarySearchTreeNode<Type> * current);

    
    void removeNode(BinarySearchTreeNode<Type> * removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    Type findMinimum();
    Type findMaximum();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    int getSize();
    int getHeight();
    bool isBalanced();
    bool isComplete(BinarySearchTreeNode<Type> * start, int index, int size);
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    delete root;
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type> :: getRoot()
{
    return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

/*
 TREE TRAVERSALS:
 
 (a) Inorder (Left, Root, Right) : 4 2 5 1 3
 (b) Preorder (Root, Left, Right) : 1 2 4 5 3
 (c) Postorder (Left, Right, Root) : 4 5 2 3 1
 
        1
       / \
      2   3
     / \
    4   5
 
*/

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(root);
}

/*
 Complete => fiiled in fully from the left
 Balanced => heights are within 1 of eachother, and both sides are balanced
*/

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinarySearchTreeNode<Type> * start)
{
    int index = 0;
    int size = getSize();
    
    return isComplete(root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinarySearchTreeNode<Type> * start)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(start == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(start->getLeftChildPointer());
    rightHeight = calculateHeight(start->getRightChildPointer());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(start->getLeftChildPointer());
    bool rightBalanced = isBalanced(start->getRightChildPointer());
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinarySearchTreeNode<Type> * start)
{
    if(start == nullptr)
    {
        return 0;
    }
    // Returns the bigger (max) of the two parameters
    else
    {
        return 1 + max(calculateHeight(start->getLeftChildPointer()), calculateHeight(start->getRightChildPointer()));
    }
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    int count = 1;
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        count += calculateSize(start->getLeftChildPointer());
        count += calculateSize(start->getRightChildPointer());
        return count;
    }
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeftChildPointer());
        cout << "Node Contents: " << inStart->getNodeData() << endl;
        inOrderTraversal(inStart->getRightChildPointer());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
        cout << "Node Contents: " << preStart->getNodeData() << endl;
        preOrderTraversal(preStart->getLeftChildPointer());
        preOrderTraversal(preStart->getRightChildPointer());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeftChildPointer());
        postOrderTraversal(postStart->getRightChildPointer());
        cout << "Node Contents: " << postStart->getNodeData() << endl;
    }
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinarySearchTreeNode<Type> * current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getLeftChild() != nullptr)
    {
        temp = temp->getLeftChild();
    }
    return temp;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinarySearchTreeNode<Type> * current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getRightChild() != nullptr)
    {
        temp = temp->getRightChild();
    }
    return temp;
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * smallest = getLeftMostChild(root);
    return smallest->getNodeData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * largest = getRightMostChild(root);
    return largest->getNodeData();
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChildPointer();
            }
            else if(itemToInsert > current->getNodeData())
            {
                current = current->getRightChildPointer();
            }
            else
            {
                cerr << "Item exists already - Exiting" << endl;
                delete insertMe;
                return;
            }
        }
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChildPointer(insertMe);
        }
        else
        {
            previous->setRightChildPointer(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getNodeData())
            {
                return true;
            }
            else if(itemToFind < current->getNodeData())
            {
                current = current->getLeftChildPointer();
            }
            else
            {
                current = current->getRightChildPointer();
            }
        }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinarySearchTreeNode<Type> * current = root;
        BinarySearchTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getNodeData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getNodeData())
                {
                    current = current->getLeftChildPointer();
                }
                else
                {
                    current = current->getRightChildPointer();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == root)
            {
                removeNode(root);
            }
            else if(getRidOfMe < previous->getNodeData())
            {
                removeNode(previous->getLeftChildPointer());
            }
            else
            {
                removeNode(previous->getRightChildPointer());
            }
        }
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinarySearchTreeNode<Type> * removeMe)
{
    BinarySearchTreeNode<Type> * current;
    BinarySearchTreeNode<Type> * previous;
    BinarySearchTreeNode<Type> * temp;
    
    previous = removeMe->getRootPointer();
    
    if(removeMe->getRightChildPointer() == nullptr && removeMe->getLeftChildPointer() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(removeMe->getRightChildPointer() == nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChildPointer(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
        {
            previous->setRightChildPointer(removeMe);
        }
        delete temp;
    }
    else if(removeMe->getRightChildPointer() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChildPointer();
        
        if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChildPointer(removeMe);
        }
        
        removeMe->setRootPointer(previous);
        delete temp;
    }
    else if(removeMe->getLeftChildPointer() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightChildPointer();
        
        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChildPointer(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
        {
            previous->setRightChildPointer(removeMe);
        }
        removeMe->setRootPointer(previous);
        delete temp;
    }
    else
    {
        current = removeMe->getLeftChildPointer();
        previous = nullptr;
        
        while(current->getRightChildPointer() != nullptr)
        {
            previous = current;
            current = current->getRightChildPointer();
        }
        
        removeMe->setNodeData(current->getNodeData());
        
        if(previous == nullptr)
        {
            removeMe->setLeftChildPointer(current->getLeftChildPointer());
            current->getLeftChildPointer()->setRootPointer(removeMe);
        }
        else
        {
            previous->setRightChildPointer(current->getLeftChildPointer());
            current->getLeftChildPointer()->setRootPointer(previous);
        }
        
        delete current;
    }
    
    if(removeMe == nullptr || removeMe->getRootPointer() == nullptr)
    {
        setRoot(removeMe);
    }
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return calculateSize(root);
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(root);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(root);
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinarySearchTreeNode<Type> * start, int index, int size)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(start == nullptr)
    {
        return true;
    }
    
    if(index >= size)
    {
        return false;
    }
    
    return isComplete(start->getLeftChildPointer(), 2 * index + 1,size) && isComplete(start->getRightChildPointer(), 2 * index + 2, size);
}

#endif /* BinarySearchTree_hpp */
