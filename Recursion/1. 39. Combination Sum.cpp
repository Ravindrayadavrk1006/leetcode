class Solution {
public:
    //top down approach
    void help(int i, int sum, int target, int n, vector<int>& candidates, vector<int>& current_vec, vector<vector<int>>& ans)
    {
        if(i == n){
            if(sum == target){
                 ans.push_back(current_vec);
                return;
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

    //bottom up approach
    void solBottomUp(int i, int req_sum, vector<int>& candidates, vector<int>& current_vec, vector<vector<int>>& ans)
    {

        //we could say when i == -1 ,
        //we are checking at i == -1 since we can take 0th position unlimited number of times, therefore it's best to check at -1 also we can go with top down approach, jst some more
        //parameters need to be passed
        if(i < 0){
            if(req_sum == 0 ){
                ans.push_back(current_vec);
                return;
            }
            return;
        }
        if(req_sum < 0 )return;
        
        //pick
        current_vec.push_back(candidates[i]);
        /*
        since after picking a element there is a chance that it can be picked again hence we won't increase i 
        */
        solBottomUp(i, req_sum - candidates[i], candidates, current_vec,ans);

        //don't pick 
        //remove the above disturbance undoing what we have done earlier to move one side of recursion tree
        current_vec.pop_back();
        solBottomUp(i-1, req_sum, candidates,current_vec,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current_vec;
        //sort(candidates.begin(),candidates.end());
        //using top down approach
        // help(0,0,target,candidates.size(),candidates,current_vec,ans);


        //using bottom up approach
        
        solBottomUp(candidates.size()-1 , target, candidates, current_vec, ans );
        return ans;
        
    }
};
