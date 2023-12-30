// first approach
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        int freq[26]={0};

        for(string &word:words){
            for(char &ch:word){
                freq[ch-'a']++;
            }
        }

        for(auto &it:freq){
            if(it%n!=0){
                return false;
            }
        }
        return true;
    }
};

// second approach using lambda function
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        int freq[26]={0};

        for(string &word:words){
            for(char &ch:word){
                freq[ch-'a']++;
            }
        }

        // lambda function
        auto lambda=[&](int count){ // & is used to access outer elements into lambda function int count is the data type of the parameter
            return count%n==0;
        };
        return all_of(begin(freq),end(freq),lambda);
    }
};