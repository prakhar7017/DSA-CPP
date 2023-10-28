class Solution {
    private:
    void addRec(string &num1,int p1,string &num2,int p2,string &ans,int carry=0){
        //base case
        if(p1<0 && p2<0){
            if(carry!=0){
                ans.push_back(carry+'0');
                return;
            }
            return;
        }

        //processing
        int n1=(p1>=0 ? num1[p1] : '0')-'0';
        int n2=(p2>=0 ? num2[p2] : '0')-'0';
        int sum=n1+n2+carry;
        int digit=sum%10;
        carry=sum/10;
        ans.push_back(digit+'0');

        //recursive call
        addRec(num1,p1-1,num2,p2-1,ans,carry);
    }
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int carry=0;
        addRec(num1,num1.size()-1,num2,num2.size()-1,ans,carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

time complexity : O(n) n is the size of the largest string