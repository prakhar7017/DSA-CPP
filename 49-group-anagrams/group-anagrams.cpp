class Solution {
public:
    string generateStr(string &str){
        int arr[26]={0};
        for(char &ch:str){
            arr[ch-'a']++;
        }
        string newWord = "";
        for(int i=0;i<26;i++){
            int freq = arr[i];
            if(freq>0){
                newWord+=string(freq,i+'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> solve(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string newStr = generateStr(strs[i]);
            mp[newStr].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return solve(strs);
    }
};