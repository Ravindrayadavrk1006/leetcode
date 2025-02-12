/*
    T.C -> O(nlogn)
    storing  

*/
class Solution {
private:
    //helper function for finding the sum of digits of each number 
    void helper_digit_sum(vector<int>& nums, vector<pair<int,int>>& digit_sum){
        int n = nums.size();
        //for each number of nums array
        for(int i = 0; i<n; i++){
            //find it's digit sum and store at digit_sum[i] the sum of digits of nums[i]
            int curr_num = nums[i];
            digit_sum[i].second = i;
            while(curr_num != 0){
                digit_sum[i].first+=curr_num % 10;
                curr_num/=10;
            }
        }
    }
    /*
        creating the sum of digit of each numbr of nums array, along with the sum we are storing the index of element as well, because we will be sorting this sum array and we will require the index hence creating offline query.
        Now sort this digit_sum array in descending order , doesn't matter if ascending or descending but done in descending order. 

        Now all the numbres whose sum are same will be together.

        we find the largest two number where sum of elements are same, this is done because let's suppose,
        163 333  139 900   -> each element has sum 9 and but the two number which contribute in the answer will the largest two numbers out of it hence we will find the largest two number of each group where digit_sum[i] is same.


        for each group we are finding the largest two numbers and then doing the ans = max(ans , current two largest number where each digit_sum is same) 
    
    */
    int sol_maximum_sum(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>> digit_sum(n, pair<int,int>(0, 0));
        helper_digit_sum(nums, digit_sum);
        // for(int i = 0; i<n; i++){
        //     cout<<digit_sum[i].first<<" ";
        // }
        cout<<endl;
        sort(digit_sum.begin(), digit_sum.end(), greater<pair<int,int>>());
        // for(int i = 0; i<n; i++){
        //     cout<<digit_sum[i].first<<" "<<digit_sum[i].second<<" ---";
        // }
        // cout<<endl;



        //default answer
        int ans = -1;


        ////here we are finding the largest two numbers of each group and maximizing the ans

        // here we are dealing with storing the index of two largest numbers
        //l1 is largest, l2 is the second largest number
        //initlaizing l1 with the index of first element 
        int l1 = digit_sum[0].second;
        int l2 =  -1;

        //run a for loop ffrom indx 1 
        for(int i = 1; i<n; i++){
            //if current element digit_sum is same as previous element digit_sum
            if(digit_sum[i].first == digit_sum[i-1].first){
                //since in digit_sum[i].second we are storing the index of elment from nums,
                //we are saying if current element is greater than previous largest then update the largest and make l2 = l1 since earlier l1 was largest so now it will become second larget
                if(nums[digit_sum[i].second] > nums[l1]){
                    //here order is important that is l2 = l1 should be done first 
                    l2 = l1;
                    l1 = digit_sum[i].second;
                }
                //if currenet eleemtn is not larger than nums[l1] then checking if current element is greater than nums[l2] , if l2 = -1 then we directly store current elemnt in l2
                else if(l2 == -1  || nums[digit_sum[i].second] > nums[l2]){
                    l2 = digit_sum[i].second;
                }
            }

            //if current element is not same as previous elment then 
            //we maximimze the answer from previous two larget
            else{
                //it may happen that we didn't have a pair yet hence, wheras pair is necessary hence checking if there is no value in l2 then don't maximize
                if(l2 != -1){
                    ans = max(ans, nums[l1] + nums[l2]);
                }

                //set the current element as largest
                l1 = digit_sum[i].second;
                //second largest will have nothing
                l2 = -1;
            }
        }
        if(l2 != -1){
                ans = max(ans, nums[l1] + nums[l2]);
            }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        return sol_maximum_sum(nums);
    }
};
