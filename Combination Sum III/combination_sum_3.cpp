/*
------------------------------------------------------------------QUESTION ----------------------------------------------------
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.


*/


// -------------------------------------------------------------- ANSWER --------------------------------------------------------------


Approach
recursive approach of selecting COMBINATION OF SIZE K and keeping condition of their sum == n

Complexity
Time complexity:
O(2^k)

Space complexity:
O(k) and the ans vector take addditional space of O(k*(2^k))

Code
class Solution {
public:
void help(int i, int sum, int count_rem, int required_sum, vector<int>& current_vec, vector<vector<int>>& ans)
    {
        //base cond.
        if(sum == required_sum && count_rem == 0 ){
            ans.push_back(current_vec);
            return;
        }
        if(sum > required_sum)return;
        if(count_rem < 0 ) return;
        if(i > 9) return ;

        //pick
        current_vec.push_back(i);
        sum +=i;
        help(i+1, sum, count_rem-1, required_sum, current_vec,ans);

        //don't pick 
        //remove the above disturbance
        current_vec.pop_back();
        sum -=i;
        help(i+1, sum, count_rem, required_sum, current_vec, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current_vec;
        help(1,0,k,n,current_vec,ans);
        return ans;     
    }
};
