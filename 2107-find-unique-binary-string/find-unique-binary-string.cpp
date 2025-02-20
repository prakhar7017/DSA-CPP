class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
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
};