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
    c = bounds[0]+ (0.5*(bounds[1]-bounds[0]));
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
  return bounds;
  cout<<"number of iterations: "<<n<<endl;
}

int main(){
  double acc = 0.001;
  vector <double> ab_bound = {-1,1};
  vector<double> estimatedZeroBounds(2);

  estimatedZeroBounds = bisectionMethod(&functionOne,acc,ab_bound);
  cout<<"A root of function one with an accuarcy of "<<acc<<", is between the points of ["<<estimatedZeroBounds[0]<<","<<estimatedZeroBounds[1]<<"]"<<endl;

  ab_bound = {0,3.14};
  estimatedZeroBounds = bisectionMethod(&functionTwo,acc,ab_bound);
  cout<<"A root of function two with an accuarcy of "<<acc<<", is between the points of ["<<estimatedZeroBounds[0]<<","<<estimatedZeroBounds[1]<<"]"<<endl;
  return 0;
}
