class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char,int>> maps;
        vector<vector<string>> answer;
        for(auto&s:strs){
            unordered_map<char,int> cur_freq;
            for(auto&c:s){
                cur_freq[c]++;
            }
            bool found=0;
            for(int i=0;i<maps.size();i++){
                if(cur_freq==maps[i]){
                    answer[i].push_back(s);
                    found=1;
                    break;
                }
            }
            if(!found){
                maps.push_back(cur_freq);
                answer.push_back({s});
            }
        }
        return answer;
    }
};
