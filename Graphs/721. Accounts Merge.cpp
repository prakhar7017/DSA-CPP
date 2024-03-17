class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);

        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);

        //make all the node as individual component
        for(int u=0;u<n;u++){
            parent[u]=u;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            auto account=accounts[i];
            for(int j=1;j<account.size();j++){
                string &mail=account[j];
                auto it=mp.find(mail);
                if(it!=mp.end()){
                    unionSet(i,it->second,parent,rank);
                }else{
                    mp[mail]=i;
                }
            }
        }

        unordered_map<int,set<string>>preAnswer;
        for(auto it:mp){
            auto accountNo=it.second;
            auto mail=it.first;
            accountNo=findParent(parent,accountNo);
            preAnswer[accountNo].insert(mail);
        }

        vector<vector<string>>ans;
        for(auto it:preAnswer){
            auto accountNo=it.first;
            auto st=it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]);
            for(auto mail:st){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// time complexity: O(n*m*alpha(n)) // alpha(n) is very slow growing function
// space complexity: O(n*m) // n is the number of accounts and m is the average number of mails in each account
