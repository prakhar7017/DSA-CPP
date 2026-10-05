class Solution {
public:
    int BFS(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(begin(wordList),end(wordList));
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
                    char ori = curr[i];
                    for(int j='a';j<='z';j++){
                        curr[i]=j;

                        if(st.find(curr)!=st.end()){
                            st.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i]=ori;
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return BFS(beginWord,endWord,wordList);
    }
};