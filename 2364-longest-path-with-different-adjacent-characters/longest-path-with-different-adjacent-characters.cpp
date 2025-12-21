class Solution {
public:
    int ans;

    int dfs(unordered_map<int,vector<int>>&adj, int currNode, int parent,string &s){
        int longest = 0;
        int secondLongest = 0;

        for(int &child:adj[currNode]){
            if(child==parent) continue;

            int child_longest_path = dfs(adj,child,currNode,s);
            if(s[child]==s[currNode]) continue;

            if(child_longest_path>secondLongest) secondLongest = child_longest_path;
            if(secondLongest>longest) swap(longest,secondLongest);
        }

        int neche_he_ans_milgya =  longest+secondLongest+1;
        int koi_ek_acha_hai = max(longest,secondLongest)+1;
        int only_root_acha_hai = 1;
        ans=max({ans,neche_he_ans_milgya,koi_ek_acha_hai,only_root_acha_hai});
        return max(koi_ek_acha_hai,only_root_acha_hai);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>adj;
        ans = 0;
        for(int i=1;i<n;i++){
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj,0,-1,s);

        return ans;

    }
};