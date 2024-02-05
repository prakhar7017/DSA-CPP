class Info {
public:
    char val;
    int count;
    Info(char val, int count) : val(val), count(count) {}
};

class compare {
public:
    bool operator()(Info a, Info b) {
        return a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int freq[26] = {0};
        // count freq of all characters in string
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<Info, vector<Info>, compare> pq;

        // push all characters into max heap
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char val = i + 'a';
                int frequency = freq[i];
                Info temp(val, frequency);
                pq.push(temp);
            }
        }

        string ans="";
        while(pq.size()>1){
            Info first=pq.top();
            pq.pop();
            Info sec=pq.top();
            pq.pop();
            ans.push_back(first.val);
            first.count--;
            ans.push_back(sec.val);
            sec.count--;
            if(first.count>0){
                pq.push(first);
            }
            if(sec.count>0){
                pq.push(sec);
            }
        }

        if(pq.size()==1){
            Info first=pq.top();
            pq.pop();
            ans.push_back(first.val);
            first.count--;
            if(first.count>0){
                return "";
            }
        }

        return ans;
    }
};
