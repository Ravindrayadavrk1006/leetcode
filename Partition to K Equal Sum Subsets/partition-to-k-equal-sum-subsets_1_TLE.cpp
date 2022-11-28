/*

SOLUTION 1 ---> ACCORDING TO FARAZ GIVING TLE 
SIMPLE SOLUTION


*/


class Solution {
    bool help(int i, int sum, int req_sum,int bucket_num, int req_buckets_num, vector<int>& nums, vector<int>& taken)
    {
        if(bucket_num > req_buckets_num) return true;
        if(sum == req_sum)
        {
            return help(0, 0, req_sum, bucket_num+1, req_buckets_num, nums, taken);
        }
        if(sum > req_sum)return false;
        if(i >= nums.size()) return false;
        //if the element aready taken expore the other element
        if(taken[i]==1)return help(i+1,sum,req_sum, bucket_num, req_buckets_num, nums, taken);

        //pick
        sum += nums[i];
        taken[i] = 1;
        bool b1 = help(i+1, sum, req_sum, bucket_num, req_buckets_num, nums, taken);
        // if (b1) return b1;
        // else
        // {
        //not pick 
        sum-=nums[i];
        taken[i]=0;
        bool b2 = help(i+1, sum, req_sum, bucket_num,req_buckets_num, nums, taken);

        return b1 || b2 ;
        // }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = 0;
        for(int i : nums)total_sum+=i;
        if(total_sum % k != 0)return false;
        if(k==1)return true;
        if(k>nums.size())return false;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> taken(nums.size(), 0);
        return help(0, 0, total_sum/k, 1, k, nums, taken);
    }
};
