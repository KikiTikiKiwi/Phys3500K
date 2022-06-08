/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Write a program that uses a while-loop to sum the numbers from 50 to 100.
*/

#include<iostream>
#include<string>
#include<cmath>

int main(){

  int n = 50;
  int answer = 0;
  while(n <= 100){
     answer = answer+n;
     n = n+1;
  }

  std::cout<<answer<<std::endl;

  return 0;
}
