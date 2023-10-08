class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string>zigzag(numRows);
        int row=0;
        int i=0;
        int dir=1;
        while(true){
            if(dir){
                while(row<numRows && i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row=numRows-2;
            }else{
                while(row>=0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
            if(i>=s.size()){
                break;
            }
            dir=!dir;
        }
        string ans="";
        for(int i=0;i<zigzag.size();i++){
            ans+=zigzag[i];
        }
        return ans;
    }

};

// time complexity: O(n)  n is the length of the string 