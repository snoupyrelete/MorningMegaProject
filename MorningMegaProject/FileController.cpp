//
//  FileController.cpp
//  MorningMegaProject
//
//  Created by Robson, Dylan on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "FileController.hpp"


/*
@param filename is an absolute path to the file, e.g : /User/drob8896/Downloads/Memes.csv
*/
DoubleList<Meme> FileController :: readMemeDataFromFileAsList(string filename)
{
    DoubleList<Meme> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    // Open the file
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        // While not at the end of the file (eof)
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempHipster, tempDank, tempMainstream;
            
            double quotient;
            int dankness;
            bool isMainstream;
            
            getline(parseCSV, title, ',');
            getline(parseCSV, tempHipster, ',');
            getline(parseCSV, tempDank, ',');
            getline(parseCSV, tempMainstream, ',');
            
            // Exclude first row headers
            if(rowCount != 0)
            {
                // String to double
                quotient = stod(tempHipster);
                // String to int
                dankness = stoi(tempDank);
                isMainstream = stoi(tempMainstream);
                
                Meme temp(title);
                temp.setHipsterQuotient(quotient);
                temp.setDankness(dankness);
                temp.setMainstream(isMainstream);
                
                dataSource.add(temp);
            }
            rowCount++;
            // Remove this line
            cout << currentCSVLine << endl;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE!" << endl;
    }
    return dataSource;
}

void FileController :: writeMemeDataStatistics(DoubleList<Meme> dataSource, string filename)
{
    // Output file stream instead of input (ifstream)
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "Contents of the list: " << endl;
        
        for(int index = 0; index < dataSource.getSize(); index++)
        {
            //saveFile  << "Meme Title: " << dataSource.getFromIndex(index).getTitle() << endl;
        }
    }
    else
    {
        cerr << "File unavailable" << endl;
    }
    saveFile.close();
}

//BinarySearchTree<CrimeData> FileController :: readCrimeDataToBinarySearchTree(string filename)
//{
//    
//    BinarySearchTree<CrimeData> crimeData;
//    
//    
//    
//    string currentCSVLine;
//    
//    int rowCount = 0;
//    
//    
//    
//    ifstream dataFile(filename);
//    
//    
//    
//    if(dataFile.is_open())
//        
//    {
//        
//        while(!dataFile.eof())
//            
//        {
//            
//            getline(dataFile, currentCSVLine, '\r');
//            
//            
//            
//            //Exclude first row headers
//            
//            if (rowCount != 0)
//                
//            {
//                
//                CrimeData rowData(currentCSVLine);
//                
//                crimeData.insert(rowData);
//                
//            }
//            
//            rowCount++;
//            
//        }
//        
//        dataFile.close();
//        
//    }
//    
//    else
//        
//    {
//        
//        cerr << "NO FILE" << endl;
//        
//    }
//    
//    
//    
//    
//    
//    return crimeData;
//    
//}
//
//AVLTree<CrimeData> FileController :: readCrimeDataToAVLTree(string filename)
//
//{
//    
//    AVLTree<CrimeData> crimeData;
//    
//    
//    
//    string currentCSVLine;
//    
//    int rowCount = 0;
//    
//    
//    
//    ifstream dataFile(filename);
//    
//    
//    
//    if(dataFile.is_open())
//        
//    {
//        
//        while(!dataFile.eof())
//            
//        {
//            
//            getline(dataFile, currentCSVLine, '\r');
//            
//            
//            
//            //Exclude first row headers
//            
//            if (rowCount != 0)
//                
//            {
//                
//                CrimeData rowData(currentCSVLine);
//                
//                crimeData.insert(rowData);
//                
//            }
//            
//            rowCount++;
//            
//        }
//        
//        dataFile.close();
//        
//    }
//    
//    else
//        
//    {
//        
//        cerr << "NO FILE" << endl;
//        
//    }
//    
//    
//    
//    return crimeData;
//    
//}

