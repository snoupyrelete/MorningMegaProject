//
//  StructureController.cpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include <iostream>
#include "StructureController.hpp"
#include <string>

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>();
    numberNode = Node<int>();
    numberArray = Array<int>(1);
    memeQueue = Queue<Meme>();
    stringGraph = Graph<string>();
    stringHashTable = HashTable<string>();
}

void StructureController :: testHashTable()
{
    stringHashTable.add("A");
    stringHashTable.add("B");
    stringHashTable.add("C");
    stringHashTable.add("D");
    stringHashTable.add("E");
    stringHashTable.add("F");
    stringHashTable.add("G");
    stringHashTable.add("H");
    stringHashTable.add("I");
    stringHashTable.add("J");
}

void StructureController :: testGraph()
{
    stringGraph.addVertex("Dylan");
    stringGraph.addVertex("Macie");
    stringGraph.addVertex("Maya");
    stringGraph.addVertex("Torri");
    stringGraph.addVertex("Kevin");
    
    // Kevin (dad)
    stringGraph.addEdge(4, 0);
    stringGraph.addEdge(4, 1);
    stringGraph.addEdge(4, 2);
    
    // Torri (mom)
    stringGraph.addEdge(3, 0);
    stringGraph.addEdge(3, 1);
    stringGraph.addEdge(3, 2);


    
    
    cout << "Depth First: " <<  endl;
    stringGraph.depthFirstTraversal(stringGraph, 0);

    cout << "Breadth First: " << endl;
    stringGraph.breadthFirstTraversal(stringGraph, 0);

    

}

void StructureController :: testArrayTemplate()
{
    cout << "Array Template" << endl;
    Timer arrayTimer;
    cout << "Finished template testing." << endl;
}

void StructureController :: testNodeTypes()
{


    
}

void StructureController :: testIntArray()
{
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(3);
    
    for(int spot = 0; spot < 3; spot++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
    
}

void StructureController :: start()
{
    //testArrayTemplate();
    //testAdvancedFeatures();
    //testListIntro();
//    testMemeQueue();
//    testNumberStack();
    //testBinarySearchTreeOperations();
    testGraph();
    testHashTable();
}

void StructureController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        //cout << "There should be messages about destructor next" << endl;
    }
    
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match: " << endl;
    cout << words.getFromIndex(0) << " should be the same as "
            << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    
    
}

void StructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << "Size should read 3: " << sample.getSize() << endl;
    }
    
    sample.setAtIndex(0, 3);
    
    cout << "This should be 3 @ index 0: " << sample.getFromIndex(0) <<endl;
    
    sample.remove(1);
    cout << "This should be 3 @ index 1: " << sample.getFromIndex(1) << endl;
}

//void StructureController :: testListTiming()
//{
//        DoubleList<int> timingList;
//        for(int index = 0; index < 10000; index++)
//        {
//                    timingList.add(rand());
//                }
//    
//    
//        long slowTime [1000];
//        long fastTime [1000];
//        double averageSlow = 0.00, averageFast = 0.00;
//    
//    
//        for(int index = 0; index < 1000; index++)
//            {
//                    int randomIndex = rand() % 10000;
//                    doubleTimer.startTimer();
//                    timingList.getFromIndex(randomIndex);
//                    doubleTimer.stopTimer();
//                    slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
//                    doubleTimer.resetTimer();
//            
//                    doubleTimer.startTimer();
//                    timingList.getFromIndexFast(randomIndex);
//                    doubleTimer.stopTimer();
//                    fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
//                    doubleTimer.resetTimer();
//            
//                    averageSlow += slowTime[index];
//                    averageFast += fastTime[index];
//            
//                }

