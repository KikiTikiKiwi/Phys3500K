/*
Kieran MacDonald
PHYS 3500K
DR.Guzzi
1/27/2022
Objective: Write a code which calculates (a+b)^n
*/

#include<iostream>
#include<string>
#include<cmath>

// Initilize factorial function
double factorial_func(int n, int k = 0){
  if(n > 1 && k == 0){
    return (n * factorial_func(n-1));
  }
  else if(n > 1 && k > 0 && n != k){
    return (((n-k) * factorial_func((n-k)-1) * factorial_func(k))); //made edit
  }
  else if(n > 1 && k > 0 && n == k){
    return (k * factorial_func(k-1));
  }
  else{
    return 1; // don't change
  }
}

// Initilize binomial coefficent function
double binomial_coefficent_func(int nth_power, int k){
  int numerator = 0;
  int denom = 0;
  if(nth_power == 0){
      return 1;
  }
  else if(nth_power > 0){
    numerator = factorial_func(nth_power);
    denom = factorial_func(nth_power,k);
  }
  else{
    return -1; //This means an error in my code
  }
  return (numerator/denom);
}

// Initilize general form of binomial exspansion
// Goal is to express my binomail as a polynomail if given just variable names
// If given digits for variables then still express my polynomail with digits
// Finally after expressing the general form, give an answer
template <class T, class U>
T general_form(T a, T b, U c){
  T binomial;
  double dummy_c = c;
  double answer = 0;
  for(int i = 0; i <= c; i++){
    if(i != c){
      std::cout<<binomial_coefficent_func(c,i)<<"a^"<<dummy_c<<"b^"<<i<<" + ";
      answer = answer + (binomial_coefficent_func(c,i) * pow(a,dummy_c) * pow(b,i));
    }
    else{
      std::cout<<binomial_coefficent_func(c,i)<<"a^"<<dummy_c<<"b^"<<i<<std::endl;
      answer = answer + (binomial_coefficent_func(c,i) * pow(a,dummy_c) * pow(b,i));
      std::cout<<"The final answer is: "<<answer<<std::endl;
    }
    --dummy_c;
  }
  return 0;
}

/*template <class T, class U>
T user_prompt(T x, T y, U n){
  std::cout<<"Please enter x variable, y variable, and the power for your binomial expansion."<<std::endl;
  std::cin>>x;
  std::cin>>y;
  std::cin>>n;
  return 0;
} */

int main(){
  int n;
  double x;
  double y;

  std::cout<<"Please enter x variable, y variable, and the power for your binomial expansion."<<std::endl;
  std::cin>>x;
  std::cin>>y;
  std::cin>>n;

  general_form(x,y,n);
  return 0;

}
