class Solution {
public:
    /*
    idea-> we will be swaping the current element with all other element and recursively call the function 
    to do the remaining task
    for ex. in 1,2,3  we will swap 1,2 and ask the function to do the remainging task 
    the last swap to undo the changes made by the first one 
    
    
    T.C -> 0(n*n!)
    S.C -> O(N)
    */
    vector<vector<int>> final_ans;
    int nums_size=0;
    void helper(int pos , vector<int> &one_perm)
    {
        if(pos>=nums_size)
        {
            final_ans.push_back(one_perm);
        }
        for(int i=pos;i<nums_size;i++)
        {
            swap(one_perm[pos],one_perm[i]);
            helper(pos+1,one_perm);
            swap(one_perm[pos],one_perm[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        nums_size=nums.size();
        helper(0,nums);
        return final_ans;
        
    }
};
