class Solution {
public:
    int sum(int n){
        return n*(n+1)/2;
    }
    int sum_of_array(vector<int>& v){
        int sum=0;
        for(auto&x:v){
            sum+=x;
        }
        return sum;
    }
    int missingNumber(vector<int>& nums) {
        return sum(nums.size())-sum_of_array(nums);
    }
};
