class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int count=1;
        char prev=chars[0];
        for(int next=1;next<chars.size();next++){
            if(chars[next]==prev){
                count++;
            }else{
                chars[index++]=prev;
                if(count>1){
                    int start = index;
                    while(count){
                        chars[index++]=(count%10)+'0';
                        count/=10;
                    }
                    reverse(chars.begin()+start,chars.begin()+index);
                }
                prev=chars[next];
                count=1;
            }
        }

        chars[index++]=prev;
        if(count>1){
            int start=index;
            while(count){
                chars[index++]= (count%10) + '0';
                count/=10;
            }

            reverse(chars.begin()+start,chars.begin()+index);

        }

        return index;
    }
};

// time complexity:O(n) n is the length of chars