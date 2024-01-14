class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        if(n!=m) return false;

        vector<int>v1(26);
        vector<int>v2(26);

        for(int i=0;i<m;i++){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }

        // same char presnt in both strings ?
        for(int i=0;i<26;i++){
            if(v1[i]!=0 && v2[i]!=0) continue;
            if(v2[i]==0 && v2[i]==0) continue;
            return false;
        }

        // same freq of chars in both strings ? values matters not order 
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2;

    }
};

// intitution
// 1. if the two strings have different characters, return false
// 2. freq of of chars in both strings should be same (values matters not order)
