class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long long sum = accumulate(chalk.begin(), chalk.end(), 0LL); 
    int t = k % sum; 
    for (int i = 0; i < n; ++i) {
        if (t < chalk[i]) {
            return i; 
        }
        t -= chalk[i]; 
    }


    return -1;
}

};