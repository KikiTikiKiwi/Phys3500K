/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Write a program that prompts the user for two integers. Print each number in
           the range specified by those two integers
*/

#include<iostream>
#include<string>
#include<cmath>

int main(){

  int a;
  int b;

  std::cout<<"please enter in two numbers to find the numbers between them."<<std::endl;
  std::cin>>a;
  std::cin>>b;

  if(a > b){
    for(int i = b+1; i < a; i++){
      std::cout<<i<<","<<std::endl;
    }
  }
  else if(b > a){
    for(int i = a+1; i < b; i++){
      std::cout<<i<<","<<std::endl;
    }
  }
  else{
    std::cout<<"The number range entered has no numbers between them."<<std::endl;
  }


  return 0;
}
