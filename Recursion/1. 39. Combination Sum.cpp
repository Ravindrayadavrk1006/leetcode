class Solution {
public:
    void help(int i, int sum, int target, int n, vector<int>& candidates, vector<int>& current_vec, vector<vector<int>>& ans)
    {
        if(i == n){
            if(sum == target){
                 ans.push_back(current_vec);
            }
            return;
        }
        if(sum > target)return;
        
        //pick
        current_vec.push_back(candidates[i]);
        sum = sum + candidates[i];
        /*
        since after picking a element there is a chance that it can be picked again hence we won't increase i 
        */
        help(i,sum,target,n,candidates,current_vec,ans);

        //don't pick 
        //remove the above disturbance undoing what we have done earlier to move one side of recursion tree
        current_vec.pop_back();
        sum = sum - candidates[i];
        help(i+1,sum,target,n,candidates,current_vec,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current_vec;
        //sort(candidates.begin(),candidates.end());
        help(0,0,target,candidates.size(),candidates,current_vec,ans);
        return ans;
        
    }
};
