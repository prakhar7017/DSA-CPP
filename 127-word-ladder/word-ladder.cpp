class Solution {
public:
    int BFS(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(begin(wordList),end(wordList));
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<wordList.size();i++){
            string word = wordList[i];
            for(int i=0;i<word.size();i++){
                string pattern = word;
                pattern[i]='*';
                adj[pattern].push_back(word);
            }
        }
        queue<string>q;
        q.push(beginWord);
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                string curr = q.front(); q.pop();
                if(curr == endWord) return steps;
                for(int i=0;i<curr.size();i++){
                    string pattern = curr;
                    pattern[i]='*';
                    for(string &next:adj[pattern]){
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
        return BFS(beginWord,endWord,wordList);
    }
};