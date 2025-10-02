class Solution {
public:
    vector<vector<string>> solveUsingSort(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            string word = strs[i];
            sort(begin(word), end(word));
            mp[word].push_back(strs[i]);
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return solveUsingSort(strs);
    }
};