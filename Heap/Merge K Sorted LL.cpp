// optimized solution using min-heap
#include<queue>
class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data>b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare>pq;

    int k=listArray.size();
    if(k==0){
        return NULL;
    }

    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            pq.push(listArray[i]);
        }
    }

    Node<int>* head=NULL;
    Node<int>* tail=NULL;

    while(!pq.empty()){
        Node<int>* temp=pq.top();
        pq.pop();

        if(temp->next!=NULL){
            pq.push(temp->next);
        }

        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }

    }
    return head;

}