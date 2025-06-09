#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
//3025=(30+25)^2  4575
bool sumPow(int abcd){
  int primero, segundo;
  primero=abcd/100;
  segundo=abcd%100;
  if((primero+segundo)*(primero+segundo)==abcd)
    return true;
  return false;
}

int main(int argcu, char* argd[]){
  for(int i=1000;i<stoi(argd[1]);i++){
    if(sumPow(i))
      cout<<i<<" ";    
  }  
  
  return 0;
}
