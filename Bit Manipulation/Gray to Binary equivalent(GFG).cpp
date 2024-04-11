/*
    Gray to Binary equivalent
    Given an integer number n, which is a decimal representation of Gray Code. Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.
*/

class Solution{
    public:
    string decimalToBinary(int n){
        string ans="";
        while(n!=0){
            int bit=n&1; // 1 or 0 could be be values here 
            ans+=(bit+'0'); // conversion of int to string
            n>>=1; // right shift means divide by 2 
        }
        reverse(begin(ans),end(ans)); // reverse 
        return ans;
    }
    
    string binarytoGray(string bin){
        string ans="";
        ans+=bin[0]; // fillin msb 
        for(int i=1;i<bin.length();i++){
            int bit=(ans[i-1]-'0')^(bin[i]-'0'); // ans[i]=ans[i-1]^bin[i]
            ans+=(bit+'0'); // conversion to char
        }
        return ans;
    }
    
    int binaryToDecimal(string gray){
        int ans=0;
        reverse(begin(gray),end(gray)); // reversiong
        for(int i=0;i<gray.length();i++){
            if(gray[i]=='1'){
                ans+=(gray[i]-'0')*pow(2,i);
            }
        }
        return ans;
    }
    
    int grayToBinary(int n)
    {
        if(n==0) return 0;
        
        string bin=decimalToBinary(n);
        string gray=binarytoGray(bin);
        int ans=binaryToDecimal(gray);
        return ans;
        
    }
};

// Time Complexity: O(log2(n))
// Space Complexity: O(log2(n))

// link : https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1