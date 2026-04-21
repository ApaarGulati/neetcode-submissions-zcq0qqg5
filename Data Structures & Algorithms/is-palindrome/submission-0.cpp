class Solution {
public:
    char lower(char s){
        if(isupper(s)){
            return s^' ';
        }
        return s;
    }

    bool isnum(char s){
        int d=s-'0';
        return 0<=d && d<=9;
    }

    bool isPalindrome(string s) {
        string ns="";
        for(int i=0;i<s.size();i++){
            if(islower(s[i]) || isupper(s[i])){
                ns.push_back(lower(s[i]));
            }
            else if(isnum(s[i])){
                ns.push_back(s[i]);
            }
        }
        cout<<ns<<endl;
        int i=0,j=ns.size()-1;
        while(i<j){
            if(ns[i]!=ns[j]){
                return 0;
            }
            i++;j--;
        }
        return 1;
    }
};