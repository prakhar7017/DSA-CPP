class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        // preparing first window
        for(int i=0;i<k;i++){
            int element=nums[i];
            while(!dq.empty() && element>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // process remaning windows 
            // store ans
            // removal of out of range
            // additaion of new elemt
        
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);

            // removal of out of range index
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            // removing smaller elements than current
            int element=nums[i];
            while(!dq.empty() && element>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // process last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

// time complexity: O(n)
