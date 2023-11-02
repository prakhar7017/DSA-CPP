#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze,int row,int col,int newx,int newy,vector<vector<bool>>&visited){
  if((newx>=0 && newx <row) && (newy>=0 && newy <col) && (maze[newx][newy]==1) && visited[newx][newy]==false){
    return true;
  }else{
    return false;
  }
}

void ratMazeHelper(vector<vector<int>> &maze,int &row,int &col,int srcx,int srcy,string &output,vector<vector<bool>>&visited){
  //base case
  if(srcx==row-1 && srcy==col-1){
    cout<<output<<endl;
  }
  //processing
  //down
  int newx=srcx+1;
  int newy=srcy;
  if(isSafe(maze,row,col,newx,newy,visited)){
    // mark visited
    visited[newx][newy]=true;
    // recursion
    output.push_back('D');
    ratMazeHelper(maze,row,col,newx,newy,output,visited);
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;
  }
  
  //right
  newx=srcx;
  newy=srcy+1;
  if(isSafe(maze,row,col,newx,newy,visited)){
    // mark visited
    visited[newx][newy]=true;
    // recursion
    output.push_back('R');
    ratMazeHelper(maze,row,col,newx,newy,output,visited);
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;
  }

  //left
  newx=srcx;
  newy=srcy-1;
  if(isSafe(maze,row,col,newx,newy,visited)){
    // mark visited
    visited[newx][newy]=true;
    // recursion
    output.push_back('L');
    ratMazeHelper(maze,row,col,newx,newy,output,visited);
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;
  }
  //up
  newx=srcx-1;
  newy=srcy;
  if(isSafe(maze,row,col,newx,newy,visited)){
    // mark visited
    visited[newx][newy]=true;
    // recursion
    output.push_back('U');
    ratMazeHelper(maze,row,col,newx,newy,output,visited);
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;
  }
}

int main() {
  vector<vector<int>>maze={{1,1,1},{1,0,1},{1,1,1}};
  int srcx=0;
  int srcy=0;
  int row=maze.size();
  int col=maze[0].size();
  string output="";
  vector<vector<bool>>visited(row,vector<bool>(col,false));
  if(maze[0][0]==0){
    cout<<"No Path Exist for rat"<<endl;
  }else{
    visited[srcx][srcy]=true;
    ratMazeHelper(maze,row,col,srcx,srcy,output,visited);
  }
  return 0;
}

// time comlexity: O(4^(n^2)) where n is the size of maze