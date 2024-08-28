
/*
using the concept of 11 question in the DP playlist

Intuition

***BETTER AND SIMPLE EXPLANATION:
        HERE constraint is that we don't have to take the adjacent values,
    approach:
        we know how to form all possible combinations, by using the approach of pick and non-pick so if we we use that concept,
        pick = arr[i] + f(i+1)
        non_pick = f(i+1)
        return max(pick,non_pick)

    but here one more condition is there:
        that we don't have to take adjancent element when we have picked current element it means in pick case in above code we have to move to f(i+2) once we have picked the current element
        and hence it would look like pick = arr[i] + f(i+2) 
        non_pick = f(i+1)
        retur max(pick,non_pick)


********normal explanation use the above approach explanation
    
Approach
calculating the sum of same elements of nums and storing in a vector sums since if we take a element we have to take all it's occurances and we reject a element all it's element occurances must be rejected.

after it used the technique of house robber of taking the max value
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
similary in our problem we will use a variation of it. where we store the sum of all occruances of a element at it's(element equal) index
and and non present element of nums as 0 so that we can use the concept of rejecting nums[element]-1 and nums[element]+1

used memoization to save the time

Complexity
Time complexity:
O(max_element of nums)

Space complexity:
O(max_element of nums)

Code
*/
class Solution {
public:
    /*
        REFER TO HOUSE ROBER PROBLEM FOR HALF PART OF FINDING MAX LEAVING ADJACENT VALUES
    */
    int help(int pos, vector<int>& sums, vector<int>& dp)
    {
        if(pos < 0)return 0;
        //other cases
        if(dp[pos] != -1)return dp[pos];
        // calculating value of current_elment + element at pos-2
        int first = sums[pos] + help(pos-2, sums, dp);
        //taking value of pos-1
        int second = help(pos-1, sums, dp);
        //finding max of above two values
        return dp[pos] = max(first,second);

    }
    int deleteAndEarn(vector<int>& nums) {
        //finding max value of nums
        int max_el = *max_element(nums.begin(),nums.end());
        vector<int> dp(max_el+1,-1);
        vector<int> sums(max_el+1);
        
        /*
        At index i taking sum of all i elements in the sum
        eg. 2,2,1,5,5,5
        then at 
        index -> 0 1 2 3 4 5 
        value -> 0 1 4 0 0 15
        */
        for(int i: nums)
        {
            sums[i]+=i;
        }
        return help(max_el, sums, dp);

    }
};
