#include<iostream>


int main(){

  int arr[] = {0,1,2,3,4,5};

  int *p = arr; //p points to the first element in arr
  ++p; // p points to arr[1]

  int *e = &arr[4];

  for(int *b = arr; b != e; ++b){
    std::cout<<*b<<std::endl;
  }

  return 0;
}
