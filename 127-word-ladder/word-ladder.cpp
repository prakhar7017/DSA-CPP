class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(begin(wordList),end(wordList));
        queue<string>q;
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
                    char ori = curr[i];
                    for(int j='a';j<='z';j++){
                        curr[i]=j;
                        if(st.count(curr)){
                            q.push(curr);
                            st.erase(curr);
                        }
                        curr[i]=ori;
                    }
                }
            }
        }
        return 0;
    }
};