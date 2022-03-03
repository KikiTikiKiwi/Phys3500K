/*
Kieran MacDonald
Computational Physics
Dr. Guzzi
2/24/22
Goal: Write a C++ code that uses classes to calculate the area of
1. Regular Hexagon (the radius of inner circle is r)
2. Parallelepiped (length=L, width=W, height=H)
*/

#include<iostream>
#include<cmath>

class Parallelepiped{
  double length;
  double width;
  double height;
public:
  Parallelepiped(double, double, double);
  void setParallelepiped(double, double, double);
  double surfaceArea();
};
Parallelepiped::Parallelepiped(double l, double w, double h){
   length = l;
   width = w;
   height = h;
}
void Parallelepiped::setParallelepiped(double l, double w, double h){
  length = l;
  width = w;
  height = h;
}

double Parallelepiped::surfaceArea(){
  return (2*(length*height)+2*(length*width)+2*(width*height));
}

class Hexagon{
  double radius;
public:
  Hexagon(double);
  void setHexagon(double);
  double area();
};

Hexagon::Hexagon(double r){
  radius = r;
}

void Hexagon::setHexagon(double r){
  radius = r;
}

double Hexagon::area(){
  return (6*tan(3.14/6))*(radius*radius);
}

int main(){
  Hexagon obj(2);
  std::cout<<"--The area of a hexagon with a radius of 2 is "<<obj.area()<<"--"<<std::endl;
  Parallelepiped obj2(1,2,3);
  std::cout<<"--The surface area of a Parallelepiped with dimensions of l = 1, w = 2 and h = 3, is "<<obj2.surfaceArea()<<std::endl;
  return 0;
}
