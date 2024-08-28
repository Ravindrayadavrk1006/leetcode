Approach
eg if just one element max is the same elment
if two element max(first,second element)
if three elements eg. 2,7,4
can without taking the adjacent element max can be(2+4,7) i.e current_element(2)and current_position -2 position element or the current_position-1 element
for extending this for more than three elements same trick recursively
eg 2,7,4,3,1,5
then 7,(2+4),3,1,5
in next step-> 6 (ie 2+4),7+3,1,5
next step -> 10,6+1,5
next step -> 7,15
return max of 7,15

Complexity
Time complexity:
O(n)

Space complexity:
O(n)

Code
class Solution {
public:
    int help(int pos, vector<int>& nums, vector<int>& dp)
    {
        if (pos < 0) return 0;
        if (dp[pos] != -1 )return dp[pos];
        int first = nums[pos] + help(pos-2, nums, dp);
        int second = help(pos-1 , nums, dp);
        return dp[pos] = max(first,second);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return help(nums.size()-1, nums, dp);
    }
};
