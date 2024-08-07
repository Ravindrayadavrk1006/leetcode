class Solution {
/*
    approaches ->
        APPROACH 1. BRUTE FORCE
         we can use a linear search approach by checking by separtely checking for few base cases
            a. if array has one element that element index is the answer
            b. if 0th index element is greater than 1st index element then 0th index element is the answer
            c. if n-1 index element is larger than n-2th index element then that is the response

            for internal element doing a for loop from index 1 to n-2 and checking if that index element is greater than left and greater than right index element as well then that will be the response. 
        

        APPROACH 2: BINARY SEARCH APPROACH
             we can use a linear search approach by checking by separtely checking for few base cases
            a. if array has one element that element index is the answer
            b. if 0th index element is greater than 1st index element then 0th index element is the answer
            c. if n-1 index element is larger than n-2th index element then that is the response
            
            **IMPORTNAT
            d. we will check for internal element from 1 to n-2 index if mid element is greater than left and right element then that is the answer 
            else if mid element is larger than left element it means it is on increasing curve and the mid element will lie on the right
            else if mid element is smaller than the left element it means it is on the decreasing curve and the peak element will lie on left


*/
public:
    int findPeakElement(vector<int>& nums) {
        //APPROACH 2.
        int n = nums.size();
        //if just one element in the array then that is the answer since left and right of given array are -inf 
        if(n == 1)return 0;
        //there will be two or more elemnts
        //if 0th index is the peak element
        if(nums[0]>nums[1])return 0;
        //if n-1th index element is the peak element
        if(nums[n-1]>nums[n-2])return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = (low + high)/2;
            //if mid element is peak then return it
            if(nums[mid]> nums[mid-1] && nums[mid]> nums[mid+1])return mid;
            //if mid element is on increasing curve then peak will lie on right
            else if(nums[mid]> nums[mid-1])low = mid+1;
            //it means the mid is on the decreasing curve it means the peak is on the left
            else if(nums[mid]<nums[mid-1])high = mid-1;
        }

        //while will return the value anyhow but since there must be one return outside if then let's keep it -1
        return -1;
    }
};
