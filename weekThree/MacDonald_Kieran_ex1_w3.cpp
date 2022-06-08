/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
<Objective>: Write a C++ code that uses the namespace functionality to define a
function that calculates both scalar product and cross product between two
3-dim vectors whose components are given as an input using the keyboard.
The code must print on the screen the value of the dot product and the
components of the cross product.
*/

#include<iostream>
#include<cmath>
#include<string>

namespace dot{
  double scaler_value = 0;
  void product(double x1, double y1, double z1, double x2, double y2, double z2){
    scaler_value = ((x1*x2) + (y1*y2) + (z1*z2));
    std::cout<<scaler_value<<std::endl;
  }
}

namespace cross{
  void product(double x1, double y1, double z1, double x2, double y2, double z2){
    std::cout<<"cross product: "<<"<"<<((y1*z2)-(y2*z1))<<", "<< ((x2*z1)-(x1*z2))<<", "<<((x1*y2)-(x2*y1))<<">"<<std::endl;
  }
}


int main(){
  double x1 = 0;
  double y1 = 0;
  double z1 = 0;

  double x2 = 0;
  double y2 = 0;
  double z2 = 0;

  std::cout<<"Please enter in the x, y, z components for vector one."<<std::endl;
  std::cin>> x1;
  std::cin>> y1;
  std::cin>> z1;
  std::cout<<"Please enter in the x, y, z components for vector two."<<std::endl;
  std::cin>> x2;
  std::cin>> y2;
  std::cin>> z2;

  std::cout<<"The cross product of the two vectors is: ";
  cross::product(x1, y1, z1, x2, y2, z2);
  std::cout<<"The dot product of the two vectors is: ";
  dot::product(x1, y1, z1, x2, y2, z2);

  return 0;
}
