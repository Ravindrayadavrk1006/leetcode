class Solution {
    /*
        explanation:
            we keep a slope variable and a counter variable
            slope tells if it is increasing 1, decreasing -1, or same 0
            counter count the number of element in increasing or decreasing sequence , for same it will keep count =1 
            we start with slope =0 and counter =1 since 1 will be the least possible answer

            we check if next element is increasing and slope tells if previous element was increasing , decreasing or same , 
            if next element is inceasing and slope also incerasing we will do count++,
            in next element greater than current element and slope decrasing i.e -1 then count++
            if next element is greater than current element and if previous elmeent was not increasing it means the count will become 2,
            if next element is smaller than current and slope is not -1  count will become 2 since current element and next element are only in monotonic sequence now


    
    */
    int sol_longest_monotonic_array(vector<int> & nums){
        int n = nums.size()-1;
        int ans = 1;
        int slope = 0;
        int counter = 1;
        for(int i = 0; i<n; i++){
            if(nums[i+1] > nums[i] && slope == 1 )counter++;
            else if(nums[i+1] < nums[i] && slope== -1)counter++;
            else if(nums[i+1] > nums[i] && slope != 1){
                counter = 2;
                slope =1;
            }
            else if(nums[i+1] < nums[i] && slope != -1){
                counter = 2;
                slope = -1;
            }
            else{
                slope = 0;
                counter = 1;
            }
            ans = max(ans, counter);
        }

        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return sol_longest_monotonic_array(nums);
    }
};
