#include "Matrix.h"
#include<vector>
#include <cmath>
#include <iostream>

using namespace std;
Matrix::Matrix(int m, int n) {
this->raws = m;
this->coloumns = n;
int vec_size = get_vectorlenth_from_matrixsize(m,n);
for(int i =1;i <= vec_size;i++){
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
if(m1.raws != m2.raws&&m1.coloumns != m2.coloumns){
return Matrix(0,0);
}
vector<int> vec;
for (int i = 0; i < m1.vect.size(); ++i) {
vec.push_back(m1.vect[i] + m2.vect[i]);
}
return Matrix(vec,m1.raws,m1.coloumns);
}

int Matrix::get_vectorindex_from_location(int i, int j){
    if (coloumns%2==0){
if (i%2!=0){
        return ((coloumns/2)*--i)+(j/2);}
    return((coloumns/2)*--i)+(j/2)-1;
    }else{
        if (i%2==1){
    if (i%2!=0){
        return ((coloumns/2)*--i)+(j/2)-(i/2);}
    return((coloumns/2)*--i)+(j/2)-(i/2);

    }else{
        if (i%2!=0){
        return ((coloumns/2)*--i)+(j/2);}
    return((coloumns/2)*--i)+(j/2)-2;}
    }


}
Matrix operator*(Matrix& m1, Matrix &m2) {
Matrix m(m1.raws,m2.coloumns);
if(m1.coloumns!=m2.raws||m2.raws!=m2.coloumns) throw invalid_argument("the matrices cannot be differnt sizes");
int val = 0;
for (int i =0;i<m1.vect.size();++i){
    m.vect.push_back(m1.vect.at(i)*m2.vect.at(i));
}
return m;
}
int Matrix::getEntry(int i, int j){
if(i>coloumns || j>raws||i<0||j<0){
throw invalid_argument("invalid indecies");
}
if (i%2!=0&&j%2==0) return 0;
if (i%2==0&&j%2!=0) return 0;
return vect.at(get_vectorindex_from_location(i,j));
}
void Matrix::changeEntry(int i, int j, int value){
if(i>coloumns || j>raws||i<0||j<0){
throw invalid_argument("invalid indecies");
}
if (i%2!=0&&j%2==0) return;
if (i%2==0&&j%2!=0) return;
this->vect.at(get_vectorindex_from_location(i,j)) = value;
}

void Matrix::print(){
    if (raws <=0 ||coloumns<=0) throw invalid_argument("the matrix is empety");
for(int h = 0;h<raws;++h){


for(int k =0; k<coloumns;++k){

if (h%2!=0&&k%2==0) {
 cout<<"0 ";
 continue;
}
if (h%2==0&&k%2!=0) {
    cout<<"0 ";
    continue;
}
cout<<getEntry(h,k)<<" ";
}
cout<<endl;
}
}





