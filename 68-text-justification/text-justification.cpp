class Solution {
public:
    int MAX_WIDTH;
    string getFinalString(int i, int j, int eachWordSpace, int extraSlotsSpace,
                          vector<string>& words) {
        string s;
        for (int k = i; k < j; k++) {
            s += words[k];
            if (k == j - 1)
                continue;
            for (int space = 1; space <=eachWordSpace; space++) {
                s += " ";
            }

            if (extraSlotsSpace > 0) {
                s += " ";
                extraSlotsSpace--;
            }
        }

        while (s.length() < MAX_WIDTH) {
            s += " ";
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;

        while (i < n) {
            int letterCount = words[i].length();
            int j = i + 1;
            int spaceSlots = 0;
            while (j < n &&
                letterCount + spaceSlots + words[j].length() + 1 <= maxWidth) {
                letterCount += words[j].length();
                spaceSlots+=1;
                j++;
            }

            int remainingSlots = maxWidth - letterCount;
            int eachWordSpace =
                spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;
            int extraSlotsSpace =
                spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;

            if (j == n) {
                eachWordSpace = 1;
                extraSlotsSpace = 0;
            }

            result.push_back(
                getFinalString(i, j, eachWordSpace, extraSlotsSpace, words));
            i = j;
        }
        return result;
    }
};