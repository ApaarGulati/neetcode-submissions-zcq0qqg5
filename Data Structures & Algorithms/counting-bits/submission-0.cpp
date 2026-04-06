class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1,0);
        int pow2=1;
        while(pow2<=n){
            v[pow2]=1;
            pow2<<=1;
        }
        for(int i=1;i<=n;i++){
            v[i]=v[i/2]+(i%2);
        }
        return v;
    }
};