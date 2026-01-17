class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>st(begin(supplies),end(supplies));

        unordered_map<string,vector<int>>adj; // ing->recipeeIndex
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            string recipe = recipes[i];
            for(int j=0;j<ingredients[i].size();j++){
                string ingredient = ingredients[i][j];
                if(!st.count(ingredient)){
                    adj[ingredient].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<string>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(recipes[i]);
        }
        vector<string>ans;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(int &nextRecIndex:adj[curr]){
                indegree[nextRecIndex]--;
                if(indegree[nextRecIndex]==0){
                    q.push(recipes[nextRecIndex]);
                }
            }
        }
        return ans;

    }
};