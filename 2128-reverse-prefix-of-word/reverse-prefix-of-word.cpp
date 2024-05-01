class Solution {
public:
    int findIndex(string &word,char &ch){
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                return i;
            }
        }
        return -1;
    }
    string reverseString(string word,int s,int e){
        while(s<=e){
            swap(word[s++],word[e--]);
        }
        return word;
    }
    string reversePrefix(string word, char ch) {
        int idx=findIndex(word,ch);
        if(idx==-1) return word;
        return reverseString(word,0,idx);
    }
};