#include <iostream>
#include <stack>
using namespace std;

bool isValid(char ch){
  if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
    return true;
  }else{
    return false;
  }
}

bool isRedundantBracket(string &str){
  stack<char>st;
  for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(isValid(ch)){ //opening bracket or any operator
      st.push(ch);
    }else{
      if(ch==')'){
        int opCount=0;
        while(!st.empty() && st.top()!='('){
          char temp=st.top();
          if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='%'){
            opCount++;
          }
          st.pop(); // deleteing till closing bracket
        }
        st.pop();  // deleting closing bracket

        if(opCount==0){
          return true;
        }
      }
    }
  }
  return false;

}

int main() {
  string str="(+)";

  if(isRedundantBracket(str)){
    cout<<"Redundant Bracket Present"<<endl;
  }else{
    cout<<"Redundant Bracket Not Present"<<endl;
  }

  return 0;
}