class Solution {
private:
/*
    concept used since the array is not linearly sorted but sorted in part
    we have to find a way to oscillate between the parts
    so idea used 
    we find the mid element and check if it is equal to the target
    if yes we return it
    otherwise 
    we check if left part is sorted ---> if yes we try to check if our element target could be present in this part
    if no it means it should be present on the right side since the array is 
    rotated
    hence we make left = mid+1 and go check in right direction
    IF left part is not sorted it means right part will be sorted for sure
    because suppose 
       [4 6 0 1 2] 
    left  mid is 0 then left part is not sorted but the right will be sorted 
    since the at one element only the elements won't be sorted
    we try to check if our required element is in right part by seeing if mid is smaller than target and right is larger than target then the possiblities of target can be here only otherwise the element is not present
    if element doesn't lies then the element is in left only 
    because senario like 5 1 3 target = 5 
    mid = 1 left is not sorted => that right is sorted we go and check if our element target is between mid value and right value since it is not 
    we have to set left = mid-1 because the element may be present in left side of mid and left to mid-1 may be sorted , if including mid is not sorted  
*/
    int sol(vector<int>& nums, int target)
    {
        int n =nums.size();
        int left = 0 ;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)return mid;
            //checking if left part is sorted
            if(nums[mid]>=nums[left])
            {
                //checking if the target lies in the left part
                //if no then we will have to check the target value in right half since rotated
                if(nums[left]<=target && target<=nums[mid])right = mid-1;
                else left = mid+1;
            }
            //left part is not sorted lets check in right part
            else
            {
                if(nums[right]>=target && target>=nums[mid])left = mid+1;
                else right = mid-1;   
            }

        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return sol(nums,target);
    }
};
