class Solution {
public:
    vector<char>chars={'A','C','G','T'};
    int BFS(string startGene, string endGene, vector<string>& bank){
        unordered_set<string>st(begin(bank),end(bank));
        queue<string>q;
        q.push(startGene);
        int mutations = 0;
        while(!q.empty()){
            int size = q.size();
            mutations++;
            for(int i=0;i<size;i++){
                string curr = q.front(); q.pop();
                for(int i=0;i<curr.length();i++){
                    char ori = curr[i];
                    for(char ch:chars){
                        if(ch == ori) continue;
                        curr[i]=ch;
                        if(st.count(curr)){
                            if(curr == endGene) return mutations;
                            st.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i]=ori;
                }
            }
        }
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        return BFS(startGene, endGene, bank);    
    }
};