#include <iostream>
using namespace std;

bool checkPalindrome(string &str,int s,int e){
  //base case
  if(s>e){
    return true;
  }
  //processing
  if(str[s]!=str[e]){
    return false;
  }
  //recursive calls
  return checkPalindrome(str,s+1,e-1);
}

int main() {
  string str="racecar";
  cout<<checkPalindrome(str,0,str.size()-1)<<endl;
  return 0;
}

// time complexity : O(n) n is the size of the string