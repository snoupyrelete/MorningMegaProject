//
//  CircularList.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef CircularList_hpp
#define CircularList_hpp

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
public:
    CircularList();
    void add(Type data);

    
    
};

#endif /* CircularList_hpp */
