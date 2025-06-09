#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
//3025=(30+25)^2  4575
bool capicua(char num[]){
  int a=stoi(num);
  int b, r=0, n;
  int c=1;
  for(int i=0; num[i]!='\0';i++){
    n=a/c;
    b=n%10;
    r=b+r*10;
    c=c*10;
  }
  return a==r;
}

int main(int argcu, char* argd[]){
  cout<<capicua(argd[1])<<endl;  
  return 0;
}
