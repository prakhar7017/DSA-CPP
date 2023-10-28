#include <iostream>
using namespace std;

void lastOccuranceRTOL(string & str,int index,int &ans,char &target){
  //base case
  if(index<0){
    return;
  }
  //processing
  if(str[index]==target){
    ans=index;
    return;
  }
  //recursive calls
  lastOccuranceRTOL(str,index-1,ans,target);
}


void lastOccuranceLTOR(string & str,int index,int &ans,char &target){
  //base case
  if(index>=str.size()){
    return;
  }
  //processing
  if(str[index]==target){
    ans=index;
  }
  //recursive calls
  lastOccuranceLTOR(str,index+1,ans,target);
}

int main() {
  int ans=-1;
  string str="abcddedg";
  char target='d';
  lastOccuranceRTOL(str,str.size()-1,ans,target);
  cout<<ans<<" "<<endl;
  return 0;
}

// time complexity : O(n) n is the size of the string