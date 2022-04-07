#include "Keyword.h"
#include "DSVector.h"
#include "DSString.h"
#include "ReadBook.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

Keyword::Keyword() {
    //pageNum.setSize(5);
}

Keyword::~Keyword(){

}

void Keyword::readKeywords(char **argv) {
    DSVector<Keyword> kWordList;
    char* buffer = new char[500];
    ifstream myFile;
    myFile.open(argv[2]);


    if (myFile.is_open() == false) {
        cout << "Cannot open keyword.txt file" << endl;
        //checks to make sure file opens properly
    }

    while(myFile.eof() != true) {
        myFile.getline(buffer, 500);
        //DSString temp (buffer);

        for(int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }  //makes buffer all lowercase

        Keyword newWord;
        newWord.kWord = buffer;

        kWordList.push_back(newWord);
    }  //loop runs until the end of the file

    myFile.close();

    ReadBook step2;
    step2.readBook(kWordList, argv);
    //calls function to read book and find keywords
}

DSString Keyword::getKWord() {
    return this->kWord;
}

DSVector<int> Keyword::getPageNum() {
    return pageNum;
}

void Keyword::setPageNum(int x) {
    this->pageNum.push_back(x);
}

Keyword Keyword::operator=(const Keyword &k) {
    Keyword word = k;
    pageNum = word.pageNum;

    this->kWord = word.kWord;

    return *this;
}
