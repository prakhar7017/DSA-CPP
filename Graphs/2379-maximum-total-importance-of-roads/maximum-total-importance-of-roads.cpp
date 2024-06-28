
// count the indegree of each node. the node haveing greates indegree will be assocaited with greatest value. similarly node with least indegree will have least value.
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(vector<int>vec:roads){
            int u=vec[0];
            int v=vec[1];
            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree),end(degree));

        long long value=1;
        long long sum=0;
        for(int deg:degree){
            sum+=deg*value;
            ++value;
        }
        return sum;
    }
};