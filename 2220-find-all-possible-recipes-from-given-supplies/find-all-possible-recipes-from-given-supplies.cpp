class Solution {
public:
    vector<string> solveUsingBfs(vector<string>& recipes,
                                 vector<vector<string>>& ingredients,
                                 vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));

        unordered_map<string, vector<int>> adj; // ing->recipeeIndex
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            string recipe = recipes[i];
            for (int j = 0; j < ingredients[i].size(); j++) {
                string ingredient = ingredients[i][j];
                if (!st.count(ingredient)) {
                    adj[ingredient].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<string> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(recipes[i]);
        }
        vector<string> ans;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int& nextRecIndex : adj[curr]) {
                indegree[nextRecIndex]--;
                if (indegree[nextRecIndex] == 0) {
                    q.push(recipes[nextRecIndex]);
                }
            }
        }
        return ans;
    }

    vector<string>solveUsingBruteForce(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies){

        int n = recipes.size();
        int count = n;
        vector<bool>isCooked(n,false);
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<string>ans;
        while(count--){
            for(int i=0;i<n;i++){
                if(isCooked[i]){
                    continue;
                }

                bool banpayege=true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(!st.count(ingredients[i][j])){
                        banpayege=false;
                        break;
                    }
                }

                if(banpayege){
                    isCooked[i]=true;
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                }
            }
        }
        return ans;

    }
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
                                    return solveUsingBruteForce(recipes,ingredients,supplies);

    }
};