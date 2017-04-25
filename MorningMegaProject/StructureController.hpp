//
//  StructureController.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "Array.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "Meme.hpp"
#include "Queue.hpp"
#include "IntNodeArray.hpp"
#include "Stack.hpp"
#include "Timer.hpp"
#include "BinarySearchTree.hpp"
#include <string>
#include "CrimeData.hpp"
#include "AvlTree.hpp"
#include "FileController.hpp"

class StructureController
{
private:
    Node<int> numberNode;
    Node<std::string> wordNode;
    Array<int> numberArray;
    Queue<Meme> memeQueue;
    Stack<int> numberStack;
    
    
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();
    void testListIntro();
    void testListTiming();
    
    void testMemeQueue();
    void testNumberStack();
    void testBinarySearchTreeOperations();
    void testBinarySearchData();
    void testAVLTreeOperations();
    void testAVLData();
public:
    StructureController();
    void start();
};

#endif /* StructureController_hpp */
