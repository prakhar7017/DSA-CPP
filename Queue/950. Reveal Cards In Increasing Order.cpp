/*
    950. Reveal Cards In Increasing Order
    You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

    You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

    You will do the following steps repeatedly until all cards are revealed:

    Take the top card of the deck, reveal it, and take it out of the deck.
    If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
    If there are still unrevealed cards, go back to step 1. Otherwise, stop.
    Return an ordering of the deck that would reveal the cards in increasing order.

    Note that the first entry in the answer is considered to be the top of the deck.

    link : https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        queue<int>q;
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            q.push(i); // pushing the index of the deck
        }

        sort(begin(deck),end(deck));

        for(int i=0;i<n;i++){

            int index=q.front();
            q.pop();

            ans[index]=deck[i];

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};

// time complexity : O(nlogn)
// space complexity : O(n)


//---------------------------------------------------------------------------------

// without using queue
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n,0);
        sort(begin(deck),end(deck));
        int i=0;
        int j=0;
        bool skip=false;
        while(i<n){
            if(ans[j]==0){ // mtlb jagah kahli hh 
                if(skip==false){ // kya mujhe ise skip karna hh 
                    ans[j]=deck[i];
                    ++i; // i tabhi badega jab number pad jayega ans ma
                }
                skip=!skip; // alternate
            }
            j=(j+1)%n; // circular rotation of indexes
        }
        return ans;
    }
};

// time complexity : O(nlogn)
// space complexity : auxilary space O(n)