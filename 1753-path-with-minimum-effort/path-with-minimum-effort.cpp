class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,1},{1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>dist(rows+1,vector<int>(cols+1,INT_MAX));

        auto isSafe=[&](int newX,int newY){
            return newX>=0 && newX<rows && newY>=0 && newY<cols;
        };

        set<pair<int,pair<int,int>>>st;

        st.insert({0,{0,0}});
        dist[0][0]=0;

        while(!st.empty()){
            auto topElement=st.begin();
            auto topPair=*topElement;
            int srcDiff=topPair.first;
            pair<int,int>srcCorr=topPair.second;
            int x=srcCorr.first;
            int y=srcCorr.second;
            st.erase(st.begin());

            for(vector<int>&dir:directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];

                if(isSafe(new_x,new_y)){
                    int absDiff=abs(heights[x][y]-heights[new_x][new_y]);
                    int maxDiff=max(srcDiff,absDiff);
                    if(maxDiff<dist[new_x][new_y]){
                        auto prevEntry=st.find({dist[new_x][new_y],{new_x,new_y}});
                        if(prevEntry!=st.end()){
                            st.erase(prevEntry);
                        }
                        dist[new_x][new_y]=maxDiff;
                        st.insert({dist[new_x][new_y],{new_x,new_y}});
                    }
                }
            }
        }
        return dist[rows-1][cols-1];
    }
};