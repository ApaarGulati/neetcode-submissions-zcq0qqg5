class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> f;
        bool duplicate=0;
        for(auto&x:nums){
            f[x]++;
            if(f[x]>1){
                duplicate=1;
            }
        }
        return duplicate;
    }
};