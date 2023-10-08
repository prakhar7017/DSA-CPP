class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        for(int i=0;i<=m-n;i++){
            for(int j=0;j<n;j++){
                if(needle[j]!=haystack[i+j]) break;

                if(j==n-1) return i;
            }
        }   
        return -1;

    }
};

// time complexity:O(m*n) space complexity:O(1)
// ----------------------------------------------------------------------------------------  

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();
        int i=0;
        while(i<m){
            if(haystack.substr(i,n)==needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};

// time complexity:O(m*n) space complexity:O(1)