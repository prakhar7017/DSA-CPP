class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int s = 0;
        int e = n-1;

        while(s<e){
            int sum = num[s]+num[e];
            if(sum==target) return {s+1,e+1};
            else if(sum<target) s++;
            else e--;
        }
        return {-1,-1};
    }
};