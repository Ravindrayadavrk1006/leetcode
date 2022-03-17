/*
idea => using two pointers approach since the array is sorted keeping the first pointer which points only the unique elements since the unique element
whereas the current pointer moves when it finds the unique pointer element is not equal to the current pointer element it swaps by first shifting the unique
pointer and after swaping then shifting the current_pointer too
***can imporve time by taking the current unique element in a variable and then comparing then the access to current elemnt decreases because the array has to 
to do some calculation for getting the current value

*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int vectorSize=nums.size();
        if(vectorSize<2)
        {
            return 1;
        }
        else
        {
            int currentIndex=1;
            int uniqueIndex=0;
            while(currentIndex<vectorSize)
            {
                if(nums[uniqueIndex]==nums[currentIndex])++currentIndex;
                else
                {
                    nums[++uniqueIndex]=nums[currentIndex++];
                }
            }
            return ++uniqueIndex;
        }
    }
};
