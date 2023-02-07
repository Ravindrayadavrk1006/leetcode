


/*
   ----------------------concept of  longest_bitonic_sequence  --------------------------------------------------------

the question is Longest Bitonic Subsequence -- A concept using LIS(longest increasing subsequence) 
eg [2,1,1,5,6,2,3,1]
bitonic subsequence are of form of mountains .ie increasing then decreasing, only increasing or only decreasing
we have already learned to find lis increasing 
for decreasing if we find lis from end then it will look like decreasing from start of array

//DECREASING
 for decreasing we will do lis from end i.e for eg 3 from last has just 1 lesser than it after itself hence 2 
    similary for array[5] i.e 2  lis from end will be 2 since 2 and 1 at last similarly 

till a point we join increasing and decreasing then we get increasing then decreasing i.e mountain structure
eg.
    in the above array            [2,1,1,5,6,2,3,1]
    //increasing --> dp_inc        1 1 1 2 3 2 3 1 
    //decreasing    dp_dec         2 1 1 3 3 2 2 1        <--start filling from here

    //mounttain at a point is eg let's look at array[4] i.e 6  
    dp_inc  3 the elements are 1,5,6 contributing in it's length and dp_dec= 3 elements contributing are 6 2 1 since 6 is included two times
    hence we have to decrease one time hence total element in bitonic will be  dp_inc[4]+dep_dec[4]-1 i.e 3+3 -1  = 5   i.e 5 elements are forming a mountain

    only increasing and only decreasing will be covered in this bitonic since 
    eg at element array[0]  dp_inc =1 dp_dec 2 i.e not increasing only decreasing since itself will be not of much use since once will be
    subtracted hence only increasing and only decreasing are also covered


    V.V IMPORTANT ->
    here in the question explicitly explanined that it must be increasing and then decreasing ==>
    that we cannot include the ones where dp_inc or dp_dec is 1 since 1 means it has not increased or decreased 
    and also we have to keep the minimum mountain size 0 since if the array is only increasing or only decreasing then no mountain formed
    hence in the below code explicitly done this condition check and also max_mountain_size initialized to 0 
    if(dp_inc[i]>1 && dp_dec[i]>1)max_mountain_size = max(max_mountain_size,dp_bitonic[i]);   
*/
    int most_optimized(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp_inc(n,1);
        for(int i = 1 ; i<n; i++)
        {
            for(int j= 0; j<i; j++)
            {
                if(nums[j]<nums[i] && dp_inc[j]+1>dp_inc[i])
                {
                    dp_inc[i] = dp_inc[j]+1;
                }
            }
        }
        vector<int> dp_dec(n,1);
        for(int i = n-2 ; i>=0; i--)
        {
            for(int j= n-1; j>i; j--)
            {
                if(nums[j]<nums[i] && dp_dec[j]+1>dp_dec[i])
                {
                    dp_dec[i] = dp_dec[j]+1;
                }
            }
        }
        vector<int> dp_bitonic(n,1);
        int max_mountain_size = 0;
        //creating bitonic array and then returning max value; 
        for(int i= 0; i<n; i++)
        {
            dp_bitonic[i] = dp_inc[i]+dp_dec[i]-1;
            if(dp_inc[i]>1 && dp_dec[i]>1)max_mountain_size = max(max_mountain_size,dp_bitonic[i]); 
        }
        return n-max_mountain_size;
    }

class Solution {
public:

    int minimumMountainRemovals(vector<int>& nums) {
        return most_optimized(nums);
    }
};
