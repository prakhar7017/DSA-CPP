#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
// unweighted graph
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
};

int main() {
  Graph<int>g;
  g.addEdge(1,2,1);
  g.addEdge(1,3,1);
  g.addEdge(3,4,1);
  g.addEdge(4,2,1);
  return 0;
}


// weighted Graph
template <typename T>
class Graph{
  public:
    unordered_map<T,list<pair<T,int>>>adjList; //u->[{v,wt},{v,wt}]
    void addEdge(T u,T v,int wt,bool direction){
      // direction -> 0 ->undirected 
      // direction -> 1 ->directed 
      if(direction==1){
        adjList[u].push_back({v,wt});
      }else{
        // undirected 
        // u -> v
        // v -> u
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
      }
    }

    void printAdjList(){
      for(auto i:adjList){
        cout<< i.first <<  "-> { ";
        for(auto nbr:i.second){
          cout<<"{"<<nbr.first<<","<<nbr.second<<"}";
        }    
        cout<<"}"<<endl;
      }
    }
};

int main() {
  Graph<int>g;
  g.addEdge(1,2,2,1);
  g.addEdge(1,3,2,1);
  g.addEdge(3,4,2,1);
  g.addEdge(4,2,2,1);
  g.printAdjList();
  return 0;
}