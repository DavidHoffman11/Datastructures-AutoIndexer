#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector class", "[DSVector]") {

    SECTION("= operator in DSVector") {
        DSVector<int> x;
        int a;
        int b;
        int c;
        int d;
        int e;

        x.push_back(3);
        x.push_back(4);
        x.push_back(5);
        x.push_back(6);
        x.push_back(7);

        a = x[0];
        b = x[1];
        c = x[2];
        d = x[3];
        e = x[4];

        REQUIRE(a== 3);
        REQUIRE(b== 4);
        REQUIRE(c== 5);
        REQUIRE(d== 6);
        REQUIRE(e== 7);
    }

    SECTION("[] operator DSVector") {
        DSVector<int> x;
        DSVector<int> y;

        x.push_back(6);
        y.push_back(6);

        int z;
        z = x[0];

        REQUIRE(x[0]== y[0]);
    }

    SECTION("== operator for DSVector") {
        DSVector<int> x;
        DSVector<int> y;

        x.push_back(1);
        x.push_back(1);
        x.push_back(1);
        y.push_back(1);
        y.push_back(1);
        y.push_back(1);

        REQUIRE(x[1]== y[1]);
    }

    SECTION("getSize and getCapacity in DSVector") {
        DSVector<int> x;

        REQUIRE(x.getSize()== 0);
        REQUIRE(x.getCapacity()== 10);
    }

    SECTION("testing isEmpty in DSVector") {
        DSVector<int> x;
        DSVector<int> y;

        x.push_back(1);

        REQUIRE(x.isEmpty(x)== false);
        REQUIRE(y.isEmpty(y)== true);
    }

    SECTION("testing clear in DSVector") {
        DSVector<int> x;

        x.push_back(1);
        x.push_back(1);
        x.push_back(1);
        x.push_back(1);

        x.clear();

        REQUIRE(x.isEmpty(x)== true);
    }

    SECTION("testing pop and push_back in DSVector") {
        DSVector<int> x;

        x.push_back(1);
        x.push_back(2);
        x.push_back(3);

        x.pop();

        REQUIRE(x.getSize()== 2);
        REQUIRE(x[1]== 2);
        REQUIRE(x[0]== 1);
    }

    SECTION("resize in DSVector") {
        DSVector<int> x[10];

        x->resize();

        REQUIRE(x->getCapacity()== 20);
    }

    SECTION("isElement in DSVector") {
        DSVector<DSString> x;
        DSVector<DSString> y;
        DSString a = "4";
        DSString b = "5";
        DSString c = "67";

        x.push_back(a);
        x.push_back(b);

        REQUIRE(y.isElement(x, a) == true);
        REQUIRE(y.isElement(x, b) == true);
        REQUIRE(y.isElement(x, c) == false);
    }
}

TEST_CASE("DSString class", "[DSString]") {

    SECTION("= operator in DSString") {
        char x[10] = "SMU";
        char y[10] = "";

        DSString word(y);
        DSString word1(x);

        word = word1;

        REQUIRE(word[1]== 'M');
        REQUIRE(word1[0]== 'S');
    }

    SECTION("== operator in DSString") {
        char x[10] = "SMU";
        char y[10] = "TCU";
        char z[10] = "SMU";

        DSString word(x);
        DSString word1(y);
        DSString word2(z);

        REQUIRE(word == word2);
    }

    SECTION("+ operator in DSString") {
        DSString x = "TCU";
        DSString y = " sucks";
        DSString z = "TCU sucks";

        DSString a = x + y;

        REQUIRE(a==z);
    }

    SECTION("< operator DSString") {
        DSString x = "Dave";
        DSString y = "David";

        REQUIRE(x<y);
    }

    SECTION("+= operator DSString") {
        DSString x = "S";
        DSString y = "MU";
        DSString z = "SMU";

        DSString a = x += y;

        REQUIRE(a== z);
    }

    SECTION("[] operator DSString") {
        DSString x = "SMU";

        REQUIRE(x[0]== 'S');
        REQUIRE(x[1]== 'M');
        REQUIRE(x[2]== 'U');
    }

    SECTION("testing substring function in DSString") {
        DSString x = "TCU sucks";
        DSString y = x.substring(0, 3);

        REQUIRE(y == "TCU");
    }
}

