class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(begin(bank), end(bank));
        unordered_set<string> vis;

        if(bankset.find(endGene)==bankset.end()) return -1;

        queue<string> q;
        int level = 0;
        q.push(startGene);
        vis.insert(startGene);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                string currStr = q.front();
                q.pop();
                if (currStr == endGene)
                    return level;

                for (char ch : "ACGT") {
                    for (int i = 0; i < currStr.length(); i++) {
                        string neigh = currStr;
                        neigh[i] = ch;
                        if (vis.find(neigh) == vis.end() &&
                            bankset.find(neigh) != bankset.end()) {
                            q.push(neigh);
                            vis.insert(neigh);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};