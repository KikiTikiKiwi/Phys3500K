#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>
#include"function.h"

double functionOne(double t, double y){
  double f = 0;
  f = -y - pow(y,2);
  return f;
}

double y_func(double t){
  double y = 1/(exp((t/10)+log(3/2))-1);
  return y;
}
