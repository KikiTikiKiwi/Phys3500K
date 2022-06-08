/*
--------------------------------------------------------------------------------
Student: Kieran MacDonald
Prof: Dr. Guzzi
Class: computational physics 3500K
March 24, 2022
Goal: Try to make sense out of it. Convert this pseudocode
into a C++ code and add the code on backward solution method
to find the solutions. Verify that it works for the system
--------------------------------------------------------------------------------
*/

#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

void print_matrix(Mat mat){
  int sizeR = mat.size();
  int sizeC = mat[0].size();
  for(int i = 0; i < sizeR; i++ ){
    for(int j = 0; j < sizeC; j++){
          cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }
}

void print_Vector(Vec vec){
  int sizeV = vec.size();
  for(int i = 0; i < sizeV; i++){
    cout<<vec[i]<<"\t";
  }
}

Vec guassElim(Mat matrix, Vec b){
  double hold = 0;
  double m = 0;
  double am = 0;
  int p = 0;
  int n = matrix.size();
  for(int i = 0; i < n-1; i++){
    am = abs(matrix[i][i]);
    p = i;
    for(int j = i + 1; j < n; j++){
      if(abs(matrix[j][i]) > am){
        am = abs(matrix[j][i]);
        p = j;
      }
    }
    if(p > i){
      for(int k = i; k < n; k++){
        hold = matrix[i][k];
        matrix[i][k] = matrix[p][k];
        matrix[p][k] = hold;
      }
      hold = b[i];
      b[i] = b[p];
      b[p] = hold;
    }
    for(int j = i + 1; j < n; j++){
      m = matrix[j][i]/matrix[i][i];
      for(int k = i + 1; k < n; k++){
        matrix[j][k] = (matrix[j][k] - (m * matrix[i][k]));
      }
      b[j] = b[j] - m*b[i];
    }
  }

  Vec x(n);
  x[n-1] = (b[n-1]/matrix[n-1][n-1]);
  for(int i = n-1; i >= 0;i--){
    double sum = 0;
    for(int j = i+1; j <= n; j++){
      sum = sum + matrix[i][j]*x[j];
    }
      x[i] = (b[i]-sum)/matrix[i][i];
  }
  print_matrix(matrix);
  cout<<"-----------------------------------------------------------------------"<<endl;
  return x;
}


int main(){
  Mat matrix = {{14,14,-9,3,-5}, {14,52,-15,2,-32}, {-9,-15,36,-5,16}, {3,2,-5,47,49}, {-5,-32,16,49,79}};
  Vec b = {-15, -100, 106, 329, 463};
  print_matrix(matrix);
  cout<<"-----------------------------------------------------------------------"<<endl;
  //guassElim(testmatrix,testb);
  print_Vector(guassElim(matrix,b));

  return 0;
}
