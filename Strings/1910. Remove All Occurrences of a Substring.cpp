class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

// time complxity : O(n*m) n is the size of the string and m is the size of the part string

// Recursive Solution 


class Solution {
    private:
    void remOccurance(string &s,string &part){
        int found=s.find(part);
        if(found!=string::npos){
            string left=s.substr(0,found);
            string right=s.substr(found+part.size(),s.size());
            s=left+right;
            remOccurance(s,part);
        }else{
            //base case
            return;
        }
    }
public:
    string removeOccurrences(string s, string part) {
        remOccurance(s,part);
        return s;
    }
};

// time complexity : O(n^2)