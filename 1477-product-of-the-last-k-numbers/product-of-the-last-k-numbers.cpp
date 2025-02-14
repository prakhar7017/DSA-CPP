class ProductOfNumbers {
    private:
    vector<int>st;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
     int product=1;
     int n=st.size();
     if(n<2) return st[0];
     int lastKthIndex=n-k;
     for(int i=lastKthIndex;i<n;i++){
        product=product*st[i];
     }   
     return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */