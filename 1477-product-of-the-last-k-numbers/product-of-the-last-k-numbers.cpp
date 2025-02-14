class ProductOfNumbers {
    private:
    vector<int>st;
    int n;
public:
    ProductOfNumbers() {
        st.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            st.clear();
            n=0;
        }else {
            if(st.empty()){
                st.push_back(num);
            }else{
                st.push_back(num*st[n-1]);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k>n) return 0;
        else if(k==n) return st[n-1];
        return st[n-1]/st[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */