/*
Student: Kieran MacDonald
Proffesor: Dr.Guzzi
Class: Computational Phsyics 3500k
Assignment: 11 example two
Goal: Write a C++ code to convert the pseudo code below to a real code for the
Trapezoid predictor-corrector method. Use it to validate the previous example
in y(1). See if you can reproduce the table below.
*/

#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

void print_Vector(Vec vec){
  int sizeV = vec.size();
  for(int i = 0; i < sizeV; i++){
    cout<<vec[i]<<endl;
  }
}

void print_table(Vec err, Vec res){
  int sizeR = res.size();
  cout<<"N"<<"|   "<<"Yn"<<"   | "<<"Error"<<endl;
  cout<<"___________________________"<<endl;
  for(int i = 0; i < sizeR; i++ ){
    cout<<i<<"|"<<res[i]<<"|"<<err[i]<<"|";
    cout<<endl;
  }
}

double functionOne(double t, double y){
  double f = 0;
  f = -y - pow(y,2);
  return f;
}

double y_func(double t){
  double y = 1/(exp((t/10)+log(3/2))-1);
  return y;
}

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

int main(){
  // y' = -y*log(y), y(0) = 1/2
  Vec pred_results;
  Vec exact_results;
  Vec pred_error;
  Mat chart;
  double t_f = 5;
  double t_i = 0;
  double y_i = 2;
  double n = 20;
  double h  = (t_f-t_i)/n;
  //trap_pred_corrector(t_f, t_i, y_i, n, &functionOne);
  pred_results = trap_pred_corrector(t_f, t_i, y_i, n, &functionOne);

  for(int i = 0;i < n; i++){
    exact_results.push_back(y_func(i+1));
  }

  for(int i = 0; i < n; i++){
    pred_error.push_back(abs((pred_results[i] - exact_results[i])));
  }
  // chart.push_back(pred_results);
  // chart.push_back(pred_error);
  //print_Vector(exact_results);
  print_table(pred_error,pred_results);
  //print_matrix(chart);

  return 0;
}
