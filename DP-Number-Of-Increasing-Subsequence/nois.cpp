class Solution {
public:
     int most_optimized(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> counts(n,1);
        int max_final_val = 1;
        for(int i = 1 ; i<n; i++)
        {
            //asking all the previous elemnts to it 
            for(int j= 0; j<i; j++)
            {
                 if(nums[j]<nums[i] && lis[j]+1>lis[i])
                {
                    lis[i] = lis[j]+1;
                    //if increasing this means the count to reach i will be same as the counts to reach j since we have reached to 
                      //j and since nums[i]>nums[j] hence we can reach here too
                    counts[i] = counts[j];
                    max_final_val= max(max_final_val,lis[i]);
                }

                //if the value lis[j]+1==lis[i]  is same this says we can have found a new way to reach current i and hence 
                 //this new way no of ways to reach this j , will be added to the earlier no of ways we can reach here 
                else if(nums[j]<nums[i] && lis[j]+1==lis[i])
                {
                    counts[i]+=counts[j];
                }
            }
        } 
        int total_count = 0;
        for(int i =0; i<n ; i++)
        {
            if(lis[i] == max_final_val)total_count+=counts[i];
        }
        return total_count;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return most_optimized(nums);
    }
};
