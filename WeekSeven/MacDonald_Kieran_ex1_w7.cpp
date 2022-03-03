/*
Kieran MacDonald
Computational Physics
Profesor: Dr. Guzzi
02/24/2022
Goal: Write a C++ code that implements the cross product between two 3dim
vectors using classes and overloading operators as a member functions.
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

// A X B such that we find the resulting cross product of our two vectors
//The cross product order  matters

class Vec{

public:
  double arr[3];
  void setVec(double input[3]){
    for(int i = 0; i < 1; i++){
      arr[i] = input[i];
    }
  }
  Vec(){};

  Vec(double a[3]){
    for(int i = 0; i < 3; i++){
      arr[i] = a[i];
    }
  }

  Vec operator* (const Vec& parm){
    Vec temp;
    temp.arr[0] = (arr[1])*(parm.arr[2])-(parm.arr[1])*(arr[2]);
    temp.arr[1] = -1*((arr[0]*parm.arr[2])-(parm.arr[0]*arr[2]));
    temp.arr[2] = (arr[0]*parm.arr[1])-(parm.arr[0]*arr[1]);
    return temp;
  }
};

void user_input(double input[3]){
  double userInput = 0;
  for(int i = 0; i < 3; i++){
      std::cin>>userInput;
      input[i] = userInput;
  }
}


int main(){

double array_a[3];
double array_b[3];

std::cout<<"Please enter in your first 3-dimenstional array."<<std::endl;
user_input(array_a);
std::cout<<"Please enter in your second 3-dimenstional array."<<std::endl;
user_input(array_b);
Vec Vector1(array_a);
Vec Vector2(array_b);
Vec result;

result = Vector1.operator* (Vector2);

std::cout<<"result.arr[0] = "<<result.arr[0]<<", "<<"result.arr[1] = "<<result.arr[1]<<", "<<"result.arr[2] = "<<result.arr[2]<<std::endl;
std::cout<<"<"<<result.arr[0]<<", "<<result.arr[1]<<", "<<result.arr[2]<<">"<<std::endl;

return 0;
}
