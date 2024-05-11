// Brute Force
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n=quality.size();
        double result=DBL_MAX;

        for(int manager=0;manager<n;manager++){
            double managerRatio=(double)min_wage[manager]/quality[manager];

            vector<double> group;

            for(int worker = 0; worker < n; worker++ ){
                double workerWage=managerRatio*quality[worker];
                if(workerWage>=min_wage[worker]){
                    group.push_back(workerWage);
                }
            }

            if(group.size()<k){
                continue;
            }

            priority_queue<double,vector<double>>pq;
            double sum=0;

            for(double &wage : group){
                sum+=wage;
                pq.push(wage);

                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
            }
            result = min(result,sum);
        }
        return result;
    }
};

//Time complexity : O(n * (n + klogk))
//Space complexity : O(n+k)








// Better Brute Force
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
        for(int manager=k-1;manager<n;manager++){
            double managerRatio=worker_ratio[manager].first;

            vector<double> group;

            for(int worker = 0; worker <=manager; worker++ ){
                double workerWage=managerRatio*worker_ratio[worker].second;
                group.push_back(workerWage);
            }

            priority_queue<double,vector<double>>pq;
            double sum=0;

            for(double &wage : group){
                sum+=wage;
                pq.push(wage);

                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
            }
            result = min(result,sum);
        }
        return result;
    }
};
//Time Complexity: O(nlogn + n * (n + klogk)) - This is worst case when no one got eliminated 
//Space Complexity : O(n+k)



// optimal solution
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

//Time Complexity : O(nlogn + klogk + n*log(k))
//Space Complexity : O(n+k)