#ifndef READBOOK_H
#define READBOOK_H
#include "DSVector.h"
#include "Keyword.h"

class ReadBook {
private:
public:
    ReadBook();
    //default
    ~ReadBook();
    //destructor

    void readBook(DSVector<Keyword>, char **argv);
};


#endif
