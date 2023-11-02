#include <iostream>
using namespace std;

void printPermutations(string &str,int index){
  //base case
  if(index>=str.size()){
    cout<<str<<endl;
    return;
  }
  //processing
  for(int j=index;j<str.size();j++){
    swap(str[index],str[j]);
    printPermutations(str,index+1);
    //backtracking
    swap(str[index],str[j]);
  }
}
int main() {
  string str="pqr";
  printPermutations(str,0);
  return 0;
}

// time complexity: O(n*n!)