/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Write a code using bitwise logic operators that checks if an integer is even or odd.
(Hint: Use the & bitwise operator)
*/

#include<iostream>
#include<string>
#include<cmath>

int main(){

  int number = 0;
  std::cout<<"Please enter a number."<<std::endl;
  std::cin>>number;

  if((number & 1) == 1){
    std::cout<<"The number is odd"<<std::endl;
  }
  else if((number & 1) == 0){
    std::cout<<"The number is even"<<std::endl;;
  }
  else{
    std::cout<<"Soemthing went wrong"<<std::endl;
  }


  return 0;
}
