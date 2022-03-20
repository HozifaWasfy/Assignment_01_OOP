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
    // we need a function to calculat the matrix size from the vector lenth and vice versa
    int get_vectorlenth_from_matrixsize(int m, int n);
    int get_vectorindex_from_location(int m, int n);
public:
    //constructor
    Matrix(int m, int n); // using m raws and n coulmns
    Matrix(vector<int> &vec, int m, int n);
    //operator overloading
    friend Matrix operator+(Matrix& m1, Matrix &m2);
    friend Matrix operator*(Matrix& m1, Matrix &m2);

   // friend ostream& operator<< (ostream& stream, Matrix& m);
    //getting entry in i and j
    int getEntry(int i, int j);
    //changing entry in i and j
    void changeEntry(int i, int j, int newValue);
    //printing matrix
    void print();
    static Matrix sum(Matrix m1, Matrix m2){
    if(m2.coloumns == 0&&m2.raws==0) return m1;
if(m1.coloumns == 0&&m1.raws==0) return m2;
if(m1.raws != m2.raws&&m1.coloumns != m2.coloumns){
return Matrix(0,0);
}
vector<int> vec;
for (int i = 0; i < m1.vect.size(); ++i) {
vec.push_back(m1.vect[i] + m2.vect[i]);
}
return Matrix(vec,m1.raws,m1.coloumns);
    };
    int size(){return raws*coloumns;};






};

#endif // MATRIX_H_INCLUDED
