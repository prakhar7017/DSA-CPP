class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>>maxi;
        vector<int>ans;
        int n=nums.size();
        // process first window
        for(int i=0;i<k;i++){
            maxi.push({nums[i],i});
        }

        // store the answer of first window
        ans.push_back(maxi.top().first);

        // remainngn windows
        for(int i=k;i<n;i++){
            // push element in maxi ,bcoz can be answer of next windows
            maxi.push({nums[i],i});

            while(maxi.top().second<=i-k){
                maxi.pop();
            }

            ans.push_back(maxi.top().first);
        }

        return ans;
    }
};