class Solution {
public:
    int BFS(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(begin(wordList),end(wordList));
        unordered_map<string,vector<string>>mp;
        for(string s:wordList){
            for(int i=0;i<s.length();i++){
                string pattern = s;
                pattern[i]='*';
                mp[pattern].push_back(s);
            }
        }
        int steps=0;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                string curr = q.front(); q.pop();
                if(curr == endWord) return steps;

                for(int i=0;i<curr.length();i++){
                    // char ori = curr[i];
                    // for(char j='a';j<='z';j++){
                    //     if(j == ori) continue;
                    //     curr[i]=j;
                    //     if(st.count(curr)){
                    //         st.erase(curr);
                    //         q.push(curr);
                    //     }
                    // }
                    // curr[i]=ori;

                    string pattern = curr;
                    pattern[i]='*';
                    for(string next:mp[pattern]){
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return BFS(beginWord, endWord, wordList);
    }
};