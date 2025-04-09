class Solution {
private:
    int min_operations_helper(vector<int>& nums, int k){
        int n = nums.size();
        int min_val = INT_MAX;
        //finding the min value of arr
        map<int,int> unique_counter;
        //unique counter, count the occurance of each element
        for(int i=0; i <n; i++){
            unique_counter[nums[i]]++;
            min_val = min(min_val, nums[i]);
        }
        //count the number of unique elmements
        int unique_cntr_size = unique_counter.size();
        //if all the elmnts are greater than k, then the answer will be count of unqiue elements
        //reason
        /*
            we have counted the occurance of each elmenet
            eg. [5,2,5,4,5] k = 1
            all 5 elmnts can become 4 ->     [4,2,4,4,4] 
            now in next iteration they can become 2  -> [2,2,2,2,2]


            //now in next iteration they can become 1 
            i.e we require three operations which is equal to the count of unique elements since from largest eleemtns are going to second largest and from second largest to third largest and so on.

        */
        if(k < min_val)return unique_cntr_size;
        /*
            since we will go till last element only not below that so , total_unique element -1
        */
        else if(k == min_val)return unique_cntr_size-1;
        /*
            if the elemnt is greater than smallest element then it won't work reason is the lower element can't be upgraded to become k which is greater than some elements
        */
        else return -1;
    }

    //according to editorial and also better
    int sol2_from_editorial(vector<int>& nums, int k){
        int n = nums.size();
        //we will use set which will store UNIQUE elements greater than k
        set<int> unique_elmnts;
        for(int el: nums){
            //if any moement we found a element less than k, then we need to return -1, because we can't increase lower number to k
            if(el < k)return -1;
            //store all the elements greater than k in the set
            if(el > k)unique_elmnts.insert(el);
        }
        return unique_elmnts.size();
    }
public:
    int minOperations(vector<int>& nums, int k) {

        //my approach
        return min_operations_helper(nums, k);


        //from editorial
        return sol2_from_editorial(nums, k);
    }
};
