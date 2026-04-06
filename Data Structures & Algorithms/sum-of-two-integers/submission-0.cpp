class Solution {
public:
    int getSum(int a, int b) {
        /*
        a+b ==> 0 in both ==> 0                                 [carry? ==> 1, caqrry=0]
            ==> 0 in one and 1 in one ==> 1                     [carry? ==> 0]
            ==> 1 in both ==> 0 +(1 carry to next bit)          [carry? ==> 1]
        */
        // int sum=0;
        // int carry=0;
        // for(int i=0;i<31;i++){
        //     cout<<"i: "<<i<<endl;
        //     // cout<<"s: "<<sum<<" c: "<<carry<<endl;
        //     int bit_a=(a>>i)&1;
        //     int bit_b=(b>>i)&1;
        //     cout<<"a: "<<bit_a<<" b: "<<bit_b<<endl;
        //     if(bit_a==0 && bit_b==0){
        //         sum|=0;
        //         if(carry){
        //             sum|=(1<<i);
        //             carry=0;
        //         }
        //     }
        //     else if((bit_a==0 && bit_b==1)||(bit_a==1 && bit_b==0)){
        //         if(carry==0){
        //             sum|=(1<<i);
        //         }
        //     }
        //     else{
        //         sum|=0;
        //         if(carry){
        //             sum|=(1<<i);
        //         }
        //         carry=1;
        //     }
        //     cout<<"sum: "<<sum<<endl;
        //     cout<<"carry: "<<carry<<endl;
        // }
        // return sum;
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a==b){
            return a<<1;
        }
        return getSum(a^b,(a&b)<<1);
    }
};