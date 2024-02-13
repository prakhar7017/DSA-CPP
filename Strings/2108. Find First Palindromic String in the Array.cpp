class Solution {
public:
    bool checkPalindrome(string &word){
        int i=0;
        int j=word.length()-1;
        while(i<j){
            if(word[i]!=word[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(auto word:words){
            if(checkPalindrome(word)){
                ans=word;
                break;
            }
        }
        return ans;
    }
};


// using STL function

// 1.
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            string temp=word;
            reverse(word.begin(),word.end());
            if(word==temp){
                return word;
            }
        }
        return "";
    }
};

// 2.
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            if(word==string(word.rbegin(),word.rend())){
                return word;
            }
        }
        return "";
    }
};

// 3.
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &word:words){
            int n=word.length();
            if(equal(word.begin(),word.begin() + (n>>1),word.rbegin())){
                return word;
            }
        }
        return "";
    }
};

