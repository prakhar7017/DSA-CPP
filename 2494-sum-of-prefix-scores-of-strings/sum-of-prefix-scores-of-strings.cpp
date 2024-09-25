class TrieNode {
public:
    unordered_map<char, TrieNode*> children; 
    int count;
    
    TrieNode() {
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

  
    void insert(const string& str) {
        TrieNode* curr = root;
        for (char ch : str) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
            curr->count += 1;  
        }
    }

    int search(const string& str) {
        TrieNode* curr = root;
        int ans = 0;
        for (char ch : str) {
            if (curr->children.find(ch) == curr->children.end()) {
                return ans;  
            }
            curr = curr->children[ch];
            ans += curr->count; 
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        Trie trie;

        for (const string& str : words) {
            trie.insert(str);
        }

        for (const string& str : words) {
            int tmp = trie.search(str);
            res.push_back(tmp);
        }

        return res;
    }
};