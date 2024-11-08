/*
    explanation ->
        in simple language the question is asking what number k shall we xor with n numbers of array from start such that the final xor value is 2^maximumbit-1;
        in question it is given xor is maximized when k<2maxiumbit, the maximum xor value will be when all the maximumbit are 1 , this we came to conclusion from the fact that they are saying k<2^maximmBit, and to make the xor maximum the xor of all the numbers till i and k should be 2^maximumBit-1,   we also know that in case of maximum value all the values should be 1.

        code ->
            starting code -> solgetMaximumXor function
                according to the question n-1 index in ans vector will contain nums[0]^k
                n-2 will contain nums[0]^nums[1]^k 
                n-3 will contain nums[0]^nums[1]^nums[2]^k 
                therefore we starting storing in the answer array from last


            helper_sol given the currentxor value we return the k , here we are using the above explained concept that current_xor ^ k = all maximumBit set to 1,


*/
class Solution {
private:
    int helper_sol(int xorVal, int maximumBit){
        int max_val = 0;
        for(int  i = 0; i<maximumBit; i++){
            //get ith bit from xorVal
            int bit  = (xorVal>>i) & 1;
            //the maximum value of xor of all the elemnt will be 2^maximumBit-1 i.e all 1 , maximumBit times,
            //to get 1 using xor operation the two bit should be opposite i.e xor of 0 and 1 and 1 & 0 is 1 ,
            //hence using the same concept

            //if the current bit is 0 then to make the xor maximum the k should have that bit set to 1, doing the same
            if(!bit){
                //setting ith bit to 1 , if ith bit in xorVal is 0 to maximize the result
                max_val = (1<<i) | max_val;
            }
        }
        return max_val;
    }
    vector<int> solgetMaximumXor(vector<int>& nums, int maximumBit){
        int n = nums.size();
        vector<int> ans(n);
        //doing for n-1 index ans outside the for loop , so that we have a start curr_xor value in the for loop and we don't have to assume anything outside , we could also start by assumign initial value to be  curr_xor value to be 0 and in the for loop starting i = 0
        int curr_xor = nums[0];
        ans[n-1] = helper_sol(curr_xor,maximumBit);
        for(int i =1; i<n; i++){
            curr_xor^=nums[i];
            ans[n-1-i] = helper_sol(curr_xor,maximumBit);
        }
        return ans;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        return solgetMaximumXor(nums, maximumBit); 
    }
};
