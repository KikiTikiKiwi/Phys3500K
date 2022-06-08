/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
Feb 3, 2022
*/

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

namespace det{
  double two_by_two(double arr[][3]){
    double d = 0;
    d = ((arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1]));
    return d;
  }

  double three_by_three(double arr[][4]){
    double d = 0;
    double d1 = (arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2]);
    double d2 = (arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]);
    double d3 = (arr[1][0]*arr[2][1] - arr[2][0]*arr[1][1]);
    d = ((arr[0][0] * d1) - (arr[0][1] * d2) + (arr[0][2] * d3));
    return d;
  }
}

namespace two_dim_cram{
  double x = 0;
  double y = 0;
  void solve(double arr[][3]){
    x = ((arr[0][2]*arr[1][1]) - (arr[1][2]*arr[0][1]))/det::two_by_two(arr);
    y = ((arr[0][0]*arr[1][2]) - (arr[1][0]*arr[0][2]))/det::two_by_two(arr);
    std::cout<<"x:"<<x<<"y:"<<y<<std::endl;
  }
}

namespace three_dim_cram{
  double x = 0;
  double y = 0;
  double z = 0;
  void solve(double arr[][4]){
     x = ((arr[0][3]*(arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2])) - (arr[0][1]*(arr[1][3]*arr[2][2] - arr[2][3]*arr[1][2]))
      + (arr[0][2]*(arr[1][3]*arr[2][1] - arr[2][3]*arr[1][1])))/ det::three_by_three(arr);
     y = (arr[0][0]*(arr[1][3]*arr[2][2] - arr[2][3]*arr[1][2]) - (arr[0][3]*(arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]))
      + (arr[0][2]*(arr[1][0]*arr[2][3] - arr[2][0]*arr[1][3])))/ det::three_by_three(arr);
     z = ((arr[0][0]*(arr[1][1]*arr[2][3]-arr[2][1]*arr[1][3])) -  (arr[0][1]*(arr[1][0]*arr[2][3]-arr[2][0]*arr[1][3])) +
      (arr[0][3]*(arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1])))/det::three_by_three(arr);

    std::cout<<"Solution to x is: "<<x<<std::endl;
    std::cout<<"Solution to y is: "<<y<<std::endl;
    std::cout<<"Solution to z is: "<<z<<std::endl;
  }
}


namespace user_prompt{
  void prompt_3d(double array[][4]){
    for(int r = 0; r < 3; r++){
      cout<<"Please enter in the coefficents of your equation."<<endl;
      for(int c = 0; c < 4; c++){
        cin>> array[r][c];
      }
    }
  }

  void prompt_2d(double array[][3]){
    for(int r = 0; r < 2; r++){
      cout<<"Please enter in the coefficents of your equation."<<endl;
      for(int c = 0; c < 3; c++){
        cin>> array[r][c];
      }
    }
  }
}


int main(){
  int dim_count = 0;

  cout<<"How many dimensions does your equation have?"<<endl;
  cin>>dim_count;
  if(dim_count == 3){
    double array[3][4];
    user_prompt::prompt_3d(array);
    three_dim_cram::solve(array);
  }
  else if(dim_count == 2){
    double array[2][3];
    user_prompt::prompt_2d(array);
    two_dim_cram::solve(array);
  }
  else{
    cout<<"This program does not have the ability to do what you are asking."<<endl;
  }

  return 0;

}










/*
namespace tw_dim{
  double x;
  double y;
  double d;
  void crammer_rule(int arr[2][3]){
    x = ( (arr[0][2]*arr[1][1] - arr[1][2]*arr[0][1]) / (arr[0][2]*arr[1][1] - arr[1][2]*arr[0][1]) );
    std::cout<<x<<std::endl;
  }
  double determinant(int array[2][2]){
    d = ((array[0][2]*array[1][1] - array[1][2]*array[0][1]));
    return d;
  }
}


namespace three_dim{

  void crammer_rule(arr[][4]){
    int minor = arr[0][0];
    int r = 0;
    int c = 0; //keep zero
    int dummy_count_r = 0;
    int dummy_count_c = 0;

    int determinant_denom = 0;

    dummy_array[2][2];
    for(r = 0; r < 3; r++){
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++ ){
          if(i != r && j != c){
            dummy_array[dummy_count_r][dummy_count_c] = arr[i][j];
          }
          ++dummy_count_c;
        }
        ++dummy_count_r;
      }
      determinant_denom = (minor * tw_dim::determinant(dummy_array)) + determinant_denom;
      minor = arr[0][0+r]
    }
    std::cout<<determinant_denom<<std::endl;
  }



}

int main(){

  int arr[2][3] = {{1,2,4}, {3,7,5}};
  tw_dim::crammer_rule(arr);



  return 0;
}
*/
