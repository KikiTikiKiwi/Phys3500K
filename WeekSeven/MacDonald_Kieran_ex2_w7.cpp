/*
Kieran MacDonald
Computational Physics
Profesor: Dr. Guzzi
02/24/2022
Goal: Write a C++ code use the vector class to build a m x n matrix and
multiplies it by a vector. (use cininsert matrix elements and vector
components)
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>

#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

Vec operator*(const Mat &a, const Vec &x){
  int i,j;
  int m = a.size();
  int n = x.size();

  Vec prod(m);

  for(i = 0; i < m; i++){
    prod[i] = 0.;
    for(j = 0; j < n; j++)
      prod[i] += a[i][j]*x[j];
  }
  return prod;
}

int main(){
Vector<double> v{1,2,3,4,2,8};
Vector<double> v1{1,2,3,4,2,8};

Vector<double> result = v*v1;

  return 0;
}


typedef vector<double> Vec;
typedef vector<Vec> Mat;
