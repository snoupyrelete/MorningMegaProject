//
//  Meme.cpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "Meme.hpp"

Meme :: Meme()
{
    this->title = "normie";
    this->dankness = 0;
    this->hipsterQuotient= -.999;
    this->mainstream = true;
}

Meme :: Meme(string title)
{
    this->title = title;
    this->dankness = title.length();
    this->hipsterQuotient = 3.14;
    this->mainstream = true;
}

int Meme :: getDankness()
{
    return this->dankness;
}

double Meme :: getHipsterQuotient()
{
    return this->hipsterQuotient;
}

bool Meme :: isMainstream()
{
    
    return this->mainstream;
}

string Meme :: getTitle()
{
    return this->title;
}

void Meme :: setDankness(int dankness)
{
    this->dankness  = dankness;
}

void Meme :: setHipsterQuotient(double quotient)
{
    this->hipsterQuotient = quotient;
}

void Meme :: setMainstream(bool mainstream)
{
    this->mainstream = mainstream;
}

void Meme :: setTitle(string title)
{
    this->title = title;
}




