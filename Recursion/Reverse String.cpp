#include <iostream>
using namespace std;

void reverse(string &str,int s,int e){
  //base case
  if(s>=e){
    return;
  }

  //processing
  swap(str[s],str[e]);

  //recursive calls
  reverse(str,s+1,e-1);
}

int main() {
  string str="prakhar";
  reverse(str,0,str.size()-1);
  cout<<str<<endl;;
  return 0;
}

// time complexity : O(n) n is the size of the string

