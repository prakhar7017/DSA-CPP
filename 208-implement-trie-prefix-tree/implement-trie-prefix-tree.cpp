class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode* root = new TrieNode();
        root->isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            root->children[i] = nullptr;
        }
        return root;
    }
    TrieNode* root;
    Trie() { root = getNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = getNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        if (curr!=nullptr && curr->isEndOfWord == true)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i=0;
        for (;i<prefix.length();i++) {
            int idx = prefix[i] - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        if (i == prefix.length()) 
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */