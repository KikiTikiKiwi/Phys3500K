#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>

#include "PolyReg.h"
#include "vector_fwrd.h"


// It is noted that sumnation is a very crucial portion of the work here. THUS
// it is helpful to implement our own very function for suming an array of values
double sumation(Vec a){
  int arraySize = a.size();
  double sumTotal = 0;
  for(int i = 0; i < arraySize; i++){
    sumTotal += a[i];
  }
  return sumTotal;
}

// Print vector
void print_Vector(Vec vec){
  int sizeV = vec.size();
  for(int i = 0; i < sizeV; i++){
    cout<<vec[i]<<endl;;
  }
  cout<<endl;
}

// Print Matrix
void print_matrix(Mat mat){
  int sizeR = mat.size();
  int sizeC = mat[0].size();
  for(int i = 0; i < sizeR; i++ ){
    for(int j = 0; j < sizeC; j++){
          cout<<"|"<<mat[i][j]<<"|";
    }
    cout<<endl;
  }
}

// Implementing an avg function will also be helpful
double average(Vec a, int N_points){
  return sumation(a)/N_points;
}

// Since we are dealing with a system of equations it will be helpful to employ
// the guassian elimination method to solve for the constants a1,a2,a3,a4.....
// A*x = b ----> we will apply the function on the A matrix
void Guass_elim_Piv(Mat& A, Vec& b, int N_dim){
  double am, hold, m = 0;
  int i,j,p = 0;

  for(int i = 0; i < N_dim-1; i++){
    am = abs(A[i][i]);
    p = i;
    for(int j = i + 1; j < N_dim; j++){
      if(abs(A[j][i]) > am){
        am = abs(A[j][i]);
        p = j;
      }
    }
    if(p > i){
      for(int k = i; k < N_dim; k++){
        hold = A[i][k];
        A[i][k] = A[p][k];
        A[p][k] = hold;
      }
      hold = b[i];
      b[i] = b[p];
      b[p] = hold;
    }
    for(int j = i + 1; j < N_dim; j++){
      m = A[j][i]/A[i][i];
      for(int k = i + 1; k < N_dim; k++){
        A[j][k] += - (m * A[i][k]);
      }
      b[j] += - m*b[i];
    }
  }
}

void back_sub(Mat A, Vec b, Vec& con, int N_dim){
  double sum = 0;
  con[N_dim-1] = b[N_dim-1]/A[N_dim-1][N_dim-1];
  for(int i = N_dim-2; i >= 0;i--){
    sum = 0;
    for(int j = i+1; j < N_dim; j++){
      sum += A[i][j]*con[j];
    }
      con[i] = (b[i]-sum)/A[i][i];
  }
}

// We will need a way to generate our A matrix such as S, Sxx, Sxxx.....
// Thus we first must devise a way of producing the elements.
double generate_S(int N_points, Vec x, Vec y, Vec u, int px, int py){
  double res = 0;
  for(int i = 0; i < N_points; i++){
    res += (pow(x[i],px)*pow(y[i],py))/(pow(u[i],2));
  }
  return res;
}

void generate_A_matrix(int N_points, Vec x, Vec y, Vec u, Mat& A, int N_dim){
  for(int i = 0; i < N_dim; i++){
    for(int j = 0; j < N_dim; j++){
      A[i][j] = generate_S(N_points, x, y, u, i+j, 0);
    }
  }
}

// Generate b matrix sy, sxy, sxxy, sxxxy ..... S(n,y)
void generate_b_vec(int N_points, Vec x, Vec y, Vec u, Vec& b, int N_dim){
  for(int i = 0; i < N_dim; i++){
    b[i] = generate_S(N_points, x, y, u, i, 1);
  }
}

double g_of_x(double x, Vec c, int N_dim){
  double sum = 0;
  for(int i = 0; i < N_dim; i++){
    sum += c[i]*pow(x,i);
  }
  return sum;
}

double chiSquared(Vec c, Vec x, Vec y, Vec u, int N_dim){
  int size_of_data = x.size();
  double res = 0;
  for(int i = 0; i<size_of_data;i++){
    res += pow(y[i] - g_of_x(x[i],c,N_dim),2)/pow(u[i],2);
  }
  return res;
}

double fit_goodness(Vec con, Vec x_data, Vec y_data, Vec u_data, int N_data, int N_dim){
  return chiSquared(con,x_data,y_data,u_data,N_dim)/N_data;
}
