#include "ReadBook.h"
#include "DSVector.h"
#include "DSString.h"
#include "Output.h"
#include <iostream>
#include <fstream>

using namespace std;

ReadBook::ReadBook() {

}

ReadBook::~ReadBook() {

}

void ReadBook::readBook(DSVector<Keyword> kWordList, char **argv) {
    char* buffer = new char[2048];
    char* bookLine;
    int pageNum = 0;
      //keeps track of page number
    ifstream myFile;
    myFile.open(argv[1]);

    if (myFile.is_open() == false) {
        cout << "Cannot open book.txt file" << endl;
        //checks to make sure file opens properly
    }

    while(myFile.eof() != true) {
        myFile.getline(buffer, 2048);

        if(buffer[1] == '-' && buffer[2] == '1') {
            break;
        }

        else if(buffer[0] == '<') {
            pageNum++;
        }  //sets pageNum on every new page

        else if(strlen(buffer) == 0) {
            continue;
        }  //returns to top of loop if getline hits an empty line

        else {
            for(int i = 0; i < strlen(buffer); i++) {
                buffer[i] = tolower(buffer[i]);
            }  //makes buffer all lowercase

            bookLine = strtok(buffer, " ,.?!;:");
              //initial call to strtok
            DSString temp (bookLine);
              //stores bookLine in a DSString so isElement function will work

            if(kWordList.isElement(temp) == true) {
                for(int i = 0; i < kWordList.getSize(); i++) {
                    if(kWordList[i].getKWord() == temp) {
                        kWordList[i].setPageNum(pageNum);
                    }
                }  //adds pageNum where keyword is found to the vector
            }  //checks if word is a keyword

            while(buffer != nullptr) {
                bookLine = strtok(nullptr, " ,.?!;:");

                if(bookLine == NULL) {
                    break;
                }

                DSString temp1 (bookLine);

                if(kWordList.isElement(temp1) == true) {
                    for(int i = 0; i < kWordList.getSize(); i++) {
                        if(kWordList[i].getKWord() == temp1) {
                            kWordList[i].setPageNum(pageNum);
                        }
                    }  //adds pageNum where keyword is found to the vector
                }  //checks if word is a keyword
            }
        }
    }

    myFile.close();

    Output o;
      //used to call printOutput function
    o.printOutput(kWordList, argv);
}