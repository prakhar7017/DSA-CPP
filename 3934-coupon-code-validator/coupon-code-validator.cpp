class Solution {
public:
    bool isValidCode(string &code){
        if(code.empty()) return false;
        for (char &ch:code){
            if(!isalnum(ch) && ch!='_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, int> mp = {{"electronics", 0},
                                         {"grocery", 1},
                                         {"pharmacy", 2},
                                         {"restaurant", 3}};

        vector<pair<int,string>>v;
        for(int i=0;i<n;i++){
            if(isValidCode(code[i]) && mp.count(businessLine[i]) && isActive[i]){
                v.push_back({mp[businessLine[i]],code[i]});
            }
        }                                 

        sort(begin(v),end(v));
        vector<string>ans;

        for(auto &it:v){
            ans.push_back(it.second);
        }
        return ans;
    }
};