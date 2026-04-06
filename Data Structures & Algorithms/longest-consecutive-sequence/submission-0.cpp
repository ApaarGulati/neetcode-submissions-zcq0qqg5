class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto&x:nums){
            f[x]++;
        }
        int ma=0;
        for(auto&x:nums){
            if(f[x]){
                int cnt=1;
                int i=1;
                while(f[x-i]){
                    f[x-i]=0;
                    i++;
                    cnt++;
                }
                i=1;
                while(f[x+i]){
                    f[x+i]=0;
                    i++;
                    cnt++;
                }
                ma=max(ma,cnt);
            }
        }
        return ma;
    }
};