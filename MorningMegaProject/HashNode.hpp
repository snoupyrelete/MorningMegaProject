//
//  HashNode.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 5/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

template <class Type>
class HashNode
{
private:
    Type data;
    long key;
public:
    HashNode();
    HashNode(Type data);
    
    Type getData();
    long getKey() const;
    void setData(Type data);
};

template <class Type>
HashNode<Type> :: HashNode()
{
    this->key = rand();
}

template <class Type>
HashNode<Type> :: HashNode(Type data)
{
    this->key = rand();
    this->data = data;
}

template <class Type>
long HashNode<Type> :: getKey() const
{
    return this->key;
}

template <class Type>
Type HashNode<Type> :: getData()
{
    return this->data;
}

template <class Type>
void HashNode<Type> :: setData(Type data)
{
    this->data = data;
}


#endif /* HashNode_hpp */
