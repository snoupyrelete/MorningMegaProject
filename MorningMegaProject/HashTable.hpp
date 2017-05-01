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
    HashNode<Type> * * hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->hashTableStorage = HashNode<Type> * [capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] hashTableStorage;
}

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

template <class Type>
long HashTable<Type> :: nextPrime(long current)
{
    int nextPrime = (this->capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template<class Type>
long HashTable<Type> :: findPosition(HashNode<Type> * data)
{
    long insertPosition = data->getKey() % this->capacity;
    return insertPosition;
}

template<class Type>
long HashTable<Type> :: handleCollision(HashNode<Type> * data, long currentPosition)
{
    long shift = 17;
    
    for(long position = currentPosition + shift; position != currentPosition; position += shift)
    {
        if(position > capacity)
        {
            position = position % capacity;
        }
        
        if(hashTableStorage[position] == nullptr)
        {
            return position;
        }
    }
    return -1;
}


#endif /* HashTable_hpp */
