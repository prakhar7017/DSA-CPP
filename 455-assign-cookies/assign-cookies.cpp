class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int n=g.size();
        int m=s.size();

        int i=0;
        int j=0;

        while(i<n && j<m) {
            if(s[j]>=g[i]) i++;
            j++;
        }
        return i;
    }
};