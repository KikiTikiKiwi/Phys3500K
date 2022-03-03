/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
Feb 3, 2022
Goal: use pointers and pointer to pointers to
-calculate the trace of 3 by 3 matrix
-the product of the two 3 by 3 matrices A*B = C
-matrix elements must be entered by keyboard
*/

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

// Prompt User for matrix input
namespace user_prompt{
  void prompt_3d(int array[][4]){
    for(int r = 0; r < 3; r++){
      cout<<"Please enter in the coefficents of your equation."<<endl;
      for(int c = 0; c < 3; c++){
        cin>> array[r][c];
      }
    }
  }
}

//Function to calculate trace of matrix
//passing the address of the array in
int trace(int array[][4]){
  int sum = 0;
  int *p = &array[0][0];

  sum = *(p) + *(p+6) + *(p+9);
  return sum;
}

int main(){

  int array[3][4];
  user_prompt::prompt_3d(array);

  std::cout<<trace(array)<<std::endl;


  //int test = array[0][0];
  //std::cout<<test<<std::endl;

  //int array[3][3] = { {1,2,3}, { 4,5,6}, {7,8,9} };
  // Call trace function
  //std::cout<<trace(array)<<std::endl;
  return 0;
}
