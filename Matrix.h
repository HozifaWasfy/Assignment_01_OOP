#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<vector>
#include <iosfwd>
using namespace std;
class Matrix {
private:
    vector<int> vect;
    int raws;
    int coloumns;
    // we need a function to calculate the matrix size from the vector length and vice versa
    int get_vectorlenth_from_matrixsize(int m, int n);
    int get_vectorindex_from_location(int i, int j);
public:
    //constructor
    int size() {return raws*coloumns;};
    Matrix(int m, int n); // using m raws and n columns
    Matrix(vector<int> &vec, int m, int n);
    //operator overloading
    friend Matrix operator+(Matrix& m1, Matrix &m2);
    friend Matrix operator*(Matrix& m1, Matrix &m2);

    //getting entry in i and j
    int getEntry(int i, int j);
    //changing entry in i and j
    void changeEntry(int i, int j, int newValue);
    //printing matrix
    void print();
    //sum and mult two matricies
    static Matrix sum (Matrix m1, Matrix m2);
    static Matrix multiply(Matrix &m1, Matrix &m2);

};





#endif // MATRIX_H_INCLUDED
