class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& batteries, ll mid_time , int n){
        ll target_minutes = n*mid_time;

        for(int i=0;i<batteries.size();i++){
            target_minutes -= min((ll)batteries[i],mid_time);
            if(target_minutes <= 0) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll start = *min_element(begin(batteries),end(batteries));
        ll total_batteries_sum = accumulate(begin(batteries),end(batteries),0LL);
        ll end =  total_batteries_sum/n;

        ll result = 0;
        while(start<=end){
            ll mid_time = start+(end-start)/2;

            if(possible(batteries,mid_time,n)){
                result = mid_time;
                start = mid_time+1;
            } else {
                end = mid_time -1;
            }
        }

        return result;
    }
};