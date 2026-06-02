class Solution {
public:
    
    /* 1. important point to note=> in binary search the last index should be length-1 
       2. till i<=j
    */
    int binarySearch(vector<int>&nums,int i,int j,int target)
    {
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)return binarySearch(nums,mid+1,j,target);
            else return binarySearch(nums,i,mid-1,target);
        }
        return max(i,j); 
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};