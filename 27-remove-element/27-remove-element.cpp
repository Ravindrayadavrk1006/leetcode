class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lengthOfArray= nums.size();
        //handling base case of length of array 1 or 0
        if(lengthOfArray==0)return 0;
        else if(lengthOfArray==1 && nums[0]==val)return 0;
        else if(lengthOfArray==1 && nums[0]!=val)return 1;
        else
        {
            //for holding the position of val
            int p_1=0;
            for(int p_2=0;p_2<lengthOfArray;p_2++)
            {
                if(nums[p_1]!=val)p_1++;
                else if(nums[p_1]==val && nums[p_2]!=val)
                {
                    nums[p_1]=nums[p_2];
                    nums[p_2]=val;
                    p_1++;
                }
                
            }
            return p_1;
        }
        
    }
};