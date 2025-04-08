class Solution {
private:
    /*
        T.C -> O(N)

        approach ->
            having a map data structure to store the count of each element
            using is_element_duplicate_st set to store those elements which occur more than once
            intially updating the map with the count of each element of nums, and if any element occur more than once we store that elemnt in the set.

            we run the for loop and it increments by thee elements because in the isnide of this loop we will process 3 elements at a time
            inside the for loop we check->
                1. if no element in the set, then we return the present time_removed counter which keep the count of number of times we have performed our oepration of removal
                2. if there are less than 3 elements then we increment the time_removed counter and return the count, eg.2 of the counter
                3.  we remove 3 elements from the current position from the map by decreasing their count in the map, if the count of element becomes 1 after removal and also the element is present in the set then we remove it since just one occurance of that element remaining now
    
    */
    int min_removal_helper(vector<int>& nums){
        int n = nums.size();
        map<int,int> mp;
        //for storing the element which has more than 1 occucrances
        set<int> is_element_duplicate_st;
        for(int el: nums){
            mp[el]++;
            //if the element has more than 1 occurance store it in the set
            if(mp[el] > 1)is_element_duplicate_st.insert(el);
        }
        //if no elmenets in the set it means no need to remove any element
        int time_removed =  0;
        for(int i = 0; i<n; i+=3){
            if(is_element_duplicate_st.size() == 0 )return time_removed;
            if(n-1-i < 3)return time_removed+1;
            else{
                //increase the counter
                time_removed++;
                //remove the next 3 elements from the current position
                for(int j = 0; j<3; j++){
                    //reduce their count
                    mp[nums[i+j]]-- ;
                    //if after removal one occurance of the elmnt, just one occurance remains we need to remove it from is_element_duplicate_st set also
                    if(mp[nums[i+j]] == 1 && is_element_duplicate_st.find(nums[i+j]) != is_element_duplicate_st.end())is_element_duplicate_st.erase(nums[i+j]);
                }
            }
        }

        //code will never reach here
        return time_removed;

    }
public:
    int minimumOperations(vector<int>& nums) {
        return min_removal_helper(nums);
    }
};
