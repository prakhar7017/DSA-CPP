class Solution {
public:
    static bool mpcomp(string a , string b){
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(auto n:nums){
            s.push_back(to_string(n));
        }   
        sort(s.begin(),s.end(),mpcomp);
        if(s[0]=="0") return "0"; 

        string ans="";
        for(auto str:s){
            ans+=str;
        }
        return ans;
    }
};