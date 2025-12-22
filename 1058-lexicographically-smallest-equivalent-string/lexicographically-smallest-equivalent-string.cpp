class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void Union(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if (u==v) return;
        if(u<v) {
            parent[v]=u;
        }else {
            parent[u]=v;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n =s1.length();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;

        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a');
        }

        string ans="";
        for(char &ch:baseStr){
            ans+=char(findParent(ch-'a')+'a');
        }
        return ans;
    }
};