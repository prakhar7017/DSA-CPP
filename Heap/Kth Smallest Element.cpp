#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr,int n,int k){
  priority_queue<int>pq;
  // traverse first k elements
  for(int i=0;i<k;i++){
    pq.push(arr[i]);
  }

  // remaining elemets ko tabhi push karna jab wo chote ho
  for(int i=k;i<n;i++){
    int element=arr[i];
    if(element<pq.top()){
      pq.pop();
      pq.push(element);
    }
  }
  int ans=pq.top();
  return ans;
}
int main(){
  int arr[]={3,7,4,5,8,6,9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k=4;
  int ans=solve(arr,n,k);
  cout<<endl<<"Kth Smallest Element is : "<<ans;
  return 0;
}

// Time Complexity: O(nlogk)
// Space Complexity: O(k)

//*********************************Python Solution*********************************
import heapq

def solve(arr, n, k):
    max_heap = []

    for i in range(k):
        heapq.heappush(max_heap, -arr[i])
        
    for i in range(k, n):
        element = arr[i]
        if element < -max_heap[0]:
            heapq.heappop(max_heap)
            heapq.heappush(max_heap, -element)

    ans = -max_heap[0]
    return ans

if __name__ == "__main__":
    arr = [3, 7, 4, 5, 8, 6, 9]
    n = len(arr)
    k = 4

    ans = solve(arr, n, k)
    print(f"Kth Smallest Element is: {ans}")


//
In the context of the provided code, the expression -arr[i] is using the unary minus operator (-) to negate the value of arr[i]. This negation is commonly used in scenarios where you want to reverse the order of elements in a min-heap, effectively turning it into a max-heap.

Here's an example to illustrate the concept:

Suppose arr[i] has a value of 5. If you negate it using -arr[i], the result will be -5. This negation is often used when dealing with priority queues or heaps, where you want to find the Kth smallest element.

For instance, if you are using a min-heap in Python (which is the default behavior of heapq), you can negate the values before pushing them onto the heap. Later, when you pop elements from the heap, you can negate them again to obtain the original values, effectively simulating a max-heap behavior.

# Later, when you want the original value:
original_value = -negated_value
In the provided python code, the negation is used to push the negated values onto the priority queue, effectively creating a max-heap behavior for finding the Kth smallest element.