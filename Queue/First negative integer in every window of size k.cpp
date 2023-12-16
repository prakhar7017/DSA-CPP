vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        vector<long long>ans;
        deque<int>dq;
        
        for(int i=0;i<K;i++){
            int element=A[i];
            if(element<0){
                dq.push_back(i);
            }
        }
        
        for(int i=K;i<N;i++){
            
            if(!dq.empty()){
                ans.push_back(A[dq.front()]);
            }else{
                ans.push_back(0);
            }
            
            // removal 
            if(!dq.empty() && i-dq.front()>=K){
                dq.pop_front();
            }
            
            //addition
            if(A[i]<0){
                dq.push_back(i);
            }
            
        }
        
         if(!dq.empty()){
                ans.push_back(A[dq.front()]);
        }else{
                ans.push_back(0);
        }
        
        return ans;
                                                 
 }