class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty())
        {
            auto fNode = q.front();
            q.pop();
            auto currString = fNode.first;
            auto currCount = fNode.second;

            // khi destination toh nhi pocuh gye
            if (currString == targetWord)
                return currCount;

            for (int index = 0; index < currString.size(); index++)
            {
                char originalCharacter = currString[index];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;

                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                currString[index] = originalCharacter; // Revert back the character for next iteration   IMP yha ma galti karta hu
            }
        }
        return 0;
    }
};

// time complexity: O(n*26^l) where l is the length of the word and n is the number of words in the list
// space complexity: O(n*26^l) where l is the length of the word and n is the number of words in the list