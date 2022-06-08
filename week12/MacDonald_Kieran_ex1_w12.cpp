/*
Student: Kieran MacDonald
Proffesor: Dr.Guzzi
Class:
Assignment:
Goal: Write a C++ code that uses the instructions in the pseudo codes below
to generate Simpson’s integration and trapezoid integration over a uniform
grid. Compare the two methods for the function
*/


#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

double functionOne(double x){
  double y = 0;
  y = 1-(sin(x)*exp(-2*pow(x,2)));
  return y;
}

void print_Vector(Vec vec){
  int sizeV = vec.size();
  for(int i = 0; i < sizeV; i++){
    cout<<vec[i]<<endl;
  }
}

// Simple trapizoid function
double trap_integration(double a, double b, int n, double (*func)(double)) {
  // This method we imagine we are making a trapizoid under our curve from point
  // a to point b. n will determine our grid size
  //This method will sum up the area of the trapezoids under our curve. The finer
  // our grid the better of an answer we get.
  double sum, h, x, trapezoid = 0;
  sum = 0.5 * (func(a) + func(b));
  h = (b-a)/n;
  for(int i = 0; i < n-1; i++){
    x = a + (i*h);
    sum = sum + func(x);
  }
  trapezoid = h*sum;

  return trapezoid;
}

double simson_integration(double a, double b, int n, double (*func)(double)){
  double simp, h, sum4, sum2, x = 0;
  simp = func(a) + func(b);
  h = (b-a)/n;
  for(int i = 0; i < n-1; i=i+2){
    x = a + (i*h);
    sum4 = sum4 + func(x);
  }
  for(int i = 0; i < n-2; i=i+2){
    x = a + (i*h);
    sum2 = sum2 + func(x);
  }
  simp = (h/3)*(simp + 4*sum4 + 2*sum2);
  return simp;
}

int main(){
  Vec trap_results;
  Vec simp_results;
  double a = -1;
  double b = 1;
  double n = 20;
  double area_curve = 0;
  cout<<"The value of h is: "<<(b-a)/n<<endl;
  area_curve = trap_integration(a,b,n,&functionOne);
  cout<<"The integral of our function using the trapezoid method is: "<<area_curve<<endl;
  area_curve = 0;
  area_curve = simson_integration(a,b,n,&functionOne);
  cout<<"The integral of our function using the simpson method is: "<<area_curve<<endl;

  // I wish to observe how this scales with an increasing n value
  for(int n = 1; n < 2000; n++){
    double a = -1;
    double b = 1;
    if(n%100 == 0){
      trap_results.push_back(trap_integration(a,b,n,&functionOne));
      simp_results.push_back(simson_integration(a,b,n,&functionOne));
    }
  }
  cout<<"Trap integration"<<endl;
  print_Vector(trap_results);
  cout<<"--------------------------------------------------------------"<<endl;
  cout<<"Simp integration"<<endl;
  print_Vector(simp_results);

  return 0;
}
