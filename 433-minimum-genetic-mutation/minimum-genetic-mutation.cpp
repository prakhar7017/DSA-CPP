class Solution {
public:
    int solveUsingBFS(string startGene, string endGene, vector<string>& bank){
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>vis;
        queue<string>q;
        int level=0;
        q.push(startGene);
        vis.insert(startGene);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string currStr=q.front();
                q.pop();
                if(currStr==endGene) return level;
                for(char ch:"ACGT"){
                    for(int i=0;i<currStr.length();i++){
                        string neigh=currStr;
                        neigh[i]=ch;
                        if(vis.find(neigh)==vis.end() && bankset.find(neigh)!=bankset.end()){
                            q.push(neigh);
                            vis.insert(neigh);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
       return solveUsingBFS(startGene,endGene,bank);
 
    }
};