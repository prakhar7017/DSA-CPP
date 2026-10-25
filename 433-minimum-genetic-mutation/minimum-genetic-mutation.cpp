class Solution {
public:
    vector<char> chars = {'A', 'C', 'G', 'T'};
    int solveUsingBFS(string& src, string& dest, unordered_set<string>& st) {
        queue<string> q;
        q.push(src);
        int mutations = 0;
        while (!q.empty()) {
            int size = q.size();
            mutations++;
            while (size--) {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < curr.length(); i++) {
                    char ori = curr[i];
                    for (char& ch : chars) {
                        curr[i] = ch;
                        if (st.count(curr)) {
                            if (curr == dest)
                                return mutations;
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i] = ori;
                }
            }
        }
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(begin(bank), end(bank));
        return solveUsingBFS(startGene, endGene, st);
    }
};