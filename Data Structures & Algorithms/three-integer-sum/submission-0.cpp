class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        unordered_map<int,int> freq;
        unordered_map<int,int> inds;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0){
                inds[nums[i]]=i;
            }
            freq[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(freq[-(nums[i]+nums[j])] && inds[-(nums[i]+nums[j])]<j){
                    vector<int> v={nums[i],nums[j],-(nums[i]+nums[j])};
                    sort(v.begin(),v.end());
                    // for(auto&x:v){
                    //     cout<<x<<" ";
                    // }
                    cout<<endl;
                    ans.insert(v);
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