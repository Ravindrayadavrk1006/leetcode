Approach
approach is simple from current position going in all possible ways by taking 1 to position value and further recrusively going like that. If possible to reach the end goal then we return true else false
for optimization DP is used since simple recursion was giving TLE

in function canJump() ==>
checking if there are any zero in the array if zero then only there is a possibility can get stuck 
at the position and won't be able to move ahead since saying standing at a position we can move max of the position(index)
value time which means if non zero we can move atleast one step which means even we take one one step from every step in a non zero
array we can reach to the last

Complexity
Time complexity:
O(n+n)

Space complexity:
O(N)

Code
class Solution {
public:
    bool help(int pos, vector<int>& nums, vector<int>& dp)
    {
        if(pos == nums.size()-1)return true;
        if(pos > nums.size()-1)return false;
        //for other 
        if(dp[pos] != -1)return dp[pos];
        for(int i=1; i<=nums[pos]; i++)
        {
            if(help(pos+i, nums, dp))return dp[pos] = 1;
        }
        return dp[pos] = 0;
    }
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1)return true;
        int i=0;
        for(;i< nums.size(); i++)
        {
            if (nums[i] == 0)break;
        }
        if(i == nums.size())return true;
        else{
            vector<int> dp(nums.size()+1,-1);
            return help(0, nums, dp); 
        }
    }
};
