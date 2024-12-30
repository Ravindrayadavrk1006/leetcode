/*
    using recursion to prepare the size of string of each size between low and high

    if you visualize this is very simple , the dp creation is outside the caller for loop because if created by already recursive function then will use for solution

*/
class Solution {
private:
    long dp_func(int end, int zero, int one, vector<int>& dp){
        //take one or take zero
        //take 0
        if(dp[end] != -1 )return dp[end];
        long count = 0;
        //taking zero and going
        if(end>= zero){
            count+=dp_func(end-zero,zero, one, dp);
        }
        if(end >= one){
            count+=dp_func(end-one, zero, one, dp);
        }
        return dp[end] = count%1000000007;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long ans = 0;
        vector<int> dp(high+1, -1);
        dp[0] = 1;
        for(int i=low; i <= high; i++){
            ans+=dp_func(i, zero, one, dp);
            ans%=1000000007;
        }
        return ans;
    }
};
