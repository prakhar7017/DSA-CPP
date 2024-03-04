class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(begin(tokens),end(tokens));
        int maxScore=0;
        int i=0; // score ko maximize karuga
        int j=n-1; // score lose karuga
        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                maxScore=max(maxScore,score);
                i++;
            }else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }else{
                return maxScore;
            }
        }
        return maxScore;
    }
};