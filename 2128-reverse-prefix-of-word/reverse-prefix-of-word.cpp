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
        // int idx=findIndex(word,ch);
        // if(idx==-1) return word;
        // return reverseString(word,0,idx);
        auto found=find(begin(word),end(word),ch);
        int idx=-1;
        if(found!=word.end()){
            idx=found-word.begin();
        }
        if(idx==-1) return word;
        reverse(word.begin(),word.begin()+idx+1);
        return word;
    }
};