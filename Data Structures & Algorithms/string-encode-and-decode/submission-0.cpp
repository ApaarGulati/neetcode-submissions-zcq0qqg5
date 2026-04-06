class Solution {
public:

    string encode(vector<string>& strs) {
        string ret="";
        for(auto&s:strs){
            ret+=s;
            ret.push_back('.');
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> v;
        string cur="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                cur.push_back(s[i]);
            }
            else{
                v.push_back(cur);
                cur="";
            }
        }
        return v;

    }
};
