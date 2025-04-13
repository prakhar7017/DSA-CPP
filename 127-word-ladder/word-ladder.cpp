class Solution {
public:
    int solveUsingBFS(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        queue<string>q;
        int level=1;
        q.push(beginWord);
        vis.insert(beginWord);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string currWord=q.front();
                q.pop();
                if(currWord==endWord) return level;
                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<currWord.size();i++){
                        string neighWord=currWord;
                        neighWord[i]=ch;
                        if(vis.find(neighWord)==vis.end() && 
                            wordSet.find(neighWord)!=wordSet.end()
                        ){
                            q.push(neighWord);
                            vis.insert(neighWord);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return solveUsingBFS(beginWord,endWord,wordList);
    }
};