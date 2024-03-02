#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

// BFS -> Breadth First Search
template <typename T>
class Graph{
  public:
    unordered_map<T,list<T>>adjList; // u-> [v1,v2,v3,v4]
    void addEdge(T u,T v,bool direction){
      // direction -> 0 ->undirected 
      // direction -> 1 ->directed 
      if(direction==1){
        adjList[u].push_back(v);
      }else{
        // undirected 
        // u -> v
        // v -> u
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
    }

    void printAdjList(){
      for(auto i:adjList){
        cout<< i.first <<  "-> { ";
        for(auto nbr:i.second){
          cout<<nbr<<",";
        }    
        cout<<"}"<<endl;
      }
    }


    // BFS -> Breadth First Search
    void bfs(T src){
      unordered_map<T,bool>vis;
      for(auto i:adjList){
        vis[i.first]=false;
      }
      queue<T>q;
      q.push(src);
      vis[src]=true;

      while(!q.empty()){
        T frontNode=q.front();
        q.pop();
        cout<<frontNode<<" ,";
        for(auto i:adjList[frontNode]){
          if(!vis[i]){
            q.push(i);
            vis[i]=true;
          }
        }

      }

    }


    // dfs -> Depth First Search
      void dfs(T src,unordered_map<T,bool>&vis){
      vis[src]=true;
      cout<<src<<" ";
      for(auto nbr:adjList[src]){
        if(!vis[nbr]){
          dfs(nbr,vis);
        }
      }
    }
};

int main() {
  // bfs
  Graph<char>g;
  g.addEdge('a','b',0);
  g.addEdge('a','b',0);
  g.addEdge('b','c',0);
  g.addEdge('b','d',0);
  g.addEdge('c','e',0);
  g.addEdge('c','f',0);
  g.addEdge('e','f',0);

  g.bfs('a');



  // dfs
   Graph<int>g;
  g.addEdge(0,4,0);
  g.addEdge(4,2,0);
  g.addEdge(2,3,0);
  g.addEdge(3,5,0);
  g.addEdge(5,1,0);
  g.addEdge(1,4,0);

  unordered_map<int,bool>vis;
  g.dfs(0,vis);
  return 0;
}
