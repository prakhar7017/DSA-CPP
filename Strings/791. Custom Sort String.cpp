class Solution {
public:
    string customSortString(string order, string s) {
        int count[26]={0};
        for(char &ch:s){
            count[ch-'a']++;
        }
        string result="";
        // phle order ke elemets push karing
        for(char ch:order){
            while(count[ch-'a']>0){
                result.push_back(ch);
                count[ch-'a']--;
            }
        }
        // left over char
        for(char ch:s){
            while(count[ch-'a']>0){
                result.push_back(ch);
                count[ch-'a']--;
            }
        }
        return result;
    }
};

//time complexity: O(n)
//space complexity: O(1)

//--------------------------------------------------------------------------------

// using lamda function
class Solution {
public:
    string customSortString(string order, string s) {
        auto lamda=[&order](char ch1,char ch2){
            return order.find(ch1)<order.find(ch2);
        };
        sort(s.begin(),s.end(),lamda);
        return s;
    }
};
//time complexity: O(nlogn)
//space complexity: O(1)


