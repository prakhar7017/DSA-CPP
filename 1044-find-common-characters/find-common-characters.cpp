class Solution {
public:
    void fillMinFreq(string &word,int minFreq[26]){
        for(char &ch:word){
            minFreq[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();

        int minFreq[26]={0};

        fillMinFreq(words[0],minFreq);

        for(string word:words){
            int temp[26]={0};
            fillMinFreq(word,temp);
            for(int i=0;i<26;i++){
                minFreq[i]=min(minFreq[i],temp[i]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            int freq=minFreq[i];
            while(freq--){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};