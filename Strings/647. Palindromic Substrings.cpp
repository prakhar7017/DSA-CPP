class Solution {
public:
    int expand(string &s,int i,int j){
        int subStringCount=0;
        int n=s.length();
        while(i>=0 && j<n && s[i]==s[j]){
            //expanding
            subStringCount++;
            --i;
            ++j;
        }
        return subStringCount;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int oddLengthAns=expand(s,i,i);
            int evenLengthAns=expand(s,i,i+1);
            ans=ans+oddLengthAns+evenLengthAns;
        }
        return ans;
    }
};
// appoach:
// applying expand function on each character of the string
// if the string is of odd length then expand function will return the count of palindromic substring of odd length
// if the string is of even length then expand function will return the count of palindromic substring of even length
// adding both the counts to get the final answer
// for eg  [ a | b | c ] odd length
        //  i,j  matched so oddcount=1 and expand to left and right
        // [ a | b | c ]
        //      ij   matched so oddcount=2 and expand to left and right
        // [ a | b | c ]
        //          ij   matched so oddcount=3 and expand to left and right

// for eg  [ a | b | a ] even length
//           i   j  not matched so evencount=0 and expand to left and right 
// for eg  [ a | b | a ] even length
//               i   j  not matched so evencount=0 and expand to left and right 

// final answer=3+0=3
// time complexity is O(n^2)
// space complexity is O(1)