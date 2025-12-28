class Solution {
public:
    typedef pair<string,double>P;
    void dfs(string src,string dest,unordered_set<string>&vis,double &result,double product,unordered_map<string,vector<P>>&adj){
        if(vis.find(src)!=vis.end()) return ;
        vis.insert(src);

        if(src == dest) {
            result = product;
            return;
        }

        for(auto p:adj[src]){
            string v = p.first;
            double val = p.second;
            dfs(v,dest,vis,result,product*val,adj);
        }    
    }
    void BFS(string src,string dest,unordered_set<string>&vis,double &result,double product,unordered_map<string,vector<P>>&adj){
        queue<P>q;
        q.push({src,product});
        vis.insert(src);

        while(!q.empty()){
            auto [node,prod] = q.front();
            q.pop();

            if(node == dest) {
                result = prod;
                return;
            }

            for(auto p:adj[node]){
                string v = p.first;
                double val = p.second;
                if(vis.find(v)==vis.end()){
                    q.push({v,prod*val});
                    vis.insert(v);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<P>>adj;

        for(int i=0;i<n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        vector<double>ans;
        for(vector<string>& query:queries){
            string src = query[0];
            string dest = query[1];
            double result = -1.0;
            double product = 1.0;

            if(adj.find(src)!=adj.end() && adj.find(dest)!=adj.end()){
                unordered_set<string>vis;
                // dfs(src,dest,vis,result,product,adj);
                BFS(src,dest,vis,result,product,adj);
            }

            ans.push_back(result);
        }
        return ans;
    }
};