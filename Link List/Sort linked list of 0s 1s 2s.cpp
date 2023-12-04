// changing the data of the node
Node* sortList(Node *head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    Node* temp=head;
    while(temp){
        if(temp->data==0){
            zeroCount++;
        }else if(temp->data==1){
            oneCount++;
        }else{
            twoCount++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }else{
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}

// time complexity: O(n)


// **************************************************************************************************************

// changing the links of the node
void insertAtTail(Node* &tail,Node* temp){
    tail->next=temp;
    tail=temp;
}
Node* sortList(Node *head){
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    Node* temp=head;

    while(temp){
        if(temp->data==0){
            insertAtTail(zeroTail,temp);
        }else if(temp->data==1){
            insertAtTail(oneTail,temp);
        }else{
            insertAtTail(twoTail,temp);
        }
        temp=temp->next;
    }

    //merge
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeroHead->next;
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    return head;

}

// time complexity : O(n)