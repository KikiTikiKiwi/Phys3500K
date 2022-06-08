/*
--------------------------------------------------------------------------------
Student: Kieran MacDonald
Prof: Dr. Guzzi
Class: computational physics 3500K
March 24, 2022
Goal: Consider the set of data below with the respective uncertainties 𝜎!
associated to yi:
Write a C++ code that analyzes these data by using least square fitting with a
quadratic function.
and estimates the goodness of the fit by calculating the 𝜒$/𝑁𝑝𝑡.
Be reminded that a good fit has 𝜒$/𝑁𝑝𝑡 ≈ 1.

--------------------------------------------------------------------------------
*/

#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

// Function to print matrix of any size
void print_matrix(Mat mat){
  int sizeR = mat.size();
  int sizeC = mat[0].size();
  for(int i = 0; i < sizeR; i++ ){
    for(int j = 0; j < sizeC; j++){
          cout<<mat[i][j]<<"  ";
    }
    cout<<endl;
  }
}
// Function to print vectors if needed
void print_Vector(Vec vec){
  int sizeV = vec.size();
  for(int i = 0; i < sizeV; i++){
    cout<<vec[i]<<"\t";
  }
}

// Function to calculate averages
double average_data(Vec data_points){
  double avg = 0;
  double sum = 0;
  int size_of_data = data_points.size();
  for(int i = 0; i < size_of_data; i++){
    sum += data_points[i];
  }
  avg = (sum/size_of_data);
  return avg;
}

Vec constant_Gen(double x_avg, double y_avg, Vec x_data, Vec y_data, Vec u_data){
  Vec constants(8);
  double s = 0;
  double sx = 0;
  double sxx = 0;
  double sxxx = 0;
  double sxxxx = 0;
  double sxxy = 0;
  double sxy = 0;
  double sy = 0;
  int size_of_data = x_data.size();

  // S
  for(int i = 0; i < size_of_data; i++){
    s += (1/pow(u_data[i],2));
  }
  constants[0] = s;
  // Sx
  for(int i = 0; i < size_of_data; i++){
    sx += ((x_data[i])/pow(u_data[i],2));
  }
  constants[1] = sx;
  // Sxx
  for(int i = 0; i < size_of_data; i++){
    sxx += ((pow((x_data[i]),2))/pow(u_data[i],2));
  }
  constants[2] = sxx;
  // sxxx
  for(int i = 0; i < size_of_data; i++){
    sxxx += ((pow((x_data[i]),3))/pow(u_data[i],2));
  }
  constants[3] = sxxx;
  // sxxxx
  for(int i = 0; i < size_of_data; i++){
    sxxxx += ((pow((x_data[i]),4))/pow(u_data[i],2));
  }
  constants[4] = sxxxx;
  // Sxxy
  for(int i = 0; i < size_of_data; i++){
    sxxy += (pow(x_data[i],2)*(y_data[i]))/(pow(u_data[i],2));
  }
  constants[5] = sxxy;
  // Sxy
  for(int i = 0; i < size_of_data; i++){
    sxy += ((x_data[i])*(y_data[i]))/(pow(u_data[i],2));
  }
  constants[6] = sxy;
  // Sy
  for(int i = 0; i < size_of_data; i++){
    sy += ((y_data[i])/pow(u_data[i],2));
  }
  constants[7] = sy;
  return constants;
}

// Our Function for Guassian Elimination. Will return solutions
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
  x[n-1] = b[n-1]/matrix[n-1][n-1];
  for(int i = n-1; i >= 0;i--){
    double sum = 0;
    for(int j = i+1; j <= n; j++){
      sum = sum + matrix[i][j]*x[j];
    }
      x[i] = (b[i]-sum)/matrix[i][i];
  }
  cout<<endl;
  return x;
}

double chiSquared(Vec ai, Vec x_data, Vec y_data, Vec u_data){
  int size_of_data = x_data.size();
  double sum = 0;
  double a = 0;
  double b = 0;
  for(int i = 0; i<size_of_data;i++){
    a = pow((y_data[i] - ((ai[0]) + (ai[1]*x_data[i]) + (ai[2]*pow(x_data[i],2)))),2);
    b = a/pow(u_data[i],2);
    sum += b;
  }
  return sum;
}

