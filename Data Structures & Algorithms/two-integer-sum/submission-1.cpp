class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        unordered_map<int,int> inds;
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(freq[req]>0){
                return {inds[req],i};
            }
            freq[nums[i]]++;
            inds[nums[i]]=i;
        }
        return {-1,-1};
    }
};
