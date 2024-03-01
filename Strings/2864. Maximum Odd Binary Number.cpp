class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();

        string ans=string(n,'0');

        int i=0;
        for(char ch :s){
            if(ch=='1'){
                if(ans[n-1]!='1'){
                    ans[n-1]='1';
                }else{
                    ans[i]='1';
                    i++;
                }
            }
        }
        return ans;
    }
};

// time complexity is O(n) and space complexity is O(n) where n is the length of the string s.


// using stl count function
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();

        int oneCount=count(s.begin(),s.end(),'1');
        string ans=string(n,'0');
        int i=0;
        while(oneCount--){
            if(ans[n-1]!='1') ans[n-1]='1';
            else {
                ans[i]='1';
                i++;
            }
        }
        return ans;
    }
};

// time complexity is O(n) and space complexity is O(n) where n is the length of the string s.