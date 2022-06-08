/*
-----------------------------------------------------------------------------
Kieran Macdonald
Computational Physics 1
Dr.Guzzi
Due:March 15

Goal 1: Write a program that uses the secant method to find the root
of a given function on a given interval, and apply this program
to find the roots of the functions below on the indicated intervals

Goal 2: In the same code, implement the numerical derivative for function 1. of
problem 1. by using the 5-point stencil method. Use point x=1
-----------------------------------------------------------------------------
*/


#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


double functionOne(double x){
  double y;
  y = x + cos(x) + exp(x);
  return y;
}

double functionTwo(double x){
  double y;
  y = pow(x,2) - sin(x);
  return y;
}

double derivative(double (*func)(double), double h, double x){
  double der = ((-1*func(x+2*h) + (8*func(x+h)) + (-1*8*func(x-h)) + func(x-2*h))/(12*h));
  return der;
}

vector<double> bisectionMethod(double (*func)(double), double acc, vector<double> bounds){
  //vector<double> bounds = vect; // Bounds will be a and b
  double c = 0;
  // lets first determine the amount of iterations needed "n" from our wanted accuracy
  // n >= (log(b-a))-log(acc))/log(2)
  int n = 0;
  n = ((log10(bounds[1]-bounds[0]) - log10(acc)))/log10(2);
  // Step through the algoitim for bisecting method, updating bounds at the end of the loop each time.
  for(int i = 0; i < n; i++){
    //compute c = a + 1/2(b-a)
    c = bounds[0]+ 0.5*(bounds[1]-bounds[0]);
    //determine which is negative f(c) times f(a) or f(c) times f(b)
    if(func(c)*func(bounds[0]) < 0){
      //a of nth iteration +1  is equal to a
      //b of nth iteration +1 is equal to c
      bounds[1] = c;
    }
    else if(func(c)*func(bounds[1])<0){
      bounds[0] = c;
    }
    // If it gets it right the first try
    else if( (func(c)*func(bounds[0] && func(c)*func(bounds[1]))) == 0){
      bounds[0] = c;
      bounds[1] = c;
    }
  }
  bounds.push_back(n);
  return bounds;
}


vector<double> SecantMethod(double (*func)(double), double acc, vector<double> x_Subscript_N){ // Where iteration is X n and X n+1 and X n+2 so on, acting as a record kepper whcih one can acces for computational purposes

  int n = 1;
  double x_r = 0;
  vector<double> answer;

  double x_N;
  double x_N_Minus;
  double func_x_N;
  double func_x_N_minus;
  double b;
  double c;

  bool condition = true;

  // We will need two intial guesses, X of subscript n and X of subscript n-1

  while(condition){
    x_N = x_Subscript_N[n];
    x_N_Minus = x_Subscript_N[n-1];
    func_x_N = func(x_N);
    func_x_N_minus = func(x_N_Minus);

    b = (x_N - x_N_Minus);
    c = (func_x_N - func_x_N_minus);
    x_Subscript_N.push_back(x_N  - (func_x_N * (b/c)));
    n = n + 1;
    if(n >= 100){
      cout<<"There is risk of segmentation fault"<<endl;
      break;
    }
    if(abs(x_Subscript_N[n] - x_Subscript_N[n-1]) <= acc){
      condition = false;
    }
  }
  answer.push_back(x_Subscript_N[n]);
  answer.push_back(n);

  return answer;
}


int main(){

  double acc = 0.01;
  double x = 0;
  vector <double> intial_X_Guess(2);
  vector<double> estimatedZeroBounds(3);
  vector<double> answerSecant;

  cout<<"We will be using the secant method and the bisection method on function one. "<<"Our end conditon will meet an accuracy of "<<acc<<" between the bounds of -1 and 1 being our initial guess."<<endl;

  cout<<"Enter first guess for function one"<<endl;
  cin>>intial_X_Guess[0];
  cout<<"Enter second guess"<<endl;
  cin>>intial_X_Guess[1];

  estimatedZeroBounds = bisectionMethod(&functionOne,acc,intial_X_Guess);
  answerSecant = SecantMethod(&functionOne,acc,intial_X_Guess);

  cout<<"Our final root aproximation of function one using the Secant Mehtod is: "<<answerSecant[0]<<endl;
  cout<<"Our final root aproximation of function one using the bisection method is between the bounds: ["<<estimatedZeroBounds[0]<<","<<estimatedZeroBounds[1]<<"]"<<endl;
  cout<<"The secant iteration count: "<<answerSecant[1]<<endl;
  cout<<"The bisection iteration count: "<<estimatedZeroBounds[2]<<endl;

  // FUNCTION TWO IS NEXT
  cout<<"---------------------------------------------------------------------------------------------"<<endl;

  cout<<"We will be using the secant method and the bisection method on function two. "<<"Our end conditon will meet an accuracy of "<<acc<<" between the bounds of 0 and PI being our initial guess."<<endl;

  cout<<"Enter first guess for function two"<<endl;
  cin>>intial_X_Guess[0];
  cout<<"Enter second guess for function two"<<endl;
  cin>>intial_X_Guess[1];

  estimatedZeroBounds = bisectionMethod(&functionTwo,acc,intial_X_Guess);
  answerSecant = SecantMethod(&functionTwo,acc,intial_X_Guess);

  cout<<"Our final root aproximation of function one using the Secant method is: "<<answerSecant[0]<<endl;
  cout<<"Our final root aproximation of function one using the bisection method is between the bounds: ["<<estimatedZeroBounds[0]<<","<<estimatedZeroBounds[1]<<"]"<<endl;
  cout<<"The secant iteration count: "<<answerSecant[1]<<endl;
  cout<<"The bisection iteration count: "<<estimatedZeroBounds[2]<<endl;

  cout<<"---------------------------------------------------------------------------------------------"<<endl;
  cout<<"Calculate the derivative of function one at a point of your choose"<<endl;
  cin>>x;
  cout<<derivative(functionOne,acc,x)<<endl;;


  return 0;
}
