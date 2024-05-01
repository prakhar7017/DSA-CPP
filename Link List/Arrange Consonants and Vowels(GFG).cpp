/*
    Arrange Consonants and Vowels
    Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

*/

class Solution {
  public:
    bool isVowel(Node* &head){
        int data=head->data;
        if(data=='a' || data=='e' || data=='i' || data=='o' || data=='u'){
            return true;
        }
        return false;
    }
    struct Node* arrangeCV(Node* head) {
        if(!head) return nullptr;
        Node* vHead=new Node(-1);
        Node* cHead=new Node(-1);
        Node* vDummy=vHead;
        Node* cDummy=cHead;
        
        while(head!=nullptr){
            if(isVowel(head)){
                vDummy->next=new Node(head->data);
                vDummy=vDummy->next;

            }else{
                cDummy->next=new Node(head->data);
                cDummy=cDummy->next;
            }
            head=head->next;
        }
        
        vDummy->next=cHead->next;
        Node* ans=vHead->next;
        delete cHead;
        delete vHead;
        
        return ans;
        
    }
};

// time complexity: O(n)
// space complexity: O(1)