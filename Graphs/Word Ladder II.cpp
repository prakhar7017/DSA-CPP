


vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    queue<pair<vector<string>, int>> q;
    q.push({{beginWord}, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());

    int prevLevel = -1;
    vector<string> tobeRemoved;

    while (!q.empty()) {
        auto fNode = q.front();
        q.pop();
        auto currSeq = fNode.first;
        auto currString = currSeq.back(); // Get the current string from the back of the sequence
        auto currLevel = fNode.second;

        if (currLevel != prevLevel) {
            for (auto s : tobeRemoved) st.erase(s);
            tobeRemoved.clear();
            prevLevel = currLevel;
        }

        // khi destination toh nhi pocuh gye
        if (currString == endWord) ans.push_back(currSeq);

        for (int index = 0; index < currString.size(); index++) {
            char originalCharacter = currString[index];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                currString[index] = ch;

                if (st.find(currString) != st.end()) {
                    auto temp = currSeq;
                    temp.push_back(currString);
                    q.push({temp, currLevel + 1});
                    tobeRemoved.push_back(currString);
                }
            }
            currString[index] = originalCharacter; // Revert back the character for next iteration   IMP yha ma galti karta hu
        }
    }
    return ans;
}

// time comeplexity: O(n*26^l) where l is the length of the word and n is the number of words in the list
// space complexity: O(n*26^l) where l is the length of the word and n is the number of words in the list