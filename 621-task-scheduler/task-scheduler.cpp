class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0 ) return tasks.size();

        vector<int>mp(26,0);
        for(char &ch: tasks){
            mp[ch-'A']++;
        }
        sort(begin(mp),end(mp));

        int maxFreq = mp[25];
        int gaps = maxFreq-1;
        int idelSlots = gaps*n;

        for(int i=24;i>=0;i--){
            idelSlots -= min(mp[i],gaps);
        }
        if(idelSlots>0) return tasks.size()+idelSlots;
        return tasks.size();
    }
};