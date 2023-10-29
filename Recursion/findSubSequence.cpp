#include <iostream>
#include <vector>
using namespace std;


void findSubSequence(string &str,string output,int index,vector<string>&ans){
  //base case
  if(index>=str.size()){
    ans.push_back(output);
    return;
  }

  //processing
  char ch=str[index];


  //recurise call

  //include
  output.push_back(ch);
  findSubSequence(str,output,index+1,ans);

  //exclude
  output.pop_back();
  findSubSequence(str,output,index+1,ans);

}

int main() {
  string str="abs";
  string output="";
  int index=0;
  vector<string>ans;
  findSubSequence(str,output,index,ans);
  for(auto val:ans){
    cout<<"--> "<<val<<endl;
  }
  return 0;
}

// time complexity : O(2^n) n is the size of the string

