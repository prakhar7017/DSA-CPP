class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        unordered_map<int,ListNode*>mp;
        ListNode* dummyNode=new ListNode(0);
        dummyNode->next=head;
        mp[0]=dummyNode;

        while(head!=NULL){
            prefixSum+=head->val;
            if(mp.find(prefixSum)!=mp.end()){
                ListNode* start=mp[prefixSum];
                ListNode* temp=start;
                int pSum=prefixSum;
                while(temp!=head){
                    temp=temp->next;
                    pSum+=temp->val;
                    if(temp!=head){
                        mp.erase(pSum);
                    }
                }
                start->next=head->next;
            }else{
                mp[prefixSum]=head;
            }
            head=head->next;
        }
        return dummyNode->next;
    }
};