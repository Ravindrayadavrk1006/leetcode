# Intuition
since have to find all the permutation which give the required values
we start initially our sum is target and try to reach sum 0 using the target -> 0 approach

eg [1,2,3] and target = 4

                               []
                        /       \     \
                       1        2      3
                     / | \     / | \   / | \
                    1  2  3   1  2  3  1  2 3
we try to find when the sum becomes equal to required (note in the question opposite of this approach of used that is assumed we have given sum and we try to reach to 0 ) 
this fulfill our idea of getting all the permutations too


# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n+n)

# Code
```
class Solution {
public:
    int help(int target, vector<int>& nums, vector<int>& dp)
    {

        #taget can become equal to zero at any point in the traversal and hence we have to return at that point
        if(target<0)return 0;
        if(target ==0)return 1;
        if(dp[target] != -1)return dp[target];
        int total_com = 0;
        for(int i = 0 ; i<nums.size(); i++)
        {
            total_com+=help(target-nums[i],nums, dp);
        }
        return dp[target] = total_com;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return help(target,nums, dp);

    }
};
```
