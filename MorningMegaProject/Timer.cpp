//
//  Timer.cpp
//  CPPProject
//
//  Created by Robson, Dylan on 1/31/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "Timer.hpp"
#include <iostream>

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer :: resetTimer()
{
    executionTime = 0;
}

void Timer :: startTimer()
{
    executionTime = clock();
}

void Timer :: stopTimer()
{
    executionTime = clock() - executionTime;
}

void Timer :: displayTimerInformation()
{
    cout << "The execution time is: " << executionTime << endl;
    cout << "In human time it is: " << executionTime << double (executionTime)/CLOCKS_PER_SEC << "seconds" << endl;
}

long Timer :: getExecutionTimeInMicroseconds()
{
    return executionTime;
}
