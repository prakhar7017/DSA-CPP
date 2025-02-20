class Solution {
public:

    string app1(vector<string>& nums){
        unordered_set<int>st;

        for(string num:nums){
            st.insert(stoi(num,0,2));
        }

        int n=nums.size();
        string ans="";
        for(int i=0;i<=n;i++){
            if(st.find(i)==st.end()){
                ans+=bitset<16>(i).to_string();
                break;
            }
        }

        return ans.substr(16-n);
    }

    string app2(vector<string>& nums){
        int n=nums.size();
        string ans="";
        for(int i=0;i<n;i++){
            char ch=nums[i][i];
            ans+=(ch=='0') ? '1' : '0';
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        return app2(nums);
    }
};