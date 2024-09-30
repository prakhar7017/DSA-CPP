class CustomStack {
public:
    int* arr;
    int size;
    int temp=-1;
    int a;
    CustomStack(int maxSize) {
      size=maxSize;  
      arr= new int[size];  
    }
    
    void push(int x) {
        temp++;
        if(temp<size)
        arr[temp]=x;
        else
        temp--;
        
    }
    
    int pop() {
        if(temp==-1) return -1;
        else
        a=arr[temp];
        temp=temp-1;
        return a;
       

    }
    
    void increment(int k, int val) {
       if(size<k){
        for(int i=0; i<size; i++){
            arr[i]+=val;
        }
       }
       else{
        for(int i=0; i<k; i++){
            arr[i]+=val;
        }
       }
    }
};