/*
Kieran MacDonald
Computational Physics
Dr. Guzzi
2/24/22
Goal:Write a C++ code that uses classes with constructors to determine the volume
of the parallelepiped below. Vectors 𝑤, 𝑣⃗, 𝑢 are defined as:
𝑤 = (1.5,3.7,9.1), 𝑣⃗ = (5.6,7.3,8.9),
𝑢 = 2.1,3.2,4.5 .
V = | ( ~u ⇥ ~v ) · w~ |
*/

#include<iostream>
#include<cmath>

/*
class Vector{
public:
  double array[3];
  Vector(double arr[]){
    for(int i = 0; i < 3; ++i)
        array[i] = arr[i];
  }
}; */

class Parallelepiped{
  //Vector vector1;
  //Vector vector2;
  //Vector vector3;
  double vec[3];
  double vec2[3];
  double vec3[3];

  double detMatrix[3][3];
public:
  double volume;
  Parallelepiped(double a[], double b[], double c[]){

    for(int i = 0; i < 3; ++i){
        vec[i] = a[i];
        vec2[i] = b[i];
        vec3[i] = c[i];
    }
  }

  void volumeCalc(){
    for (int j = 0; j < 3; j++){
      detMatrix[0][j] = vec[j];
      detMatrix[1][j] = vec2[j];
      detMatrix[2][j] = vec3[j];
    }
    double d1 = (detMatrix[1][1]*detMatrix[2][2] - detMatrix[2][1]*detMatrix[1][2]);
    double d2 = (detMatrix[1][0]*detMatrix[2][2] - detMatrix[2][0]*detMatrix[1][2]);
    double d3 = (detMatrix[1][0]*detMatrix[2][1] - detMatrix[2][0]*detMatrix[1][1]);
    volume = ((detMatrix[0][0] * d1) - (detMatrix[0][1] * d2) + (detMatrix[0][2] * d3));

 }

};

int main(){
  // Define my vectors in my system
  double tempArr1[3] = {1.5,3.7,9.1};
  double tempArr2[3] = {5.6,7.3,8.9};
  double tempArr3[3] = {2.1,3.2,4.5};

  // Assuming my three vectors are linearly independant the Parallelepiped will
  // Have a geometry to it
  // And a determinant
  Parallelepiped obj1(tempArr1, tempArr2, tempArr3);
  obj1.volumeCalc();

  std::cout<<"The Volume of your Parallelepiped is: "<<obj1.volume<<" units"<<std::endl;

  return 0;
}
