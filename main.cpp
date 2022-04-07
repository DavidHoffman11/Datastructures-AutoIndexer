#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include "DSVector.h"
#include "Keyword.h"

using namespace std;

int main(int argc, char **argv) {
    //catch tests run if there are no command line args
    if(argc == 1) {
        cout << "Running Catch Tests" << endl;
        Catch::Session().run();
    }
    Keyword start;
    start.readKeywords(argv);

    return 0;
}