/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
<Objective>: Write a C++ code that:
• uses the namespace functionality to define a function that calculates both scalar product and
cross product between two 3-dim vectors whose components are inserted by keyboard.
• The two vectors must now be passed as arrays.
• The code must print on the screen the value of the dot product and the components of the cross product.
*/

#include<iostream>
#include<cmath>
#include<string>

namespace dot{
  double scaler_value;
  void product(double v1[], double v2[]){
    //((x1*x2) + (y1*y2) + (z1*z2));
    scaler_value = ((v1[1]*v2[1]) + (v1[2]*v2[2]) + (v1[3]*v2[3]));
  }
}

namespace cross{
  double cross_vector[3] = {0,0,0};
  void product(double v1[3], double v2[3]){
    //(y1*z2)-(y2*z1))<<", "<< ((x2*z1)-(x1*z2))<<", "<<((x1*y2)-(x2*y1
    cross_vector[0] = (v1[1]*v2[2] - v2[1]*v1[2]);
    cross_vector[1] = (v2[0]*v1[2]-v1[0]*v2[2]);
    cross_vector[2] = (v1[0]*v2[1]-v2[0]*v1[1]);
  }
}

void user_input(double* v1, double* v2){
  for(int i = 0; i < 2; i++){
    std::cout<<"Enter the componets for vector: "<<i+1<<std::endl;
    for(int j = 0; j < 3; j++){
      std::cout<<"Enter in component "<<j<<std::endl;
      if(i == 0){
        std::cin>>v1[j];
      }
      else if(i == 1){
        std::cin>>v2[j];
      }
      else{
        std::cout<<"user_input function went to last else statement"<<std::endl;
      }
    }
  }

}

int main(){

  double vector_one[3];
  double vector_two[3];

  //the user input function then has the parameters passed in point back to the origional var
  user_input(vector_one, vector_two);

  dot::product(vector_one, vector_two);
  cross::product(vector_one, vector_two);

  std::cout<<"The dot product of the two vectors is: "<< dot::scaler_value<<std::endl;
  std::cout<<"The cross product of the two vectors is: <";
    for(int i = 0; i < 3; i++){
      if(i != 2){
        std::cout<<cross::cross_vector[i]<<", ";
      }
      else{
        std::cout<<cross::cross_vector[i]<<">"<<std::endl;
      }
    }


  return 0;

}
