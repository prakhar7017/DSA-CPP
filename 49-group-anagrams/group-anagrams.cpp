class Solution {
public:
    string generate(string &str){
        int arr[26]={0};
        for(char &c:str){
            arr[c-'a']++;
        }
        string newWord = "";
        for(int i=0;i<26;i++){
            int freq = arr[i];
            if(freq>0){
                newWord+= string(freq,i+'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string &str:strs){
            string anagram = generate(str);
            mp[anagram].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};