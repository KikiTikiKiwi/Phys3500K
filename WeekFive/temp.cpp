#include <iostream>
#include <string>
using namespace std;

int main(){
  string x = "bye";
  while(x != "hi"){
    cout << "Say hi" << endl;
    cin >> x;
  }
}
