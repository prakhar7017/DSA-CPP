// Brute Force 
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int rowS=arr[i].size();
            for(int j=0;j<rowS;j++){
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};

//optimized solution using min-heap
class Node {
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col) : data(data), row(row), col(col) {};
};

class compare {
public:
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        // step 1: Insert the first element of each array into the min heap.
        for (int i = 0; i < K; i++) {
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }

        vector<int> ans;

        // step 2: Merge the arrays using the min heap.
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            ans.push_back(temp->data);
            int row = temp->row;
            int col = temp->col;

            if (col + 1 < arr[row].size()) {
                Node* temp = new Node(arr[row][col + 1], row, col + 1);
                pq.push(temp);
            }
        }

        return ans;
    }
};

