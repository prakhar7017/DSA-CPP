class Solution {
public:
    unordered_set<char>mp={'A','E','I','O','U','a','e','i','o','u'};
    int countVowel(string str){
        int count=0;
        for(char ch:str){
            if(mp.find(ch)!=mp.end()){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int len=s.length();
        int mid=len>>1;
        string firstPart=s.substr(0,mid);
        string secPart=s.substr(mid);
        return countVowel(firstPart)==countVowel(secPart);
    }
};

