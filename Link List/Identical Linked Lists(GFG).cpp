/*
    Identical Linked Lists

    Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
    Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

*/

bool areIdentical(struct Node *head1, struct Node *head2) {
    if(head1==nullptr && head2==nullptr){
        return true;
    }
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if((temp1!=nullptr && temp2==nullptr) || (temp1==nullptr && temp2!=nullptr)){
        return false;
    }    
    return true;
}

// time complexity:o(n);
// space complexity:o(1);