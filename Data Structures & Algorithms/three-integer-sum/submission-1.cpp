class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tgt=-nums[i];
            int l=0,r=n-1;
            while(l<r){
                if(nums[l]+nums[r]<tgt){
                    l++;
                }
                else if(nums[l]+nums[r]>tgt){
                    r--;
                }
                else{
                    if(l==i){
                        l++;
                    }
                    else if(r==i){
                        r--;
                    }
                    else{
                        vector<int> v={nums[l],nums[r],nums[i]};
                        sort(v.begin(),v.end());
                        ans.insert(v);
                        l++;
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> finans;
        for(auto&v:ans){
            finans.push_back(v);
        }
        return finans;
    }
};