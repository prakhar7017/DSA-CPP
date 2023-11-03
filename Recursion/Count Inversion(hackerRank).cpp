long merge(vector<int> &arr,int s,int mid,int e,vector<int>&temp){
    int leftIndex=s;
    int rightIndex=mid+1;
    int mainArrayindex=s;
    long c=0;
    while(leftIndex<=mid && rightIndex<=e){
        if(arr[leftIndex]<=arr[rightIndex]){
            temp[mainArrayindex++]=arr[leftIndex++];
        }else{
            temp[mainArrayindex++]=arr[rightIndex++];
            c+=mid-leftIndex+1;
        }
    }
    while(leftIndex<=mid){
        temp[mainArrayindex++]=arr[leftIndex++];
    }
    while(rightIndex<=e){
        temp[mainArrayindex++]=arr[rightIndex++];
    }
    
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    return c;
}

 long mergeSort(vector<int> &arr,int s,int e,vector<int>&temp){
     //base case
     if(s>=e){
         return 0;
     }
     
     int mid=s+(e-s)/2;
     long c=0;
     c+=mergeSort(arr, s,mid,temp);
     c+=mergeSort(arr, mid+1, e, temp);
     c+=merge(arr,s,mid,e,temp);
     
     return c;
 }

long countInversions(vector<int> arr) {
    int size=arr.size();
    int s=0;
    int e=size-1;
    vector<int>temp(size);
    return mergeSort(arr,s,e,temp);
}

// time complexity: O(nlogn)