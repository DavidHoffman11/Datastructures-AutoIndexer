#ifndef OUTPUT_H
#define OUTPUT_H
#include "DSVector.h"
#include "Keyword.h"


class Output {
public:
    Output();
    ~Output();

    void printOutput(DSVector<Keyword>&, char**);
      //print output
    DSVector<Keyword> sortVector(DSVector<Keyword>&);
      //alphabetically sorts vector of keywords
};


#endif
