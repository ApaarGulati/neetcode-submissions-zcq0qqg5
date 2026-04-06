class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto&x:nums){
            freq[x]++;
        }
        vector<pair<int,int>> v;
        for(auto&p:freq){
            v.push_back({p.second,p.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int> answer;
        for(int i=0;i<k;i++){
            answer.push_back(v[i].second);
        }
        return answer;
    }
};
