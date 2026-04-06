class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=0;
        int j=31;
        while(i<j){
            int ith_bit=(((((long long)1)<<i)&n)>0);
            int jth_bit=(((((long long)1)<<j)&n)>0);
            swap(ith_bit,jth_bit);
            n|=(((long long)1)<<i);
            n^=(((long long)1)<<i);
            n|=(ith_bit)*(((long long)1)<<i);

            n|=(((long long)1)<<j);
            n^=(((long long)1)<<j);
            n|=(jth_bit)*(((long long)1)<<j);
            i++;
            j--;
        }
        return n;
    }
};
