class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i]==nums[i-1]){
                continue;
            }
            int tgt=-nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[l]+nums[r]<tgt){
                    l++;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                }
                else if(nums[l]+nums[r]>tgt){
                    r--;
                    while(r>l && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else{
                    vector<int> v={nums[i],nums[l],nums[r]};
                    ans.push_back(v);
                    l++;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    r--;
                    while(r>l && nums[r]==nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};