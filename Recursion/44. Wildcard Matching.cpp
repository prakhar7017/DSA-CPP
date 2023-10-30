class Solution {
    private:
    bool isMatchHelper(string &s,int si ,string &p,int pi){
        // base case
        if(si==s.size() && pi==p.size()){
            return true;
        }
        if(si==s.size() && pi<p.size()){
            while(pi<p.size()){
                if(p[pi]!='*'){
                    return false;
                }
            }
            return true;
        }
        //processing
        if(s[si]==p[pi] || '?'==p[pi]){
            return isMatchHelper(s,si+1,p,pi+1);
        }
        if(p[pi]=='*'){
            // let * as empty
            bool caseA=isMatchHelper(s,si,p,pi+1);
            // * consume character
            bool caseB=isMatchHelper(s,si+1,p,pi);

            return caseA || caseB ;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;
        return isMatchHelper(s,si,p,pi);
    }
};

time complexity : O(2^n) n is the size of the string