int main(){
// Create the needed space for our matrix
Mat matrix = {{0,0,0}, {0,0,0}, {0,0,0}};
Vec b(3);
Vec temp(8);
Vec solutions(3);
// Lets bring in our X data points
Vec X_data = {0.9, 1.30, 1.30, 1.40, 1.60, 1.80, 2.10, 2.10, 2.50, 2.90, 3.20, 3.30, 3.60, 4.00, 4.20, 4.30};
// Lets bring in our Y data points
Vec Y_data = {2.50, 4.03, 4.10, 4.40, 5.10, 6.05, 7.48, 7.60, 9.80, 12.4, 14.3, 15.2, 18.1, 19.9, 23.0, 23.9};
// Lets bring in our uncertainties
Vec U_data = {0.05, 0.0806, 0.082, 0.088, 0.102, 0.121, 0.1496, 0.152, 0.196, 0.248, 0.286, 0.304, 0.362, 0.398, 0.46, 0.478};
// Next we will need the averages of X and Y
double X_avg = average_data(X_data);
double Y_avg = average_data(Y_data);

// We now have to construct our matrix of coefficents
// double x_avg, double y_avg, Vec x_data, Vec y_data, Vec u_data
temp = constant_Gen(X_avg, Y_avg, X_data, Y_data, U_data);
for(int i = 0; i < 3; i++){
  for(int j = 0; j < 3; j++){
    matrix[i][j] = temp[i+j];
  }
}
// We now need the b
for(int i = 0; i < 3; i++){
  b[i] = temp[7-i];
}

solutions = (guassElim(matrix,b));
cout<<"The constants are as follows: "<<"a1 = "<<solutions[0]<<" a2 = "<<solutions[1]<<" a3 = "<<solutions[2]<<endl;
cout<<"-----------------------------------------------------------------------"<<endl;
// // Vec ai, Vec x_data, Vec y_data, Vec u_data
cout<<"The goodness of our fit: "<<chiSquared(solutions, X_data, Y_data, U_data)/X_data.size()<<endl;

return 0;
}



// It is noted that sumnation is a very crucial portion of the work here. THUS
// it is helpful to implement our own very function for suming an array of values
// double sumation(Vec a){
//   int arraySize = a.size();
//   double sumTotal = 0;
//   for(int i = 0; i < arraySize; i++){
//     sumTotal += a[i];
//   }
//   return sumTotal;
// }
//
// // Print vector
// void print_Vector(Vec vec){
//   int sizeV = vec.size();
//   for(int i = 0; i < sizeV; i++){
//     cout<<vec[i]<<"\t";
//   }
// }
//
// // Print Matrix
// void print_matrix(Mat mat){
//   int sizeR = mat.size();
//   int sizeC = mat[0].size();
//   for(int i = 0; i < sizeR; i++ ){
//     for(int j = 0; j < sizeC; j++){
//           cout<<"|"<<mat[i][j]<<"|";
//     }
//     cout<<endl;
//   }
// }
//
// // Implementing an avg function will also be helpful
// double average(Vec a, int N_points){
//   return sumation(a)/N_points;
// }
//
// // Since we are dealing with a system of equations it will be helpful to employ
// // the guassian elimination method to solve for the constants a1,a2,a3,a4.....
// // A*x = b ----> we will apply the function on the A matrix
// void Guass_elim_Piv(Mat& A, Vec& b, int N_dim){
//   double am, hold, m = 0;
//   int i,j,p = 0;
//
//   for(int i = 0; i < N_dim-1; i++){
//     am = abs(A[i][i]);
//     p = i;
//     for(int j = i + 1; j < N_dim; j++){
//       if(abs(A[j][i]) > am){
//         am = abs(A[j][i]);
//         p = j;
//       }
//     }
//     if(p > i){
//       for(int k = i; k < N_dim; k++){
//         hold = A[i][k];
//         A[i][k] = A[p][k];
//         A[p][k] = hold;
//       }
//       hold = b[i];
//       b[i] = b[p];
//       b[p] = hold;
//     }
//     for(int j = i + 1; j < N_dim; j++){
//       m = A[j][i]/A[i][i];
//       for(int k = i + 1; k < N_dim; k++){
//         A[j][k] = (A[j][k] - (m * A[i][k]));
//       }
//       b[j] = b[j] - m*b[i];
//     }
//   }
// }
//
// void back_sub(Mat A, Vec b, Vec& con, int N_dim){
//   double sum = 0;
//   con[N_dim-1] = b[N_dim-1]/A[N_dim-1][N_dim-1];
//   for(int i = N_dim-2; i >= 0;i--){
//     sum = 0;
//     for(int j = i+1; j < N_dim; j++){
//       sum = sum + A[i][j]*con[j];
//     }
//       con[i] = (b[i]-sum)/A[i][i];
//   }
// }
//
// // We will need a way to generate our A matrix such as S, Sxx, Sxxx.....
// // Thus we first must devise a way of producing the elements.
// double generate_S(int N_points, Vec x, Vec y, Vec u, int px, int py){
//   double res = 0;
//   for(int i = 0; i < N_points; i++){
//     res += (pow(x[i],px)*pow(y[i],py))/(pow(u[i],2));
//   }
//   return res;
// }
//
// void generate_A_matrix(int N_points, Vec x, Vec y, Vec u, Mat& A, int N_dim){
//   for(int i = 0; i < N_dim; i++){
//     for(int j = 0; j < N_dim; j++){
//       A[i][j] = generate_S(N_points, x, y, u, i+j, 0);
//     }
//   }
// }
//
// // Generate b matrix sy, sxy, sxxy, sxxxy ..... S(n,y)
// void generate_b_vec(int N_points, Vec x, Vec y, Vec u, Vec& b, int N_dim){
//   for(int i = 0; i < N_dim; i++){
//     b[i] = generate_S(N_dim, x, y, u, i, 1);
//   }
// }
