#include <iostream>
#include <vector>
#include <string>
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

void storeString(TrieNode* root,vector<string>&ans,string prefix,string &suffix){
  // base case
  if(root->isTerminal==true){
    ans.push_back(prefix+suffix);
  }

  for(char ch='a';ch<'z';ch++){
    int index=ch-'a';
    TrieNode* next=root->children[index];
    if(next!=NULL){
      suffix.push_back(ch);
      storeString(next,ans,prefix,suffix);
      // backtrack
      suffix.pop_back();
    }
  }
}

void findSuffixString(TrieNode* root,vector<string>&ans,string userInput,string &prefix,string &suffix){
  // base case
  if(userInput.length()==0){
    TrieNode* lastChar=root;
    storeString(lastChar,ans,prefix,suffix);
    return;
  }
  char ch=userInput[0];
  int index=ch-'a';
  TrieNode* newRoot;
  if(root->children[index]!=NULL){
    newRoot=root->children[index];
    findSuffixString(newRoot,ans,userInput.substr(1),prefix,suffix);
  }else{
    return;
  }
}

vector<vector<string>>getSuggestion(TrieNode* root,string userInput){
  TrieNode* prev=root;
  vector<vector<string>>output;
  string prefix="";
  string suffix="";
  for(int i=0;i<userInput.length();i++){
    char lastChar=userInput[i];
    int index=lastChar-'a';
    TrieNode* curr=prev->children[index];
    if(curr==NULL){
      break;
    }else{
      vector<string>nicheKeAns;
      prefix.push_back(lastChar);
      storeString(curr,nicheKeAns,prefix,suffix);
      output.push_back(nicheKeAns);
    }
    prev=curr;
  }
  return output;
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

  // if(searchingWord(root,"cutie")){
  //   cout<<"founded"<<endl;
  // }else{
  //   cout<<"not found"<<endl;
  // }

  // deleteWord(root,"cutie");
  // if(searchingWord(root,"cutie")){
  //   cout<<"founded"<<endl;
  // }else{
  //   cout<<"not found"<<endl;
  // }

  vector<string>ans;
  string userInput="ca";
  string prefix=userInput;
  string suffix="";

  // findSuffixString(root,ans,userInput,prefix,suffix);
  // for(auto word:ans){
  //   cout<<word<<" ";
  // }cout<<endl;

  vector<vector<string>> ans1=getSuggestion(root,userInput);
  for(auto i:ans1){
    for(auto word:i){
      cout<<i<<" ";
    }
  }
  cout<<endl;

  return 0;
}