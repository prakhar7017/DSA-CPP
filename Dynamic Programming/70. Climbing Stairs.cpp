
// Approach 1 : Recursion with Memoization
class Solution {
public:
int t[46];
int solve(int n){
    if(n<0) return 0;

    if(t[n]!=-1){
        return t[n];
    }
    if(n==0) {
        return 1;
    }

    int step_1=solve(n-1);
    int step_2=solve(n-2);
    return t[n]=step_1+step_2;

}
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

// Approach 2 : Bottom Up DP
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 ||n==1 || n==2 || n==3) return n;

        vector<int>v(n+1);
        v[0]=0;
        v[1]=1;
        v[2]=2;

        for(int i=3;i<=n;i++){
            v[i]=v[i-1]+v[i-2];
        }

        return v[n];

    }
};


// Approach 3 : Bottom Up DP (Space Optimized)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 ||n==1 || n==2 || n==3) return n;

        int a=1; //i-2
        int b=2; //i-1
        int c=3;
        for(int i=3;i<=n;i++){
            c=a+b;
            int temp=b;
            b=c;
            a=temp;
        }

        return c;

    }
};