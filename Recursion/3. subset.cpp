// problem -statement : print all the subsequences of a given set

class Solution {
public:
    vector<vector<int>> final_ans;
    //SOLUTION TWO->>>> this is the only approach to learn from here
    /*
    IDEA-> the concept is to start from beginning and taking in account once including the element and once not including the element 
    T.C -> O(2^n)
    S.C -> O(n) since s.c is the no of level in the recursion tree
    
    */
    void sol2(vector<int> &s,int i ,vector<int> &subset)
    {
        if(i==s.size())
        {
            final_ans.push_back(subset);
            return;
        }


        //TAKE 
        subset.push_back(s[i]);
        sol2(s,i+1,subset);
        //remove the disturbance
        subset.pop_back();

        //NOT-TAKE
        //excluding the ith element
        sol2(s,i+1,subset);
            
    }

//DO NOT PREFER THIS SOLUTION
    //SOLUTION 1
    
    /*
        IDEA -> concept is 
        {2,3} -> it's subset will be {2,3},{2},{3},{}
        now let's add 1 and try forming in the above subset add 1 to all the subsets {1,2,3},{1,2},{1,3},{1}
        using the above concept to solve 
        first we go the finish of array we get {{}} suppose the given array is {1,2,3}  then while coming back we will get 3 => from the above idea we will get {{3},{}} 
        and similarly when coming more back we will get {{2,3},{2},{3},{}} and so on 
        T.C -> O(2^n) i.e no of nodes in the recursive tree
        S.C -> O(N) since s.c is no of levels in the recursive tree 
    */
    vector<vector<int>> mainF(vector<int> & nums,int i)
    {
        if(i>=nums.size())return {{}};
        else
        {
            vector<vector<int>> partial_ans=mainF(nums,i+1);
            vector<vector<int>> f_ans;
            for(auto x:partial_ans)
            {
                f_ans.push_back(x);
            }
            for(auto x:partial_ans)
            {
                x.push_back(nums[i]);
                f_ans.push_back(x);
            }
        return f_ans;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //solution 1  fn call
        //return mainF(nums,0);
        
        
        //solution 2 fn call
        vector<int> subset={};
        sol2(nums,0,subset);
        return final_ans;
    }
};
