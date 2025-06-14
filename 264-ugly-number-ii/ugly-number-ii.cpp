class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1);

        t[1]=1;
        int i2;
        int i3;
        int i5;

        i2=i3=i5=1;

        for(int i=2;i<=n;i++){
            int i2_uglyNo=t[i2]*2;
            int i3_uglyNo=t[i3]*3;
            int i5_uglyNo=t[i5]*5;

            t[i]=min({i2_uglyNo,i3_uglyNo,i5_uglyNo});

            if(t[i]==i2_uglyNo) i2++;
            if(t[i]==i3_uglyNo) i3++;
            if(t[i]==i5_uglyNo) i5++;
        }

        return t[n];

    }
};