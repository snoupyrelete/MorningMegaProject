//
//  IntNode.cpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "IntNode.hpp"


IntNode :: IntNode()
{
    this->nodeData = -999;
    this->nextPointer = nullptr;
}

IntNode :: IntNode(int data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

IntNode :: IntNode(int nodeData, IntNode * next)
{
    this->nodeData = nodeData;
    this->nextPointer = next;
}

int IntNode :: getNodeData()
{
    return nodeData;
}

IntNode * IntNode :: getNextPointer()
{
    return nextPointer;
}

void IntNode :: setNodeData(int nodeData)
{
    this->nodeData = nodeData;
}

void IntNode :: setNextPointer(IntNode * next)
{
    this->nextPointer = next;
}

