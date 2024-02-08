#include <iostream>
using namespace std;

class TrieNode{

  public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char value):value(value),isTerminal(false){
      for(int i=0;i<26;i++){
      children[i]=NULL;
      }
    }
};

void deleteWord(TrieNode* root,string word){
  // base case
  if(word.length()==0){ // string finished
    // just check is terminal
    root->isTerminal=false;
  }

  char ch=word[0];
  int index=ch-'a';
  TrieNode* newRoot;
  if(root->children[index]!=NULL){
    // req char found . call recursion to go orr aage 
    newRoot=root->children[index];
    return deleteWord(newRoot,word.substr(1));
  }else{
    // req char not found in root children array, means not found
    return;
  }
}

bool searchingWord(TrieNode* root,string word){
  // base case
  if(word.length()==0){ // string finished
    // just check is terminal
    return root->isTerminal;
  }

  char ch=word[0];
  int index=ch-'a';
  TrieNode* newRoot;
  if(root->children[index]!=NULL){
    // req char found . call recursion to go orr aage 
    newRoot=root->children[index];
    return searchingWord(newRoot,word.substr(1));
  }else{
    // req char not found in root children array, means not found
    return false;
  }
}

void insertWord(TrieNode* root,string word){
  // base case
  if(word.length()==0){ // word length 0 hofi tab root last char ko point kar rhi hogi
    root->isTerminal=true;
    return;
  }

  // find first char of word
  char ch=word[0];
  // get the corresponding index
  int index=ch-'a';
  // check karo ki root ki children array ma iss index ka corresponding kya koi node padi hua hh . agar koi node phle sa padi hui hh to simple usse node par travel kar jao , or agar uss index par koi node nhi padi hua hh toh simple uss index par wo node daal do. node dalne ke baad agge badh jao using recursion
  TrieNode* newRoot;
  if(root->children[index]!=NULL){ // mtlb index par koi node hh 
    newRoot=root->children[index]; // newRoot will point at that node of index
  }else{ // mtlb index par koi bhi node nhi hh
    newRoot=new TrieNode(ch); // make the now node to put at that index
    root->children[index]=newRoot; // putiing the newRoot at index
  }

  // recusing calling
  insertWord(newRoot,word.substr(1));
}

int main() {
  TrieNode* root=new TrieNode('_');
  insertWord(root,"car");
  insertWord(root,"care");
  insertWord(root,"love");
  insertWord(root,"dove");
  insertWord(root,"lonly");
  insertWord(root,"caring");
  insertWord(root,"cutie");

  if(searchingWord(root,"cutie")){
    cout<<"founded"<<endl;
  }else{
    cout<<"not found"<<endl;
  }

  deleteWord(root,"cutie");
  if(searchingWord(root,"cutie")){
    cout<<"founded"<<endl;
  }else{
    cout<<"not found"<<endl;
  }

  return 0;
}