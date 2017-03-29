//
//  FileController.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "DoubleList.hpp"
#include "Meme.hpp"
// #include "CrimeData.hpp"
#include <string>
#include <fstream> // File operations
#include <iostream> // Console access
#include <sstream> // String as stream

using namespace std;

class FileController
{
private:
    DoubleList<Meme> memeList;
public:
    DoubleList<Meme> readMemeDataFromFileAsList(string filename);
    void writeMemeDataStatistics(DoubleList<Meme> source, string filename);
};

#endif /* FileController_hpp */
