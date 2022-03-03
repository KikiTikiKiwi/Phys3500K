/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
Feb 10, 2022
Objective: Write a C++ code that uses pointers to functions to perform vector
rotations in the 2dim plane. Initial vector and rotation angle are passed by
 keyboard.
*/

#include<iostream>
#include<string>
#include<cmath>
#include<sstream>

using namespace std;

struct Vect{
    double vector[2][1];
};

// Why didn't i have comments explaining what this struct is
// a rotation - so an angle and a 2x2 Matrix
struct RotMatrix{
  double angleRad;
  double angleDeg;
  double matrixRad[2][2];
  double matrixAng[2][2];
};

// Objective of function is to fill my initial vector and to set my rotation matrix
void set_Vec(Vect * v){
  std::cout<<"Please Enter your vector"<<std::endl;
  std::cin>>v->vector[0][0];
  std::cin>>v->vector[1][0];
  std::cout<<endl;
}

void set_RotM(RotMatrix * r){
  std::cout<<"Please Enter your rotation angle (radians)"<<std::endl;
  std::cin>>r->angleDeg;
   r->angleRad = ((r->angleDeg * M_PI)/180);

  r->matrixRad[0][0] = cos(r->angleRad);
  r->matrixRad[0][1] = -sin(r->angleRad);
  r->matrixRad[1][0] = sin(r->angleRad);
  r->matrixRad[1][1] = cos(r->angleRad);
}

//initial two conditions: angle and vector
void rotation(Vect v, RotMatrix r){
  // Want to do (2 by 2) X (2 by 1)
  // row, col, rp
    double result[2];
    result[0] = r.matrixRad[0][0]*v.vector[0][0] + r.matrixRad[0][1]*v.vector[1][0];
    result[1] = r.matrixRad[1][0]*v.vector[0][0] + r.matrixRad[1][1]*v.vector[1][0];
    if(result[0] < 0.000001){
      result[0] = 0;
    } else if(result[1] < 0.000001){
      result[1] = 0;
    }
    cout<<"Rotated vector point: <"<<result[0]<<","<<result[1]<<">"<<endl;
}

void operation(Vect vec, RotMatrix matrix, void(*function)(Vect, RotMatrix)){
  (*function)(vec, matrix);
}

int main(){
  Vect a_vector;
  Vect * a_vector_ptr = &a_vector;
  RotMatrix a_rotMatrix;
  RotMatrix * a_rotMatrix_ptr = &a_rotMatrix;

  //user prompt set func
  set_Vec(a_vector_ptr);
  cout<<"vector: "<<a_vector.vector[0][0]<<","<<a_vector.vector[1][0]<<endl;
  set_RotM(a_rotMatrix_ptr);
  cout<<"Rotation Matrix:"<<endl;
  cout<<a_rotMatrix.matrixRad[0][0]<<endl;
  cout<<a_rotMatrix.matrixRad[0][1]<<endl;
  cout<<a_rotMatrix.matrixRad[1][0]<<endl;
  cout<<a_rotMatrix.matrixRad[1][1]<<endl;
  cout<<"Angle(rad): "<<a_rotMatrix.angleRad<<endl;
  cout<<"Angle(deg): "<<a_rotMatrix.angleDeg<<endl;
  cout<<"vector: "<<a_vector.vector[0][0]<<","<<a_vector.vector[1][0]<<endl;
  void (*rot)(Vect,RotMatrix) = rotation;
  operation(a_vector, a_rotMatrix, rot);
  return 0;
  //operation(a_vector.vector, a_rotMatrix.matrix, rotation);

}
