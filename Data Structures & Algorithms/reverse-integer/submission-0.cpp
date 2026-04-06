class Solution {
public:
    int reverse(int x) {
        /*
        given the current int, i want to get the reverse int
        initially ans=0;
        in base 10, take remainder of division of x by 10 and ans*=10, ans+=remainder, x/=10
        */

        int ans=0;
        while(x){
            cout<<x<<endl;
            cout<<ans<<endl;
            cout<<endl;
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            ans*=10;
            ans+=(x%10);
            x/=10;
        }
        return ans;
    }
};