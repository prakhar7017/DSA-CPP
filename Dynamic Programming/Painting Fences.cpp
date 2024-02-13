#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n,int k){
  // base case
  if(n==1){
    return k;
  }
  if(n==2){
    return (k+k*(k-1));
  }
  // ans=(same+diff)*(k-1)
  int ans=(solveUsingRecursion(n-2,k)+solveUsingRecursion(n-1,k))*(k-1);
  return ans;
}

int solveUsingRecursionMEMO(int n,int k,vector<int>&dp){
  // base case
  if(n==1){
    return k;
  }
  if(n==2){
    return (k+k*(k-1));
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  // ans=(same+diff)*(k-1)
  int ans=(solveUsingRecursion(n-2,k)+solveUsingRecursion(n-1,k))*(k-1);
  return dp[n]=ans;
}
int solveUsingTabulation(int n,int k){

  vector<int>dp(n+1,-1);
  // base case analysis
  dp[1]=k;
  dp[2]=(k+k*(k-1));

  for(int i=3;i<=n;i++){
    dp[i]=(dp[i-2]+dp[i-1])*(k-1);
  }
  return dp[n];
}
int spaceOptimised(int n,int k){
  int prev2=k;
  int prev1=(k+k*(k-1));
  if(n==1){
    return prev2;
  }
  if(n==2){
    return prev1;
  }
  int curr;
  for(int i=3;i<=n;i++){
    curr=(prev2+prev1)*(k-1);
    prev2=prev1;
    prev1=curr;
  }
  return curr;
}
int main() {
  int n=2;
  int k=4;
  vector<int>dp(n+1,-1);
  // int ans=solveUsingRecursion(n,k);
  // int ans=solveUsingRecursionMEMO(n,k,dp);
  // int ans=solveUsingTabulation(n,k);
  int ans=spaceOptimised(n,k);
  cout<<ans<<endl;
  return 0;
}