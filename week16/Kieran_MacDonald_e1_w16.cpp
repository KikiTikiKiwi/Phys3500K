// dftcs - Program to solve the diffusion equation
// using the Forward Time Centered Space (FTCS) scheme.
#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

#define Ngrid 101
#define Ntau 3000


int main(void)
{

int i,j,m;
//* Initialize parameters (time step, grid spacing etc.).
double xmin=0.;
double xmax=1.0;
double tmin=0.;
double tmax=3.5;

double T0=100.; //Kelvin

double Dt =(tmax-tmin)/Ntau; //time step
double Dx =(xmax-xmin)/Ngrid; //time step
double kappa = 237.; // conductivity
double sph = 900.; //specific heat
double rho = 2700.; // density
double cons = kappa/sph/rho*Dt/Dx/Dx; //Constant
//Arrays for the 2D x-t grid
double T[Ngrid+1][Ntau+1]={0.};
double Tpl[Ngrid+1][Ntau+1]={0.};
double x[Ngrid+1]={0.};
double t[Ntau+1]={0.};

for (i=0; i<=Ngrid;i++ )
   x[i] = Dx*i + xmin;

for (j=0; j<=Ntau;j++)
    t[j] = j*Dt + tmin;


//Set initial condition for the temperature distribution T_{ij}
   for (i=1; i<Ngrid;i++)
       T[i][0] = T0; //Initial temp.

//We set the initial and final points to 0 for compatibility
//of boundary conditions at the extremal points
       T[0][0] = 0.;
       T[0][Ntau] = 0.;
       T[Ngrid][0] = 0.;
       T[Ngrid][Ntau] = 0.;

//Set boundary conditions for the temperature distribution T_{ij}
          for (j=1; j<Ntau;j++)
          {
              T[0][j] = 0.;
              T[Ngrid][j] = 0.;
          }

  for (j=0; j<Ntau;j++)
     for (i=1; i<Ngrid;i++ )
        {
           T[i][j+1] = T[i][j] + cons*(T[i+1][j] + T[i-1][j] - 2.0*T[i][j]);
           T[i][j] = T[i][j+1];
         }

 T[Ngrid][0]=T[Ngrid][Ntau]=0.;

cout<< " time step " << " " << "x_i" << " "<< "t_j" << " "<< "T(x_i,t_j)"<<endl;
for (j=0; j<=Ntau;j++)
      for (i=0; i<=Ngrid;i++ )
          cout<< "j = " << j << " "<< x[i] << " "<< t[j] << " "<< T[i][j] <<endl;


}
