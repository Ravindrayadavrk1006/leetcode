/*


IMPORTANT ---> FOR SKIPPING THE SAME SETS AND ONLY FORMING UNIQUE SETS , IF A ELEMENT ONCE SKIPPED THEN WE HAVE TO SKIP ALL IT'S OCCURANCES TO FORM ONLY UNIQUE PAIRS 
Approach
simple approach of forming combination till sum required and for handling the condition of unique combination if the element is skippped once skip it again till new element found

Complexity
Time complexity:
O(2^n)

Space complexity:
O(N)

Code


*/


class Solution {
public:
    void help(int i, int sum, int n, int target, vector<int>& candidates, vector<int>& current_vec, vector<vector<int>>& ans)
    {
        //base condition
        if(sum == target)
        {
            ans.push_back(current_vec);
            return;
        }
        if(sum > target)return;
        if(i == n)return;

        //pick
        current_vec.push_back(candidates[i]);
        sum+=candidates[i];
        help(i+1, sum, n, target, candidates, current_vec, ans);

        //don't pick leave all occurance of the current element
        current_vec.pop_back();
        sum-=candidates[i];
        while(i+1 < n  && candidates[i] == candidates[i+1])i++;
        help(i+1, sum, n, target, candidates, current_vec, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current_vec;
        int sum= 0;
        sort(candidates.begin(),candidates.end());
        help(0, sum, candidates.size(), target, candidates, current_vec, ans);
        return ans;
    }
};
