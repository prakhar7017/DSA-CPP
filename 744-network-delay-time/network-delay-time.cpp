class Solution {
public:
    typedef pair<int, int> P;
    int DJ(int n, int k,unordered_map<int, vector<P>>&mp){
        vector<int>result(n+1,INT_MAX);
        set<P>st; 
        result[k]=0;
        st.insert({0,k});

        while(!st.empty()){
            auto &it = *st.begin();
            int currNode = it.second;
            int d = it.first;
            st.erase(it);

            for(P &v:mp[currNode]){
                int neigh = v.first;
                int dist = v.second;
                if(d+dist<result[neigh]){
                    st.erase({result[neigh],neigh});
                    result[neigh]=d+dist;
                    st.insert({d+dist,neigh});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if (result[i]==INT_MAX) return -1;
            ans = max(ans,result[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<P>>mp;
        for (vector<int>& time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            mp[u].push_back({v,wt});
        }
        return DJ(n,k,mp);
    }
};