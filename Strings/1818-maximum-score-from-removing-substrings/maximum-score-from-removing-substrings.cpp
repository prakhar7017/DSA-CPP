class Solution {
public:
    string removeSubStr(string &s, string &matchStr){
        int i=0; // used for writing purpose

        // j used for reading purpose
        for(int j=0;j<s.length();j++){
            s[i]=s[j]; // writing on index i whatever j reads
            ++i;

            if(i>=2 && s[i-2]==matchStr[0] && s[i-1]==matchStr[1]){
                // found matchStr before i
                i-=2;
            }
        }

        s.erase(begin(s)+i,end(s));

        return s;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int score=0;

        string maxStr=(x>y) ? "ab" : "ba";
        string minStr=(x<y) ? "ab" : "ba";

        // first pass
        string firstPass=removeSubStr(s,maxStr);
        int L=firstPass.length();

        int charRemoved=(n-L);
        score+=(charRemoved/2) * max(x,y);

        // second pass
        string secondPass=removeSubStr(firstPass,minStr);
        int secLen=secondPass.length();

        charRemoved=(L-secLen);
        score+=(charRemoved/2) * min(x,y);

        return score;
    }
};