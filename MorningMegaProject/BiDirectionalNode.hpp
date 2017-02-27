//
//  BiDirectionalNode.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/27/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BiDirectionalNode_hpp
#define BiDirectionalNode_hpp

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    Type data;
    BiDirectionalNode<Type> * previousPointer;
    BiDirectionalNode<Type> * nextPointer;
public:
    BiDirectionalNode<Type>();
    BiDirectionalNode<Type>(Type data);
    BiDirectionalNode<Type>(Type data, BiDirectionalNode<Type> * prev, BiDirectionalNode<Type> * next);

    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * prev);
};

template <class Type>
BiDirectionalNode :: BiDirectionalNode(Type data) : Node(data)
{
    
}


#endif /* BiDirectionalNode_hpp */
