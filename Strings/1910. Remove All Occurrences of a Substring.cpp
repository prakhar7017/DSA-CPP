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