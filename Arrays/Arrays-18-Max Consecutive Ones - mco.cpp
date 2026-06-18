class Solution {
private:
    /*
        idea--> 
        we take two vars 
        int max_ones = 0;
        int temp_ones = 0;
        we traverse the array
        and
        we increase temp_ones if the value of array element is 1 and if the temp_ones value greater than max_ones we update max_ones too
        if current_element is not 1 we make temp_ones =0 which states that the current run of array is finished we will start for another run of ones
    */
    int sol(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int max_ones = 0;
        int temp_ones = 0;
        while(i<n)
        {
            if(nums[i] == 1)
            {
                temp_ones++;
                if(temp_ones>max_ones)max_ones=temp_ones; 
                i++;
            }
            else
            {
                temp_ones = 0;
                i++;
            }
        }
        return max_ones;
    }
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return sol(nums);
    }
};
