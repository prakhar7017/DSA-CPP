class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u],parent);
    }

    void UnionSet(int u,int v,vector<int>&rank,vector<int>&parent){
        u=findParent(u,parent);
        v=findParent(v,parent);

        if(u==v) return ;

        if(rank[u]<rank[v]){
            parent[u]=v;
        }else if(rank[u]>rank[v]){
            parent[v]=u;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>emailToAccountNo;

        for(int i=0;i<n;i++){
            auto account=accounts[i];
            for(int j=1;j<account.size();j++){
                string &mail=account[j];
                auto it=emailToAccountNo.find(mail);
                if(it!=emailToAccountNo.end()){
                    UnionSet(i,it->second,rank,parent);
                }else{
                    emailToAccountNo[mail]=i;
                }
            }
        }

        unordered_map<int,set<string>>accountnoToemail;
        for(auto it:emailToAccountNo){
            int accountNo=it.second;
            auto mail=it.first;
            accountNo=findParent(accountNo,parent);
            accountnoToemail[accountNo].insert(mail);
        }

        vector<vector<string>>ans;
        for(auto it:accountnoToemail){
            auto accountNo=it.first;
            auto mails=it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]); // inserting name
            for(auto mail:mails){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;
    }
};