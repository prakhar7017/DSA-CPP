class Solution {
public:
    vector<string>getNeighbors(string s){
        vector<string>neighbors;
        string temp=s;
        for(int i=0;i<s.length();i++){
            for(char ch='a';ch<='z';ch++){
                if(ch == temp[i]) continue;
                temp[i]=ch;
                neighbors.push_back(temp);
            }
            temp=s;
        }
        return neighbors;
    }
    int BFS(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(begin(wordList),end(wordList));
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
                    char ori = curr[i];
                    for(char j='a';j<='z';j++){
                        if(j == ori) continue;
                        curr[i]=j;
                        if(st.count(curr)){
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
        return BFS(beginWord, endWord, wordList);
    }
};