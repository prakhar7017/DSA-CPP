class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int i,vector<int>&parent){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=findParent(parent[i],parent);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(u,parent);
        v=findParent(v,parent);

        if(u==v){
            parent[v]=u;
            rank[u]++;
        }else if(rank[u]<rank[v]){
            parent[u]=v;
        }else {
            parent[v]=u;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(string &str:equations){
            if(str[1]=='='){
                unionSet(str[0]-'a',str[3]-'a',parent,rank);
            }
        }

        for(string &str:equations){
            if(str[1]=='!'){
                int parent_first=findParent(str[0]-'a',parent);
                int parent_second=findParent(str[3]-'a',parent);

                if(parent_first==parent_second){
                    return false;
                }
            }
        }
        return true;
    }
};