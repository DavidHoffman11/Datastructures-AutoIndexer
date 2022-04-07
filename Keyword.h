#ifndef KEYWORD_H
#define KEYWORD_H
#include "DSVector.h"
#include "DSString.h"

using namespace std;

class Keyword {
private:
    DSString kWord;
    DSVector<int> pageNum;

public:
    Keyword();
    //default constructor
    ~Keyword();
    //destructor

    void readKeywords(char** argv);
    //reads in keywords and stores them in a vector
    DSString getKWord();
      //returns keyword
    DSVector<int> getPageNum();
      //returns pageNum
    void setPageNum(int);
      //sets pageNum
    Keyword operator=(const Keyword&);
};


#endif
