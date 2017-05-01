//
//  HashTable.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 5/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <cmath>
#include <assert.h>

using namespace std;
template <class Type>
class HashTable
{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    // Array of pointers
    Type * * hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(Type data);
    long handleCollision(Type data, long currentPosition);
public:
    HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};

template <class Type>
bool HashTable<Type> :: isPrime(long sampleNumber)
{
    if(sampleNumber <= 1)
    {
        return false;
    }
    else if(sampleNumber == 2 || sampleNumber == 3)
    {
        return true;
    }
    else if(sampleNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(sampleNumber) + 1; next += 2)
        {
            if(canidateNumber % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}

//template <class Type>
//long HashTable<Type> :: nextPrime(long current)
//{ }

#endif /* HashTable_hpp */
