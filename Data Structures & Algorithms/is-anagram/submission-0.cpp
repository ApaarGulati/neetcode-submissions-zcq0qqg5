class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_freq,t_freq;
        for(auto&c:s){
            s_freq[c]++;
        }
        for(auto&c:t){
            t_freq[c]++;
        }
        for(int i=0;i<26;i++){
            if(s_freq[(char)(i+'a')]!=t_freq[(char)(i+'a')]){
                return false;
            }
        }
        return true;
    }
};
