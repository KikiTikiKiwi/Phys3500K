/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Use the decrement operator to write a while that prints the numbers from ten down to zero.
*/

#include<iostream>
#include<string>
#include<cmath>

int main(){

  int n = 10;
  while(n >=0){
    std::cout<<n<<",";
    --n;
  }


  return 0;
}
