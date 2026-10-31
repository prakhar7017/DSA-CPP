class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        return s1 == s2;
    }
    vector<vector<string>> solveUsingBruteForce(vector<string>& strs) {
        int n = strs.size();
        vector<int> vis(n, 0);
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            string curr = strs[i];
            vis[i] = 1;
            vector<string> group;
            group.push_back(curr);
            for (int j = i + 1; j < n; j++) {
                string next = strs[j];
                if (!vis[j] && isAnagram(curr, next)) {
                    group.push_back(next);
                    vis[j] = true;
                }
            }
            ans.push_back(group);
        }
        return ans;
    }
    vector<vector<string>> solveUsingBetter(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string temp = str;
            sort(begin(temp), end(temp));
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    string generate(string &str){
        int arr[26]={0};
        for(char &ch:str){
            arr[ch-'a']++;
        }

        string newWord ="";

        for(int i=0;i<26;i++){
            int freq = arr[i];
            if(freq>0){
                newWord+=string(freq,i+'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> solveUsingOptimised(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string sortedWord = generate(str); 
            mp[sortedWord].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return solveUsingOptimised(strs);
    }
};