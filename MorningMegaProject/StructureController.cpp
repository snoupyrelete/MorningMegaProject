//
//  StructureController.cpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "IntNodeArray.hpp"
#include "StructureController.hpp"
#include "Timer.hpp"
#include <iostream>

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>();
    numberNode = Node<int>();
    numberArray = Array<int>(1);
}

void StructureController :: testArrayTemplate()
{
    cout << "Array Template" << endl;
    Timer arrayTimer;
    
    arrayTimer.startTimer();
    //int test [9];
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    arrayTimer.resetTimer();
    
    arrayTimer.startTimer();
    numberArray = Array<int>(9);
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    arrayTimer.resetTimer();
    
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
    testListIntro();
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

