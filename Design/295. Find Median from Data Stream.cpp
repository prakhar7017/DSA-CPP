class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> mini;
    priority_queue<int> maxi;
    double median=0;
    MedianFinder() {
        
    }
    int signum(int a,int b){
        if(a==b){
            return 0;
        }else if(a>b){
            return 1;
        }
        return -1;
    }
    void addNum(int num) {
        switch(signum(maxi.size(),mini.size())){
            case 0:
                    if(num>median){
                        mini.push(num);
                        median = mini.top();
                    }else{
                        maxi.push(num);
                        median = maxi.top();
                    }
                    break;
            case 1:
                    if(num>median){
                        mini.push(num);
                    }else{
                        int maxiTop=maxi.top();
                        maxi.pop();
                        mini.push(maxiTop);
                        maxi.push(num);
                    }
                    median = (mini.top() + maxi.top()) / 2.0;
                    break;
            case -1:
                    if(num>median){
                        int miniTop=mini.top();
                        mini.pop();
                        maxi.push(miniTop);
                        mini.push(num);
                    }else{
                        maxi.push(num);
                    }
                    median = (mini.top() + maxi.top()) / 2.0;
                    break;
        }
    }
    
    double findMedian() {
        switch(signum(maxi.size(),mini.size())){
            case 0:
                    return median;
            case 1:
                    return maxi.top();
            case -1:
                    return mini.top();
            default:
                    return 0;
        }
    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */