class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==k){
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        int sum=ans;
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[cardPoints.size()-k+i];
            ans=max(ans,sum);
        }
        return ans;
    }
};

// time complexity : O(n) n is the size of the array 
// sliding window approach