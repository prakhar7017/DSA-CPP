class Solution {
public:
    bool solveBruteForce(string s){
        bool changed = true;
        while(changed){
            changed = false;
            for(int i=0;i+1<s.size();i++){
                if((s[i]=='(' && s[i+1]==')') || (s[i]=='{' && s[i+1]=='}') || (s[i]=='[' && s[i+1]==']')){
                    s.erase(i,2);
                    changed = true;
                    break; // restart scaning after modifying
                }
            }
        }
        return s.empty();
    }
    bool isValid(string s) { return solveBruteForce(s); }
};