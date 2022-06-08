#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<fstream>

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

double B_squared = 1;

double linear(double theta, double omega, double t0){
  double deriv = -(theta);
  return deriv;
}
// d0/dt
double theta_pos (double t, double theta, double theta_vel){
	return (theta_vel);
}
// dw/dt
double theta_vel( double t, double theta, double theta_vel){
  double result, l, g;
	g = 9.8;
  l = 9.8; // make my w^2 = 1
  result = -g/l*sin(theta);
  return result;
}



int main(){
  Vec a = {0.01, 0.2, 0.5, 0.9, 0.99}; //change these as needed
  double h, j1a, j2a, j1b, j2b, k1a, k1b, k2a, k2b, k3a, k3b, k4a, k4b, theta, theta2, omega, omega2, t, t2;
  int n;
  h=0.05;
  n=1000;



  ofstream myfile;
  for(int i = 0; i < a.size(); i++){
    string fileName = "pendData" + to_string(i)+ ".txt";
    cout<<fileName<<endl;
    myfile.open(fileName);
    t = 0;
    t2 = 0;
    theta = a[i] * M_PI;
    theta2 = a[i] * M_PI;
    omega = 0;
    omega2 = 0;

    for(int j=1;j<=n;j++){
      //Linear 2nd order runge kutta
      j1a=h*omega;
      j1b=h*linear(theta,omega,t);
      j2a=h*(omega+j1b);
      j2b=h*linear(theta+j1a,omega+j1b,t+h);
      theta = theta + (j1a + j2a)/2;
      omega = omega + (j1b+j2b)/2;
      t=t+h;

      // Non Linear 4th runge kutta
      k1a = h*theta_pos(t2,theta2,omega2);
      k1b = h * theta_vel(t2,theta2,omega2);
      k2a = h*(theta_pos(t2,theta2,omega2)+(k1b/2));
      k2b = h * theta_vel(t2+(h/2),theta2+(k1a/2),omega2+(k1b/2));
      k3a = h *(theta_pos(t2,theta2,omega2)+(k2b/2));
      k3b = h * theta_vel(t2+(h/2),theta2+(k2a/2),omega2+(k2b/2));
      k4a = h*(theta_pos(t2,theta2,omega2)+(k3b));
      k4b = h * theta_vel(t2+h,theta2+k3a,omega2+k3b);
      theta2 = theta2 + (k1a + 2*k2a + 2*k3a + k4a)/6;
      omega2 = omega2 + (k1b+ 2*k2b + 2*k3b + k4b)/6;
      t2 = t2+h;

      if(n%10 == 0){
        myfile<<theta<<" "<<t<<" "<<theta2<<" "<<t2<<"\n";
      }
    }
    myfile.close();
  }
  // How do we evalute frequency of a linear vs Nonlinear pendulum? Also time period?
  return 0;
}






// linear

/*
for(int i=1;i<=n;i++){
  k1a=h*omega;
  k1b=h*linear(theta,omega,t);
  k2a=h*(omega+k1b);
  k2b=h*linear(theta+k1a,omega+k1b,t+h);
  theta = theta + (k1a + k2a)/2;
  omega = omega + (k1b+k2b)/2;
  t=t+h;
  if(n%10 == 0){
    myfile <<theta<<" "<<t<<"\n";
  }
}

*/


/*

double omega2,theta2,t2;
theta2= 120*(3.14/180); //will give angle in radians
omega2=0; //initial velocity is zero
t2=0; // time starts at 0

for(int i = 1; i<=n; i++){

  k1a = h*theta_pos(t2,theta2,omega2);
  k1b = h * theta_vel(t2,theta2,omega2);
  k2a = h*(theta_pos(t2,theta2,omega2)+(k1b/2));
  k2b = h * theta_vel(t2+(h/2),theta2+(k1a/2),omega2+(k1b/2));
  k3a = h *(theta_pos(t2,theta2,omega2)+(k2b/2));
  k3b = h * theta_vel(t2+(h/2),theta2+(k2a/2),omega2+(k2b/2));
  k4a = h*(theta_pos(t2,theta2,omega2)+(k3b));
  k4b = h * theta_vel(t2+h,theta2+k3a,omega2+k3b);

  theta2 = theta2 + (k1a + 2*k2a + 2*k3a + k4a)/6;
  omega2 = omega2 + (k1b+ 2*k2b + 2*k3b + k4b)/6;
  t2 = t2+h;
  myfile <<theta2<<" "<<t2<<"\n";
}
*/

























/*
  for(int i = 1; i<=n; i++){
    k1a = -h*omega2;
    k1b = h * funcT(theta2,omega2,t2);
    k2a = -h*(omega2+(k1b/2));
    k2b = h * funcT(theta2+(k1a/2),omega2+(k1b/2),t2+(h/2));
    k3a = -h *(omega2+(k2b/2));
    k3b = h * funcT(theta2+(k2a/2),omega2+(k2b/2),t2+(h/2));
    k4a = -h*(omega2+(k3b));
    k4b = h * funcT(theta2+k3a, omega2+k3b, t2+h);

    theta2 = theta2 + (k1a + 2*k2a + 2*k3a + k4a)/6;
    omega2 = omega2 + (k1b+ 2*k2b + 2*k3b + k4b)/6;
    t2 = t2+h;
    myfile <<theta2<<" "<<t2<<"\n";
  }
  myfile.close();
  return 0;
}

*/










/* double Beta = 2;
double omega = 1;
double theta0 = 3.14;
double t = 0;
double h_grid = 0.1;

void fork(double theta, double w, double t, double h, int nth, double(*func)(double, double, double), Vec& sol_theta, Vec& sol_omega){}
void funOne(double theta, double w, double t){}

int main(){

  Vec theta_sol;
  Vec omgea_sol;
  double nth = 30;
  fork(theta0, omega, 0, h_grid, nth, &funOne, theta_sol, omgea_sol);

  return 0;
}

// d/dt(theta) = w
// d/dt (w) = B^2 sin(thet)

double funOne(double theta, double w, double t){
  return -(Beta*Beta * (sin(theta)));
}

// fork stands for fourth order runge kutta
void fork_double_pend(double theta, double w, double t, double h, int nth, double(*func)(double, double, double), Vec& sol_theta, Vec& sol_omega){
  double k1,k2,k3,k4,l1,l2,l3,l4;
  for(int i = 1; i<=nth; i++){
    k1 = h*w;
    l1 = h * func(theta,w,t);
    k2 = h*(w+(l1/2));
    l2 = h * func(theta+(k1/2),w+(l1/2),t+(h/2));
    k3 = h *(w+(l2/2));
    l3 = h * func(theta+(k2/2),w+(l2/2),t+(h/2));
    k4 = h*(w+(l3));
    l4 = h * func(theta+k3, w+l3, t+h);
    theta = theta + (k1 + 2*k2 + 2*k3 + k4)/6;
    w = w + (l1 + 2*l2 + 2*l3 + l4)/6;
    t = h*(i-1);
    sol_theta.push_back(theta);
    sol_omega.push_back(w);
//     theta = theta + (k1a + k2a)/2;
// omega = omega + (k1b+k2b)/2; t=t+h;
  }
}
*/
