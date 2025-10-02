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

    string generate(string& s) {
        int n = s.size();
        int arr[26] = {0};

        for (char& ch : s) {
            arr[ch - 'a']++;
        }

        string newWord = "";
        for (int i = 0; i < 26; i++) {
            int freq = arr[i];
            if (freq > 0) {
                newWord += string(freq, i + 'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> solveUsingWithoutSort(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // return solveUsingSort(strs);
        return solveUsingWithoutSort(strs);
    }
};