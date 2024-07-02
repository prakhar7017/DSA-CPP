class Solution {
public:
    bool checkBipartite(int node,int currColor,vector<int>&colored,vector<int>adj[]){
        colored[node]=currColor;
        
        for(int nbrNode:adj[node]){
            if(colored[nbrNode]==currColor){
                return false;
            }
            if(colored[nbrNode]==-1){
                int color=1-currColor;
                bool ans=checkBipartite(nbrNode,color,colored,adj);
                if(ans==false){
                    return false;
                } 
            }
        }
        return true;
    }
    
    bool checkBipartiteBFS(int node,int currColor,vector<int>&colored,vector<int>adj[]){
        queue<int>q;
        q.push(node);
        colored[node]=currColor;
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(int nbrNode:adj[frontNode]){
                if(colored[nbrNode]==colored[frontNode]){
                    return false;
                }
                if(colored[nbrNode]==-1){
                    q.push(nbrNode);
                    colored[nbrNode]=1-colored[frontNode];
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>colored(V,-1);
	    for(int node=0;node<V;node++){
	        if(colored[node]==-1){
	            bool ans=checkBipartiteBFS(node,0,colored,adj);
	            if(ans==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

// time complexity : o(n+e)
// space complexity : o(n)