void StructureController :: testMemeQueue()
{
    cout << "!!! START!!!:  testMemeQueue()" << endl;
    Queue<Meme> memeQueue;
    
    Meme firstMeme("toddler fist with pinwheel!");
    Meme secondMeme;
    Meme thirdMeme;
    secondMeme.setDankness(8435);
    thirdMeme.setHipsterQuotient(2.893);
    
    memeQueue.add(firstMeme);
    memeQueue.enqueue(secondMeme);
    
    cout << "EXPECTED SIZE: 2 ACTUAL:  " << memeQueue.getSize() <<endl;
    
    //Meme temp = memeQueue.dequeue();
    cout << "EXPECTED PEEK RESULT: toddler fist.... IS: " << memeQueue.peek().getTitle() << endl;

    Meme toDequeue = memeQueue.dequeue();
    
    cout << "EXPECTED RESULT OF DEQUEUE: SIZE=1 IS: " << memeQueue.getSize() << endl;
    cout << "EXPECTED RESULT OF DEQUEUE: title=toddler first  IS: " << toDequeue.getTitle() << endl;
    
    Meme toRemove = memeQueue.remove(0);
    
    cout << "EXPECTED RESULT OF REMOVE: SIZE=0 IS: " << memeQueue.getSize() << endl;
    cout << "EXPECTED RESULT OF REMOVE: title=normie...  IS: " << toRemove.getTitle() << endl;

    cout << "!!! END !!!:  testMemeQueue()" << endl;
}

void StructureController :: testNumberStack()
{
    cout << "!!! START!!!:  testNumberStack()" << endl;
    Stack<int> numberStack;
    
    numberStack.push(1);
    int first = numberStack.peek();
    cout << "EXPECTED PEEK: 1 ACTUAL: " << first << endl;
    numberStack.add(2);
    cout << "EXPECTED SIZE AFTER ADD: 2, ACTUAL: " << numberStack.getSize() << endl;

    cout << "EXPECTED VAL OF POP: 2 ACTUAL: " << numberStack.pop() << endl;
    cout << "EXPECTED VAL OF REMOVE: 1 ACTUAL: " << numberStack.remove(0) << endl;

    cout << "!!! END !!!:  testNumberStack()" << endl;
}



//void StructureController :: testBinarySearchTreeOperations()
//{
//    
//    //BinarySearchTree<int> numbers;
//    
//    numbers.insert(9843);
//    
//    numbers.insert(10);
//    
//    numbers.insert(43);
//    
//    numbers.insert(-123);
//    
//    numbers.insert(23465);
//    
//    numbers.insert(10); // won't go in
//    
//    numbers.insert(43243);
//    
//    numbers.insert(-45677654);
//    
//    numbers.insert(92165);
//    
//    
//    
//    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
//    
//    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
//    
//    numbers.inOrderTraversal();
//    
//    
//    
//    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
//    
//    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
//    
//}

//void StructureController :: testBinarySearchData()
//
//{
//    
//    FileController fileData;
//    
//    Timer treeTimer;
//    
//    treeTimer.startTimer();
//    
//    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/cody.henrichsen/Documents/crimes.csv");
//    
//    treeTimer.stopTimer();
//    
//    
//    
//    int count = crimeTree.getSize();
//    
//    int height = crimeTree.getHeight();
//    
//    bool complete = crimeTree.isComplete();
//    
//    bool balanced = crimeTree.isBalanced();
//    
//    
//    
//    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
//    
//    cout << "The time to read in the tree was: " << endl;
//    
//    treeTimer.displayTimerInformation();
//}
//
//void StructureController :: testAVLTreeOperations()
//
//{
//    
//    AVLTree<int> numbers;
//    
//    numbers.insert(9843);
//    
//    numbers.insert(10);
//    
//    numbers.insert(43);
//    
//    numbers.insert(-123);
//    
//    numbers.insert(23465);
//    
//    numbers.insert(10); // won't go in
//    
//    numbers.insert(43243);
//    
//    numbers.insert(-45677654);
//    
//    numbers.insert(92165);
//    
//    
//    
//    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
//    
//    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
//    
//    numbers.inOrderTraversal();
//    
//    
//    
//    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
//    
//    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
//    
//}
//
//void StructureController :: testAVLData()
//
//{
//    
//    FileController fileData;
//    
//    Timer treeTimer;
//    
//    treeTimer.startTimer();
//    
//    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");
//    
//    treeTimer.stopTimer();
//    
//    
//    
//    int count = crimeTree.getSize();
//    
//    int height = crimeTree.getHeight();
//    
//    bool complete = crimeTree.isComplete();
//    
//    bool balanced = crimeTree.isBalanced();
//    
//    
//    
//    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
//    
//    cout << "The time to read in the tree was: " << endl;
//    
//    treeTimer.displayTimerInformation();
//    
//}
