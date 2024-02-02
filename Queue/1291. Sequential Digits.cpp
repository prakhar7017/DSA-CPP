class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front>=low && front<=high){
                ans.push_back(front);
            }
            int lastDigit=front%10;
            if((lastDigit+1)<=9){
                int newNumber=(front*10)+(lastDigit+1);
                q.push(newNumber);
            }
        }   
        return ans;
    }
};

// time complexity o(n);
// space complexity o(n);


//************************Python Solution************************
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        q=deque()
        ans=[]
        for i in range(1,9):
            q.append(i)

        while q:
            front =q.popleft()
            if front >= low and front <= high:
                ans.append(front)
            last_digit = front % 10
            if (last_digit + 1) <= 9:
                new_number = (front * 10) + (last_digit + 1)
                q.append(new_number)
                
        return ans
// time complexity o(n);
// space complexity o(n);