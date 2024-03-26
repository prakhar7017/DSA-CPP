class Solution {
  public:
    string findSum(string a , string b){
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        string ans="";
        while(i>=0 && j>=0){
            int sum=(a[i]-'0')+(b[j]-'0')+carry;
            ans+=(sum%10+'0');
            carry=(sum/10);
            --j;
            --i;
        }
        while(i>=0){
            int sum=(a[i]-'0')+carry;
            ans+=(sum%10+'0');
            carry=(sum/10);
            --i;
        }
        while(j>=0){
            int sum=(b[j]-'0')+carry;
            ans+=(sum%10+'0');
            carry=(sum/10);
            --j;
        }
        if(carry){
            ans+=(carry+'0');
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
    bool isAdditiveSequence_helper(string a,string b,string c){
        string sum=findSum(a,b);
        int i=0,j=0;
        while(i<c.length() && j<sum.length()){
            if(c[i]!=sum[j]){ // if any charc of c doest not match with  charc of sum 
                return false;
            }
            ++i;
            ++j;
        }
        if(j!=sum.length()) return false; // if j doest not reach end mtlb c phel he khtm hogyi
        if(i==c.length()) return true; // agar c pura traverse hogya iska mltb sum milgya 
        // c pura travers hogya 
        // j sum ke end tak bhi poch gya, mltb ek sum mil gya ab aage 
        // update kardo c ko ,with remaining c ke charac
        c=c.substr(i);
        // a=b;
        // b=sum;
        // c
        return isAdditiveSequence_helper(b,sum,c);
    }
    bool isAdditiveSequence(string n) {
        int size=n.length();
        int len=size>>1;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<size;j++){
                string a=n.substr(0,i+1);
                string b=n.substr(i+1,j-i);
                string c=n.substr(j+1);
                if(isAdditiveSequence_helper(a,b,c))
                    return true;
            }
        }
        return false;
    }
};

// time complexity : o(n^2)
// space complexity : o(n)