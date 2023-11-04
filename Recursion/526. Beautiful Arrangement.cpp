class Solution {
    private:
    void countArrangementHelper(vector<int>&v,int &n,int &ans,int currNum){
        //base case
        if(currNum==n+1){
            ++ans;
            return;
        }

        //processing
        for(int i=1;i<=n;i++){
            if(v[i]==0 && (currNum % i == 0 || i % currNum == 0)){
                v[i]=currNum;
                countArrangementHelper(v,n,ans,currNum+1);
                //backtrack
                v[i]=0;
            }
        }
    }
public:
    int countArrangement(int n) {
        int ans=0;
        vector<int>v(n+1);
        countArrangementHelper(v,n,ans,1);
        return ans;
    }
};


// time complexity: O(k) where k is the number of valid permutations.