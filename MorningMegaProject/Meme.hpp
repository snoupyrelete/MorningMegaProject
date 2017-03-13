//
//  Meme.hpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Meme_hpp
#define Meme_hpp
#include <string>

using namespace std;

class Meme
{
private:
    string title;
    int dankness;
    double hipsterQuotient;
    bool mainstream;
public:
    Meme();
    Meme(string title);
    
    int getDankness();
    double getHipsterQuotient();
    bool isMainstream();
    string getTitle();
    
    void setDankness(int dankness);
    void setHipsterQuotient(double quotient);
    void setMainstream(bool mainstream);
    void setTitle(string title);
};

#endif /* Meme_hpp */

