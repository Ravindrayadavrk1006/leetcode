/*
        approach of binary search minimize the maximum,
        here nums.size() is the number of bags already present , on performing maxOperations we will have finally nums.size() + maxOperations number of bags at the end,
        let totalBags = nums.size() + maxOperations
        we are trying to do the binary search by trying to place the all the coins in the totalBags,
        now what we will do is we will try to keep some maximum amount of balls in the bag,

        code ->
            we will do binary search by saying in a bag we can try placing maximum this amount of coin , we could place all the coins in the totalBags or in less than that bag it means it is a correct answer and we will try to minimize the maximum balls in a bag

*/

class Solution {
private:

    //helper function where we are trying to place maximum mid number of balls in bag
    //we are checking how many bags are required to fill all the balls at any moment if bags required become greater than the totalBags then we return false,
    int _possibleToAllocate(int mid, vector<int>& nums, int bags){
        int curr_bag=0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //in how many bags the current bags can be placed when maximum mid  balls are allowed in a bag , we   are doing 1*0 to convert it into float value then dividing the current bags ball by maximum balls allowed in a bag , and then doing the ciel to convert if there is any point after whole number to +1 , i.e if  (1.0 * nums[i]/mid) == 2.4 then it 3 bags will be required that's why ciel is done
            curr_bag+= ceil(1.0 *nums[i]/mid);
            //if any moment the required number of bags become greater than the maximum bag allowed we say it's not a correct answer
            if(curr_bag> bags)return false;
        }
        return true;
    }
    int solMinimumSize(vector<int>& nums, int maxOperations){
        int start = 1;
        //for the end of the search space we could take the max of the nums array and take it as end too, but not thinking much INT_MAX/2 will work fine too
        int end = INT_MAX/2;
        int n = nums.size();
        while(start <= end){
            int mid = (start + end)/2;
            if(_possibleToAllocate(mid, nums, n+ maxOperations))end = mid-1;
            else start = mid+1;
        }
        return start;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        return solMinimumSize(nums, maxOperations);
    }
};
