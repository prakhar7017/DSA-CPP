    public:
    void sort012(int arr[], int n)
    {
        int l=0;
        int r=n-1;
        int index=0;
        while(index<=r){
            if(arr[index]==0){
                swap(arr[index++],arr[l++]);
            }else if(arr[index]==2){
                swap(arr[index],arr[r--]);
            }else{
                index++;
            }
        }
    }