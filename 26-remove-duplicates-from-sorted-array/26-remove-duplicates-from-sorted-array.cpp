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