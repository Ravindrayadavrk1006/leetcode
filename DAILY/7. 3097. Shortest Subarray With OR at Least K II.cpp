class Solution {
private:
    //brute force giving TLE

    //here we are trying to generate all the probable subarray and trying to calculate the ans
  //time complexity O(n2)
    int sol1_minimumSubarrayLength(vector<int>& nums, int k){
         int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n;i++){
            int curr_or = 0;
            for(int j = i; j<n; j++){
                curr_or |= nums[j];
                if(curr_or >= k){
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
    /*
        learning since the ans is talking about subarray that is continuous then SLIDING WINDOW IS a probable approach to do it O(1)

        we are trying to add the numbers and the moment the number become equal or more than k we found one answer we update the ans with current response and trying to remove from the start side to try and see if sorter array can yield the result , if yes we keep udpateing our answer , if no then we increase the end and try adding a new number

    */

    //sol 2 from other guys 
   //WORKING SOLUTION
    //learnings -> sliding window protocol
    //T.C -> O(N)
    int sol2(vector<int>& nums, int k){
        int n = nums.size();
        //in starting the the sliding window is supposed to contain just one element hence starting and end both at 0
        int start = 0; 
        int end = 0;
        int ans = INT_MAX;
        vector<int> count(32, 0);
        while(end < n){
            //add that number
           updateBits(count, nums[end], +1) ;
           while(start <= end && get_val(count)>= k){
            ans = min(ans, end-start+1);
            //remove the front number
            updateBits(count, nums[start], -1);
            //increase the start value since removed
            start++;
           }
           //the number become less now after the removals so increase the end pointer so that this get added in the next operation
           end++;
        }

        if(ans == INT_MAX)return -1;
        return ans;
    }

    //this function is used for updating the count of each bit after adding or removing a number
    //here val is whether we want to add that number or remove that number
    void updateBits(vector<int>& count,int curr_num, int val){
        for(int i = 0; i<32; i++){
            //get the current bit and check if it is 1 then increase/decrease the ith count
            if(((curr_num>>i) & 1)== 1){
                count[i]+=val;
            }
        }
    }

    //we are getting the current number from the current bits 
    int get_val(vector<int>& count){
        int num = 0;
        for(int i= 0; i<32; i++){
            if(count[i]>0){
                num |= (1<<i);
            }
        }
        return num;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //calling basic approach giving TLE
        // return sol1_minimumSubarrayLength(nums, k);


        //working solution
        return sol2(nums, k);

    }
};
