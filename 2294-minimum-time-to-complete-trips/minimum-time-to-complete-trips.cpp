class Solution {
public:
    int bruteForce(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long curr_time = 1;
        while (true) {
            int trips = 0;
            for (int i = 0; i < n; i++) {
                trips += curr_time / time[i];
            }
            if (trips >= totalTrips)
                break;
            curr_time++;
        }
        return curr_time;
    }

    bool possible_ki_totalTrips_kar_pye(vector<int>& time, long long mid,
                                        int totalTrips) {
        long long trips = 0;
        for (int& t : time) {
            trips += mid / t;
            if (trips >= totalTrips) {
                return true;
            }
        }
        return false;
    }
    long long solveUsingBS(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long s = 1;
        long long e =
            (long long)*min_element(begin(time), end(time)) * totalTrips;
        while (s < e) {
            long long mid = s + (e - s) / 2;
            if (possible_ki_totalTrips_kar_pye(time, mid, totalTrips)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        return solveUsingBS(time, totalTrips);
    }
};