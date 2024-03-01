#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
// unweighted graph
class Graph{
  public:
    unordered_map<T,list<T>>adjList;
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