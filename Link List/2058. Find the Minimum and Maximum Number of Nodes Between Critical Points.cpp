class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1}; // [minDist,maxDist]
        ListNode* prev=head;
        if(!prev) return ans; // NULL
        ListNode* curr=head->next;
        if(!curr) return ans; // X->NULL;
        ListNode* nextNode=curr->next;
        if(!nextNode) return ans; // X->X1->NULL

        int firstCP=-1;
        int lastCP=-1;
        int minDist=INT_MAX;
        int i=1;
        while(nextNode){     // 5 -> 3 -> 1 -> 2-> NULL
                                      // prev curr nextNode  invalid arrangement
            
            bool isCP=((curr->val>prev->val && curr->val>nextNode->val) 
                        ||(curr->val<prev->val && curr->val<nextNode->val));
            
            if(isCP && firstCP==-1){
                firstCP=i;
                lastCP=i;
            }else if(isCP){
                minDist=min(minDist,i-lastCP);
                lastCP=i;
            }
            ++i;
            prev=curr;
            curr=nextNode;
            nextNode=nextNode->next;
        }

        if(lastCP==firstCP){
            // means ek CP mila
            return ans;
        }else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }

        return ans;
    }
};

// time complexity:O(n) space complexity:O(1)

// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/




