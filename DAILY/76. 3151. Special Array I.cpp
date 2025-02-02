class Solution {
private:


    bool sol_is_special_array(vector<int>& nums){
        int parity = nums[0]%2;
        int n = nums.size();
        for(int i=1; i<n; i++){
            int curr_parity = nums[i]%2;
            if( curr_parity == parity)return false;
            parity = curr_parity;
        }
        return true;
    }

    //using bitwise and to get if it's odd or even
    bool using_bitwise_and(vector<int> nums){
        int parity = nums[0] & 1;
        int n = nums.size();
        for(int i =1; i<n; i++){
            int curr_parity = nums[i]&1;
            if(parity == curr_parity)return false;
            parity = curr_parity;
        }
        return true;
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        // return sol_is_special_array(nums);

        return using_bitwise_and(nums);
    }
};
