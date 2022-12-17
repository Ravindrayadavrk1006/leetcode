// FOR SOLUTION 1
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

class Solution {
public:
    // -------------------- SOLUTION 1-------------------
    /*     
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
    */
    //USING TOP DOWN APPROACH
    EXPLANATION EASY SOLUTION SINCE DON'T HAVE TO TAKE ADJACENT THIS MEANS IF WE ARE STANDING AT N POSITION THEN WE HAVE TO LEAVE N-1 AND TAKE N-2 AND OTHER POSSIBILITY
    IS THAT WE DON'T TAKE THE CURRENT NUMBER THEN WE CAN TAKE N-1 NUMBER USING THE SAME STRATEGY
    //------------------------ SOLUTION 2-------------------
    //using top down approach
    int help(int pos, vector<int>& nums, vector<int>& dp)
    {
        //base cases
        if(pos == 0)return nums[pos];
        if(pos < 0)return 0;
        //all cases
        if(dp[pos] != -1)return dp[pos];
        int take = nums[pos]+help(pos - 2, nums, dp);
        int not_take = 0 + help(pos -1, nums, dp);
        return dp[pos] = max(take, not_take);

    }
    //using tabulation method FOR CONVERTING THE ABOVE DP SOLUTION IN TABULATION SOLUTION , STRIVER TECHNIQUE OF CONVERTING A DP SOLUTION TO NON RECURSIVE SOLUTION
    int tabulation(vector<int>& nums)
    {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
        int n = nums.size();
        vector<int> table(n);
        table[0] = nums[0];
        table[1] = max(nums[0],nums[1]);
        int less_than_zero = 0;
        for(int i=2; i< n;i++)
        {
            int take = nums[i] + table[i-2];
            int not_take = 0 + table[i-1];
            table[i] = max(take, not_take);
        }
        return table[n-1];
    }
    int rob(vector<int>& nums) {
        /*
        //--------- calling method 2nd
        // 1.
        vector<int> dp(nums.size(),-1);
        return help(nums.size()-1, nums, dp);
        */

        //2.
        //calling tabulation 
        //return tabulation(nums);

        //3.
        /// SINCE ONLY THREE ELEMENTS ARE REQUIRED 
        //space optimization
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
        int n = nums.size();
        int prev = max(nums[0],nums[1]);
        int prev_2 = nums[0];
        for(int i =2 ; i< n ; i++)
        {
            int take = nums[i] + prev_2;
            int not_take = prev;
            int curr = max(take, not_take);
            prev_2 = prev;
            prev = curr;
        }
        return prev;
    }
};
