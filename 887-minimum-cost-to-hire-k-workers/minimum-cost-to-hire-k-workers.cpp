class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n=quality.size();
        double result=DBL_MAX;

        vector<pair<double,int>>worker_ratio(n);
        for(int worker=0;worker<n;worker++){
            worker_ratio[worker]=make_pair((double)min_wage[worker]/quality[worker],quality[worker]);
        }

        sort(begin(worker_ratio),end(worker_ratio));

        priority_queue<int,vector<int>>pq;

        double sumQuality=0;
        for(int i=0;i<k;i++){
            pq.push(worker_ratio[i].second);
            sumQuality+=worker_ratio[i].second;
        }

        double managerRatio=worker_ratio[k-1].first;
        result= managerRatio*sumQuality;


        for(int manager=k;manager<n;manager++){
            managerRatio=worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second);
            sumQuality+=worker_ratio[manager].second;

            if(pq.size()>k){
                sumQuality-=pq.top();
                pq.pop();
            }

            result=min(result,managerRatio*sumQuality);
        }
        return result;
    }
};