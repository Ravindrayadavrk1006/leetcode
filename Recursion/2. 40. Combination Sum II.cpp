class Solution {
private:

    //THIS IS PREFFERED APPROACH SINCE EXPLAINED BY STRIVER AND ALSO IN CP NOTES
    /*
      pattern of recursion -> generating all unique subsequences or subsets
      explained in the notes
    */
    void solCombinationSum(int i, int curr_sum, vector<int>& curr_vec, vector<int>& candidates, vector<vector<int>>& ans, int n  ){
        if(curr_sum == 0 ){
            ans.push_back(curr_vec);
            return ;
        }
        //this line should be here not at the top because the condition of curr_sum becomes 0 or not need to checked at i == n also 
      //this condition is also not required since it is handled by the for loop, it is running till the required position of i and also in betwee we are checking if any point the current element is greater than the required sum we don't add that element
        if(i == n || curr_sum < 0 )return;
        //starting from not the same elemnet
        for(int j =i; j<n; j++){
            //if the present element is not the first element and it is equal to previous element then check for next element
            if(j>i && candidates[j] == candidates[j-1])continue;
            //this is done since the candidates arr is already sorted and if the current element is greater then current_required curr_sum then there is no need for checking for further element since they will also be greater than curr_sum
            if(candidates[j] > curr_sum)break;
            //insert the current element in the current vec and call recursive
            curr_vec.push_back(candidates[j]);
            solCombinationSum(j+1, curr_sum - candidates[j], curr_vec, candidates, ans, n );
            //since pushing inside the for loop always remove the disturbance even if there is just one recursive call, since next iteration the call will come here
            curr_vec.pop_back();
        }
    }

    //other approach 
    //
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
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr_vec;
        sort(candidates.begin(), candidates.end());
        solCombinationSum(0, target, curr_vec, candidates, ans, candidates.size() );
        return ans;



      //other approach

       vector<vector<int>> ans;
        vector<int> current_vec;
        int sum= 0;
        sort(candidates.begin(),candidates.end());
        help(0, sum, candidates.size(), target, candidates, current_vec, ans);
        return ans;
    }
};
