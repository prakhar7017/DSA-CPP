class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head){
            return;
        }   
        if(!head->next){
            return;
        }
        
        Node* it=head;
        for(int i=0;i<M-1;i++){
            if(it!=NULL){
                it=it->next;
            }
        }
        if(!it){
            return;
        }
        Node* mthNode=it;
        it=mthNode->next;
        for(int i=0;i<N;i++){
            if(it!=NULL){
                Node* temp=it->next;
                it->next=NULL;
                delete it;
                it=temp;
            }
        }
        
        mthNode->next=it;
        linkdelete(it,M,N);
    }
};


// time complexity:O(n)
// space complexity:O(1)
// key not: ensure linking of pointers properly and delete the nodes properly and ensure while skipping pointer dont get null 