class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        if (head1==NULL || head2==NULL) return 0;
        unordered_set<int>st;
        Node* temp=head2;
        while(temp!=NULL){
            st.insert(temp->data);
            temp=temp->next;
        }
        temp=head1;
        int count=0;
        while(temp!=NULL){
            int diff=x-temp->data;
            if(st.find(diff)!=st.end()){
                count++;
            }
            temp=temp->next;
        }
        return count;
    }
};

// time complexity: O(n+m)
// space complexity: O(m)