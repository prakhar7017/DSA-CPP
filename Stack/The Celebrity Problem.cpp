int celebrity(vector<vector<int> >& M, int n) 
    {
        // push all person in stack
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        // try to reach potential celerity untill stack is left with single element
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(M[a][b]){
                // if a knows b, then a is not celebrity
                st.push(b);
            }else{
                // if a dont knows b, then b is not celebrity
                st.push(a);
            }
        }
        
        int potentialCelebrity=st.top();
        st.pop();
        
        // check celebrity dont knows anyone,means potentialCelebrity ke sare column zero
        for(int i=0;i<n;i++){
            if(M[potentialCelebrity][i]!=0){
                return -1;
            }
        }
        
        // check all know celebrity ,means potentialCelebrity ke sare row 1 honge except iteslf
        for(int i=0;i<n;i++){
            if(M[i][potentialCelebrity]==0 && i!=potentialCelebrity){
                return -1;
            }
        }
        
        return potentialCelebrity;
        
    }