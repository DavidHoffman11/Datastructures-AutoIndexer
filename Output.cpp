#include "Output.h"
#include "Keyword.h"
#include "DSVector.h"
#include <iostream>
#include <fstream>

using namespace std;

Output::Output() {

}

Output::~Output() {

}

void Output::printOutput(DSVector<Keyword>& kWordList, char** argv) {
    DSVector<Keyword> sortedList;
    sortedList.setSize(9);
    ofstream myFile;

    sortedList = sortVector(kWordList);
      //sorts Keywords and stores the sorted list in sortedList
    DSString kWord1 = sortedList[0].getKWord();
      //sets kWord1 equal to first keyword

    myFile.open(argv[3]);

    if (myFile.is_open() == false) {
        cout << "Cannot open output file" << endl;
        //checks to make sure file opens properly
    }

    myFile << "[" <<  kWord1[0] << "]" << endl;
      //prints the first letter of the first keyword

    for(int i = 0; i < sortedList.getSize(); i++) {
        myFile << sortedList[i].getKWord() << ": ";
        if(sortedList[i].getPageNum().getSize() != 0) {
            for(int j = 0; j < sortedList[i].getPageNum().getSize(); j++) {
                if(j==0 || sortedList[i].getPageNum()[j] != sortedList[i].getPageNum()[j-1]) {
                    myFile << sortedList[i].getPageNum()[j] << ", ";
                }  //checks if page number has already been printed
            }
        }  //checks if keyword has been found on any pages
        myFile << endl;
          //prints keyword and lines where it's found to output file

        if(sortedList.getSize() != i+1) {
            if(sortedList[i].getKWord()[0] != sortedList[i+1].getKWord()[0])  {
                myFile << "[" << sortedList[i+1].getKWord()[0] << "]" << endl;
            }  //prints first letter of next keyword if it isn't the same as the previous word
        }
    }

    myFile.close();
}

DSVector<Keyword> Output::sortVector(DSVector<Keyword>& kWordList) {
    DSVector<Keyword> sortedList;
    Keyword lowWord = kWordList[0];

    while(sortedList.getSize() != kWordList.getSize()-1) {
        for(int j = 0; j < kWordList.getSize(); j++) {
            if(sortedList.isElement(kWordList[j].getKWord()) == true) {
                continue;
            }  //checks if word is already in vector
            if(kWordList[j].getKWord()[0] < lowWord.getKWord()[0]) {
                lowWord = kWordList[j];
            }
            else if(kWordList[j].getKWord()[0] == lowWord.getKWord()[0])  {
                if(kWordList[j].getKWord()[1] < lowWord.getKWord()[1]) {
                    lowWord = kWordList[j];
                }  //checks if second letter is first alphabetically
                else if(kWordList[j].getKWord()[1] == lowWord.getKWord()[1]) {
                    if (kWordList[j].getKWord()[2] < lowWord.getKWord()[2]) {
                        lowWord = kWordList[j];
                    }  //checks if third letter is first alphabetically
                }  //if first and second letter are the same
            } //if first letter is the same
            else {
                continue;
            }
        }

        sortedList.push_back(lowWord);
        lowWord = kWordList[1];
    }

    return sortedList;
}