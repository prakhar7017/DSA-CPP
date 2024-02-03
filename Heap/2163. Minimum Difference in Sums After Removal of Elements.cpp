#define ll long long 
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ll m=nums.size();
        ll n = m/3;
        vector<ll>prefix(m,-1),suffix(m,-1); 
        // prefix[i] = sum of first n min elements from left
        // suffix[i] = sum of first n max elements from right 
        priority_queue<ll>maxi; // why maxi is used because we want to pop out maximum elment to find the sum of first n min elements
        ll sum=0;
        for(int i=0;i<m;i++){
            sum+=nums[i];
            maxi.push(nums[i]);
            if(maxi.size()>n){ // means we have more than n elements in the priority queue so we need to pop out the maximum element
                sum-=maxi.top();
                maxi.pop();
            }
            if(maxi.size()==n){ // means we have exactly n elements in the priority queue so we can store the sum of first n min elements
                prefix[i]=sum;
            }
        }
        sum=0;
        priority_queue<ll,vector<ll>,greater<ll>>mini; // why mini is used because we want to pop out minimum elment to find the sum of first n max elements
        for(int i=m-1;i>=0;i--){
            sum+=nums[i];
            mini.push(nums[i]);
            if(mini.size()>n){ // means we have more than n elements in the priority queue so we need to pop out the minimum element
                sum-=mini.top();
                mini.pop();
            }
            if(mini.size()==n){ // means we have exactly n elements in the priority queue so we can store the sum of first n max elements
                suffix[i]=sum;
            }
        }

        ll ans=LONG_LONG_MAX;
        for(int i=n-1;i<2*n;i++){  // we are taking n-1 to 2n-1 because we need to find the minimum difference of the sum of first n min elements and sum of first n max elements
            ans=min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;

    }
};