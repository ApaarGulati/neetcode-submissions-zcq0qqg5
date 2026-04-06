class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums);
        int suf=1;
        for(int i=1;i<nums.size();i++){
            pref[i]*=pref[i-1];
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            pref[i]=(i-1>=0 ? pref[i-1]:1)*suf;
            suf*=nums[i];
        }

        return pref;
    }
};
