//
//  StructureController.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "Array.hpp"
#include "Node.hpp"

#include <string>

class StructureController
{
private:
    Node<int> numberNode;
    Node<std::string> wordNode;
    Array<int> numberArray;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
public:
    StructureController();
    void start();
};

#endif /* StructureController_hpp */
