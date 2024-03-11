#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
class Graph{
  public:
  unordered_map<int,list<int>>adjList;
  void addEdge(int u,int v,bool dir){
    // undirected
    if(dir==0){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }else{
        adjList[u].push_back(v);
    }
  }
  void printAdj(){
    for(auto i:adjList){
      cout<<i.first<<"->{";
      for(auto j:i.second){
        cout<<j<<" ,";
      }
    cout<<"}"<<endl;
    }
  }
  void findBridge(int src,int parent,vector<int> &tin,vector<int> &low,int &timer,unordered_map<int,bool>vis){
    vis[src]=true;
    tin[src]=timer;
    low[src]=timer;
    timer++;
    for(auto nbr:adjList[src]){
      // avoid goining to parent
      if(nbr==parent) continue;
      if(!vis[nbr]){
        // dfs call,
        findBridge(nbr,src,tin,low,timer,vis);
        // update low
        low[src]=min(low[src],low[nbr]);
        // check for bridge
        if(low[nbr]>tin[src]){
          cout<<src<<" "<<nbr<<endl;
        }
      }else{
        // already vis node
        low[src]=min(low[src],tin[nbr]);
      }
    }
  }
};
int main() {
  Graph g;
  g.addEdge(1,0,0);
  g.addEdge(1,2,0);
  g.addEdge(0,2,0);
  g.addEdge(0,3,0);
  g.addEdge(3,4,0);
  // g.printAdj();
  int n=5;
  vector<int>low(n);
  vector<int>tin(n);
  unordered_map<int,bool>vis;
  int timer=1;
  g.findBridge(0,-1,tin,low,timer,vis);
  return 0;
}

// Time Complexity: O(V+E)
// Auxiliary Space: O(V) is used for visited, disc and low arrays.