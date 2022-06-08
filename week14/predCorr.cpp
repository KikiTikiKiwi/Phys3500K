#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>
#include"function.h"

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

Vec trap_pred_corrector(double t_f, double t_intitial, double y_initial, double n, double (*func)(double, double)){
  double f_n,y_bar,y,h = 0;
  Vec trap_pred_y;
  h = (t_f-t_intitial)/n;
  //cout<<"t_f: "<<t_f<<" t_i:" <<t_intitial<<" y_i"<<y_initial<<" n: "<<n<<endl;
  for(int k = 0; k < n; k++){
    f_n = func(t_intitial,y_initial);
    y_bar = y_initial + (h*f_n);
    y = y_initial + (0.5*h*(f_n + func(t_intitial+h,y_bar)));
    y_initial = y;
    t_intitial = t_intitial + h;
    trap_pred_y.push_back(y);
  }
  return trap_pred_y;
}
