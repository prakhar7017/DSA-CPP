#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i) {
    int leftIndex = 2 * i; // leftChild
    int rightIndex = 2 * i + 1; // rightChild

    int largest = i; // largest pointing to parent

    // find largest of all three parent, leftChild, rightChild
    if (leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    // if parent is not largest then swap parent with largest
    if (i != largest) {
        swap(arr[i], arr[largest]);
        i = largest;
        heapify(arr, n, i);
    }
}


void buildHeap(int *arr, int n) {
    int pos = n >> 1; // n/2
    // all leaf node are lies in range [n/2+1,n] so we don't need to heapify them.
    // we need to heapify only non-leaf node which are lies in range [1,n/2]
    for (int i = pos; i > 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int arr[] = {-1,5, 10, 15, 20, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Heapify" << endl;
    for (int i = 1; i < n; i++) {
        cout << arr[i] << " ";
    }

    buildHeap(arr, n);

    cout << endl << "After Heapify" << endl;;
    for (int i = 1; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
