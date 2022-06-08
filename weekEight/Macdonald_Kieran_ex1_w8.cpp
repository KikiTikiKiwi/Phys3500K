/*
-----------------------------------------------------------------------------
Kieran Macdonald
Computational Physics 1
Dr.Guzzi
Due:March 15
Goal: Write c++ code that uses the vector class to build a m by n matrix and
 multiplies it by another matrix n by r
-----------------------------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

Mat multiply(Mat a, Mat b, int r){
  int i,j,k = 0;
  int m = a.size();
  int n = b.size();
  // ON the test this is what i had troule with, was allocating a matrix size
  vector<vector<double>> tempMatrix(m,vector<double>(r));
  for(i = 0; i < m; i++){
    for(j = 0; j < r; j++){
      for(int k = 0; k < n; k++){
        tempMatrix[i][j] += (a[i][k]*b[k][j]);
      }
    }
  }
  return tempMatrix;
}

// class that makes matrix objects from the vector class.
class Matrix{
public:
  Mat matrix; // vectors of vectors <double>
  int r; // r is m
  int c; // c is n
  //default matrix constructor
  Matrix(Mat mat, int k){
    r = mat.size();
    c = k;
    matrix = mat;
  }
  Matrix(int row, int col){
    r = row;
    c = col;
    cout<<"created matrix, size is "<<matrix.size()<<endl;

    for(int i = 0; i < row; i++){
      Vec temp(col);
      for(int j = 0; j < col; j++){
        std::cin>> temp[j];
      }
      matrix.push_back(temp);
      cout<<"added row "<<i<<" vector of size "<<temp.size()<<endl;
    }
    cout<<"intialized matrix of size "<< matrix.size()<<endl;
  }
};

void print_matrix(Matrix mat){
  for(int i = 0; i < mat.r; i++ ){
    for(int j = 0; j < mat.c; j++){
          cout<<mat.matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
}

void print_matrix(Mat mat, int n, int r){
  for(int i = 0; i < n; i++ ){
    for(int j = 0; j < r; j++){
          cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main(){
  int m = 0;
  int n = 0;
  int r = 0;
  cout<<"Please enter in the size of matrix A, m by n"<<endl;
  cin>>m;
  cin>>n;
  cout<<"Please enter in colum size of matrix B- so it will be n by r"<<endl;
  cin>>r;

  cout<<"Now enter matrix A"<<endl;
  Matrix newObj(m,n);
  print_matrix(newObj);
  cout<<"Now enter in values for matrix B"<<endl;
  Matrix otherObj(n,r);
  print_matrix(otherObj);

  cout<<"The product matrix (P = A*B) is: "<<endl;
  Mat product = multiply(newObj.matrix, otherObj.matrix, r);
  //Matrix prod(product);
  print_matrix(product,m,r);

  return 0;
}
