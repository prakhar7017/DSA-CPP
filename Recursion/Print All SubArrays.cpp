#include <iostream>
#include <vector>
using namespace std;

//print all the subarray from start till end
void printSubArrayUtil(vector<int>&nums,int s,int e=0){
  //base case
  if(e>=nums.size()){
    return;
  }

  // processing
  for(int i=s;i<=e;i++){
    cout<<nums[i]<<" ";
  }
  cout<<endl;

  //recursive calls
  printSubArrayUtil(nums,s,e+1);
}

//take care of start and end
void printSubArray(vector<int>&nums){ 
  for(int i=0;i<nums.size();i++){
    printSubArrayUtil(nums,i,i);
  }
}

int main() {
  vector<int>nums={1,2,3,4,5};
  printSubArray(nums);
  return 0;
}



// time complexity : O(n^2) n is the size of the array

output->
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
2 
2 3 
2 3 4 
2 3 4 5 
3 
3 4 
3 4 5 
4 
4 5 
5 