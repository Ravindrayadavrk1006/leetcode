Intuition
simple knapsack problem of finding the maximum value by checking all the possibilities
we check after taking a strs array element if the count of zeros and ones haven't execeded the maximum

Approach
for forming all the subsets we try the concept of take and not_take since not take doesn't affect the value of m and n hence taking directly with 0 + since we haven't taken the current string . In take we are checking before taking if by taking the current string if values of m and n doesn't exceed the maximum value we can .
and accordingly proceeding since we know in maximum of all we have to take a default value -1e9 for safety since going till pos 0 in all the subsets so won't affect if anything gets left out

Complexity
Time complexity:
O(mnsize of array)

Space complexity:
O(mnsize of array)

Code
class Solution {
public:
    int help(int pos, int m , int n,vector<string>& strs,vector<vector<vector<int>>>& dp)
    {
        if(pos == 0){
            int str_len = strs[0].size();
            int zeros= count(strs[0].begin(),strs[0].end(),'0');
            int ones = str_len-zeros;
            if(zeros<=m && ones<=n)return 1;
            return 0;
        }
        if(dp[pos][m][n] != -1)return dp[pos][m][n];
        //not take
        int not_take = 0 + help(pos-1,m,n,strs,dp );
        //int take
        int take = -1e9;
        int str_len = strs[pos].size();
        int zeros= count(strs[pos].begin(),strs[pos].end(),'0');
        int ones = str_len-zeros;
        if(zeros<=m && ones<=n)take= 1 + help(pos-1,m-zeros,n-ones,strs, dp);
        return dp[pos][m][n] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return help(strs.size()-1,m,n,strs, dp);
    }
};
