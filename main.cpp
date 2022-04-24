#include <iostream>
#include "Matrix.h"
#include "Menu.h"
using namespace std;
#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
 Menu m;
 m.Start();
 return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.h"
TEST_CASE("Creating Matrices of different sizes"){
    SECTION("checking bu getEntry because it throws error for empty matrix and zero"){
        Matrix m(0,0);
        CHECK(m.size() == 0);
    }
    SECTION("matrix with size 1*1"){
        Matrix m(1,1);
        CHECK(m.size() == 1);
    }
    SECTION("matrix with size 2*2"){
        Matrix m(2,2);
        CHECK(m.size() == 4);
    }

}
TEST_CASE("retrieving and editing a value in the matrix"){
    vector<int> vec({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    Matrix m(vec,6,6);
    SECTION("retrieving an element inside the matrix"){
        CHECK(m.getEntry(1,1) == 1);
    }
    SECTION("changing element"){
        m.changeEntry(1,1,5);
        CHECK(m.getEntry(1,1) == 5);
    }
    SECTION("illegal indecies"){
        CHECK_THROWS_AS(m.getEntry(-1,6), invalid_argument);
    }

}
TEST_CASE("summation of matrices"){
    vector<int> vec({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    Matrix a(vec,6,6);
    Matrix b(vec,6,6);
    Matrix c(6,6);
    Matrix d1 = a+b;
    SECTION("a + b = b + a"){
        CHECK(((d1.getEntry(2,2)==(b.getEntry(2,2)+(a.getEntry(2,2))))));
    }

}
TEST_CASE("multiplication of matrices"){
    vector<int> vec({1,3,5});
    vector<int> vec2({2,4,6});
    Matrix a(vec,2,3);
    Matrix b(vec2,3,2);
    Matrix d1 = a*b;
    SECTION("d= b * a"){
        CHECK(((d1.getEntry(1,1)== 20)));
    }

}
TEST_CASE("memory overloading"){

    SECTION("Matrix of size 0"){
        Matrix m(0,0);
        CHECK(m.size() == 0);
    }

    SECTION("Matrix of size 1000"){
        Matrix m(100,10);
        CHECK(m.size() == 1000);
    }
}


#endif
