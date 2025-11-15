class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }

    void Union(int x,int y){
        x=find(x);
        y=find(y);

        if(x==y) return;
        if(rank[x]<rank[y]){
            parent[x]=y;
        } else if(rank[x]>rank[y]){
            parent[y]=x;
        }else{
            parent[y]=x;
            rank[x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(string &s:equations){
            if(s[1]=='=') Union(s[0]-'a',s[3]-'a');
        }

        for(string &s: equations){
            if(s[1]=='!'){
                if(find(s[0]-'a') == find(s[3]-'a')) return false;
            }
        }

        return true;
    }
};