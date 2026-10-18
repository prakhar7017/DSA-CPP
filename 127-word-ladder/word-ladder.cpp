class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(begin(wordList),end(wordList));
        unordered_map<string,vector<string>>mp;
        queue<string>q;
        for(string &word:wordList){
            for(int i=0;i<word.length();i++){
                string pattern = word;
                pattern[i]='*';
                mp[pattern].push_back(word);
            }
        }
        q.push(beginWord);
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            step++;
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return step;
                for(int i=0;i<curr.length();i++){
                    string pattern = curr;
                    pattern[i]='*';
                    for(string &next:mp[pattern]){
                        if(st.count(next)){
                            st.erase(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return 0;
    }
};