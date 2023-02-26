class Solution {
    /*
    approaches-->
    1. sort the array and find where nums[i]!= nums[i-1]+1
    return nums[i]-1
    t.c nlogn 
    2.using concept of hashing we create a hash array which count the number of elements in O(n)
    traverse the hash array and the element which has 0 as frequency print it
    3. the num of n natural number n(n+1)/2 and then sum the array the output will be n(n+1)/2 - sum of array
    */
    //solution 3
    int sol(vector<int>& nums)
    {
        int n = nums.size();
        int sum_natural = n*(n+1)/2;
        int sum_arr = 0;
        for(int i = 0 ; i<n; i++)sum_arr+=nums[i];
        return sum_natural-sum_arr;
    }
public:
    int missingNumber(vector<int>& nums) {
        return sol(nums);
    }
};
