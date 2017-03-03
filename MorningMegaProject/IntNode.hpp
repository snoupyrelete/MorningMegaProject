//
//  IntNode.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nextPointer;
public:
    // Constructors
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specfied value and reference to the next node
    */
    IntNode(int value, IntNode * nextNode);
    
    // Methods
    int getNodeData();
    IntNode * getNextPointer();
    
    void setNodeData(int value);
    void setNextPointer(IntNode * updateNode);
};

#endif /* IntNode_hpp */
