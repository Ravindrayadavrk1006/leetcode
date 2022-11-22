class Solution {
public:
    void help(int i, int n , int rem , vector<int>& current_set, vector<vector<int>>& ans )
    {
        //base case
        if(rem==0){
            ans.push_back(current_set);
            return;
        }
        if(rem<0 || i>n) return;

        //pick
        current_set.push_back(i);
        help(i+1, n, rem-1, current_set, ans);
        
        //don't pick
        //back_track the disturbance done
        current_set.pop_back();
        help(i+1, n, rem, current_set, ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current_set;
        help(1, n, k, current_set, ans);
        return ans;
    }
};
