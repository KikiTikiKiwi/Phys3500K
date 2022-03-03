/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Rewrite the exercises 1. and 2. using for loops.
*/

#include<iostream>
#include<string>
#include<cmath>


int main(){

// for-loop that will sum the numbers 50 to 100
int answer  = 0;
for(int i = 50; i <= 100; i++){
  answer = i + answer;
  if(i == 100){
    std::cout<<"sum of 50 to 100 using for-loop: "<<answer<<std::endl;
  }
}

//for-loop for the decrement operation printing doen from 10 to 0
for(int i = 10; i >= 0; i--){
  if(i == 0){
    std::cout<<i<<std::endl;
    break;
  }
  std::cout<<i<<",";
}


  return 0;
}
