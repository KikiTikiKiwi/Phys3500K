/*
Student: Kieran MacDonald
Class: Computational physics 3500K
Prof: Dr.Guzzi
Assignmet: Test Three
Date Due: April 21, 2022
Objective: Take the Trapezoid predictor-corrector method of Ex2 HW11.
Restructure this code by implementing it in terms of header files and multiple
source files. Write a makefile to compile according to CASE 4.
*/

#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>
#include"function.h"
#include"predCorr.h"

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
