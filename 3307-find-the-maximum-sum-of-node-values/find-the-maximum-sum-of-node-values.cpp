class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0;
        int count=0;
        int nuksan=INT_MAX;

        for(ll num : nums){
            if((num^k)>num){
                sum+=(num^k);
                ++count;
            }else{
                sum+=num;
            }
                nuksan=min((long long)nuksan,abs(num-(num^k)));
        }

        if(count & 1==1){
            return sum-nuksan;
        }
        return sum;
    }
};