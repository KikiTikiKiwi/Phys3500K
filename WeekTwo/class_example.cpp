
#include<iostream>
#include<string>
#include<cmath>
#include <typeinfo>

int main(){

  int array_example[] = {1,2,3,4,5};
  std::cout<<typeid(array_example).name()<<std::endl;

  return 0;
}
