
// brute force approach
class Solution {
public:
    int pivotInteger(int n) {
        int ans=-1;
        for(int i=0;i<n;i++){
            int leftSum=0;
            int rightSum=0;
            for(int j=0;j<=i;j++){
                leftSum+=j+1;
            }
            for(int k=i;k<n;k++){
                rightSum+=k+1;
            }
            if(leftSum==rightSum){
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};

// time complexity is O(n^2)
// space complexity is O(1)
//-----------------------------------------------------------------------------------
// using two auxiliary arrays
class Solution {
public:
    int pivotInteger(int n) {
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);

        leftSum[0]=1;
        rightSum[n-1]=n;
        for(int i=1;i<n;i++){
            leftSum[i]+=leftSum[i-1]+i+1;
        }
        for(int j=n-2;j>=0;j--){
            rightSum[j]+=rightSum[j+1]+j+1;
        }

        for(int i=0;i<n;i++){
            if(leftSum[i]==rightSum[i]){
                return i+1;
            }
        }
        return -1;
    }
};

// time complexity is O(n)
// space complexity is O(2n)

//-----------------------------------------------------------------------------------

class Solution {
public:
    int pivotInteger(int n) {
        int total=((n)*(n+1))>>1;
        int leftSum=0;
        int rightSum=0;

        for(int i=1;i<=n;i++){
            leftSum+=i;
            rightSum=total-(leftSum-i);
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;

    }
};
// time complexity is O(n)
// space complexity is O(1)

//--------------------------------------------------------------------
class Solution {
public:
    int pivotInteger(int n) {
        int total=((n)*(n+1))>>1;
        int leftSum=0;
        int rightSum=0;

        for(int i=1;i<=n;i++){
            leftSum=((i)*(i+1))>>1;
            rightSum=total-leftSum+i;
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;

    }
};
// time complexity is O(n)
// space complexity is O(1)

//----------------------------------------------------------------------------------
// using two pointers
class Solution {
public:
    int pivotInteger(int n) {
        int leftSum=1;
        int rightSum=n;
        int i=1;
        int j=n;

        while(i<j){
            if(leftSum<rightSum) i++, leftSum+=i;
            else j--, rightSum+=j;
        }
        return leftSum==rightSum ? i :-1;
    }
};

// time complexity is O(n)
// space complexity is O(1)

//---------------------------------------------------------------------------------
class Solution {
public:
    int pivotInteger(int n) {
        int total=((n)*(n+1))>>1;
        for(int i=1;i<=n;i++){
            if(i*i==total){
                return i;
            }
        }
        return -1;
    }
};
// time complexity is O(n)
// space complexity is O(1)

//---------------------------------------------------------------------------------
// using binary search
class Solution {
public:
    int pivotInteger(int n) {
        int total=((n)*(n+1))>>1;
        int i=1;
        int j=n;
        while(i<=j){
            int mid=(i+j)>>1;
            if(mid*mid==total) return mid;
            else if(mid*mid<total){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
};
// time complexity is O(logn)
// space complexity is O(1)