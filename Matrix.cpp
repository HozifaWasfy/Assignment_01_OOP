#include "Matrix.h"
#include<vector>
#include <iostream>

using namespace std;
Matrix::Matrix(int m, int n) {
this->raws = m;
this->coloumns = n;
int vec_size = get_vectorlenth_from_matrixsize(m,n);
vect.resize(get_vectorlenth_from_matrixsize(m,n));
for(int i =1;i <= vec_size;++i){
vect.push_back(i);
}
}
Matrix::Matrix(vector<int> &v, int m, int n) {
this->raws = m;
this->coloumns = n;
this->vect.resize(get_vectorlenth_from_matrixsize(m,n));
this->vect = v;

}
int Matrix::get_vectorlenth_from_matrixsize(int m, int n){
int x = m*n;
if (x%2==0){return x/2;}
return ((x/2)+1);
}
//maatrix multiplication is the first raw time the other matrix to make
Matrix operator+(Matrix& m1, Matrix &m2) {
if(m2.coloumns == 0&&m2.raws==0) return m1;
if(m1.coloumns == 0&&m1.raws==0) return m2;
if(m1.raws != m2.raws||m1.coloumns != m2.coloumns){
return Matrix(0,0);
}
Matrix m = m.sum(m1,m2);
return m;
}

int Matrix::get_vectorindex_from_location(int i, int j){

int c=0;
for(int h = 1;h<=raws;++h){


for(int k =1; k<=coloumns;++k){
if(h==i&&k==j){return c;}
if (h%2!=0&&k%2==0) {

 continue;
}
if (h%2==0&&k%2!=0) {

    continue;
}

c++;
}
}}
Matrix operator*(Matrix& m1, Matrix &m2) {
return Matrix::multiply(m1 , m2);
}
int Matrix::getEntry(int i, int j){
if(i<0||j<0){
throw invalid_argument("invalid indecies try again");
}
if(i>this->raws||j>this->coloumns){
throw invalid_argument("invalid indecies try again");
}
if (i%2!=0&&j%2==0) return 0;
if (i%2==0&&j%2!=0) return 0;
return vect.at(get_vectorindex_from_location(i,j));
}
void Matrix::changeEntry(int i, int j, int value){
if(i>raws || j>coloumns||i<0||j<0){
throw invalid_argument("invalid indecies");
}
if (i%2!=0&&j%2==0) throw invalid_argument("invalid indecies");;
if (i%2==0&&j%2!=0) throw invalid_argument("invalid indecies");;
this->vect.at(get_vectorindex_from_location(i,j)) = value;
}

void Matrix::print(){
cout<<endl;
if (raws <=0 ||coloumns<=0) throw invalid_argument("the matrix is empety");
for(int h = 1;h<=raws;++h){
    for(int k =1; k<=coloumns;++k){
        cout<<this->getEntry(h,k)<<" ";
}

cout<<endl;
}
}

Matrix Matrix::sum(Matrix m1, Matrix m2){
if(m2.coloumns == 0&&m2.raws==0) return m1;
if(m1.coloumns == 0&&m1.raws==0) return m2;
if(m1.raws != m2.raws&&m1.coloumns != m2.coloumns){
return Matrix(0,0);
}

vector<int> vec;
for (unsigned int i = 0; i < m1.vect.size(); ++i) {

vec.push_back(m1.vect[i] + m2.vect[i]);
}
return Matrix(vec,m1.raws,m1.coloumns);
   }


Matrix Matrix::multiply(Matrix &m1, Matrix &m2) {
    if(m1.coloumns != m2.raws){

    throw invalid_argument("the raws of m1 not equal coloumns of m2");
    }
    Matrix m(m1.raws,m2.coloumns);
    for (int i = 1; i <= m1.raws; ++i) {
        for (int j = 1; j <= m2.coloumns; ++j) {
            int value = 0;
            for (int k = 1; k <= m1.coloumns; k++) {
        value += m1.getEntry(i,k) * m2.getEntry(k,j);
    }
            m.changeEntry(i,j,value);
        }
    }
    return m;
}






