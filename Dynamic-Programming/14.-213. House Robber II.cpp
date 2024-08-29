c++ || dp tabulation || space optimized
Approach
see explanation inside the code

Complexity
Time complexity:
O(n)

Space complexity:
O(1)

Code
class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        int n = nums.size();
        //calculating first case from index 0 to n-2 
        //calculating first case from index 1 to n-1 
        //reason for doing so is since the array is circular if we consider the first element then we don't want to consider the last element and hence for last till n-2 index only
        //in second case the first is exempted and hence starting from 1 and hence goes till the end
        /*
        [****important] thing the above two cases are consider because we don't have to include adjacent elemnts and since it is circle then 1st and last element are adjacent,
          which means if we want to take into consideration first and last element then we can't take into consideration both at the same time, because if we take 1st element then we can't take last element
      if we take last element then we can't take first element, and hence we are taking two cases when we are taking first eleemnt and excluding last element and once we are excluding first element and including the last element
      and we are returning the max of two.
      */



          
        //FIRST CASE
        int prev_2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for(int i = 2 ; i <  n-1; i++)
        {
            int take = nums[i] + prev_2;
            int not_take = 0 + prev;
            int curr = max(take, not_take);
            prev_2 = prev;
            prev = curr;
        }
        int result_1 = prev;
        //SECOND CASE
        prev_2 = nums[1];
        prev = max(nums[1], nums[2]);
        for(int i = 3 ; i< n; i++)
        {
            int take = nums[i] + prev_2;
            int not_take = 0 + prev;
            int curr = max(take, not_take);
            prev_2 = prev;
            prev = curr;
        }
        int result_2 = prev;
        return max(result_1, result_2);

    }
};
