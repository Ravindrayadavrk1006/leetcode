/*
    explanation ->
        asked to count the number of pairs which lie in given range,
        the basic appraoch is finding in O(n^2) by checking all the pairs but it will give TLE because n<10^5 in constraint and it will never pass


        approach -> sort the nums array, then for each eleemnt in this array we are finding the maximum number whose addition with current nums[i] satisfies our answer i.e <= upper and minmum number whose addition satifies our range i.e nums[i]+ minimum number > = lower,

        since the array is sorted we can use binary search to do the searching.
        for finding the maximum mumber which satisfies our condition of nums[i] + maximum_number <= upper     => maximum_number <= upper- nums[i]

        similarly for lower number which satifsies our answer,

        we will get indexes in both the cases and if our maximum index number which satifies our range if grater than i then it means it is correct and also smallest index should be less than n and  smallest_index<= largest , all the numbers in between our smallest and largest index will satisfies the answer for nums[i] , hence largest index- smallest index +1 
*/

class Solution {

private:


    //binary search equal or lesser
    int helperBinarySearchEqualLess(vector<int>& nums,int start, int val){
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start + end)/2;
            //if current value is greater it means we are not in range , hence decrease the end and bring in range
            if(nums[mid]> val )end = mid-1;
            else start = mid+1;
        }
        //our range is from 0 to end hence return end
        return end;
    }

    //equal to greater
    int helperBinarySearchEqualGreater(vector<int>& nums,int start, int val){
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start + end)/2;
            //since we need greater or equal and if our current value is smaller we increase start and try going in correct range
            if(nums[mid]< val )start = mid+1;
            else end = mid-1;
        }
        //see how equal and greater it means our range will start from start till n, all of them satisfies our answer
        return start;
    }
    long long solCountFairPairs(vector<int>& nums, int lower, int upper){
        long long ans = 0;
        //creating offline queries of nums array
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            // cout<<"i "<<i << " "<<nums[i]<<endl;
            //here the value of number to be compared is sent upper -nums[i] , this is because we want nums[i] + binaryserachcurrentpos element > upper in binary search this line -> if(nums[mid]> val )end = mid-1; so just moving  the values left and right and passing here only
            int  end = helperBinarySearchEqualLess(nums, i+1, upper-nums[i]);
            int start = helperBinarySearchEqualGreater(nums, i+1, lower - nums[i]);
            // cout<<"start "<<start<<" end"<<end<<endl;
            if(end>i && start<n && start <= end)ans += (end-start + 1LL);
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return solCountFairPairs(nums, lower, upper);
    }
};
