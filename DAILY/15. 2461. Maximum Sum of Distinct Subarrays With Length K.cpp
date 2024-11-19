class Solution {

/*
    this problem is simple we are using window to insert k consecutive elements trying to form all the subarrays,
    one issue is that it is talking about we should only consider k consecutive unique elements,
    this unique is the main thing we have to solve here,
    if it was non unique then forming all sub arrays of size k using normal window of size k we would have solved it,

    for unqiue -> we are using set data structure as a window,
    we are using hashmap for keeping the count of elements , if the current element to be removed while forming the window if it's count becomes zero then only we remove it else in our window there are some more occurance of this element and we can't remove it yet.
    visualize in test case [9,9,9,1,2,3],


*/
private:
    long long solMaximumSubarraySum(vector<int>& nums, int k){
        long long ans = 0LL;
        int n = nums.size();
        //this is our window
        unordered_set<int> st;
        long long current_sum = 0;
        //element count map
        map<int, int> mp;
        for(int i=0; i<k; i++){
            //insert in the set
            st.insert(nums[i]);
            //find if the elment present in map or not
            bool notPresent = mp.find(nums[i]) == mp.end();
            //if not present then insert it
            if(notPresent){
                mp[nums[i]] = 1;
            }
            //if element already present in the map increase it's count
            //increment the count of that variable
            else{
                mp[nums[i]]++;
            }
            //creating current sum by adding all the elements of our window
            current_sum+= nums[i];
        }
        //**important current_sum get's updated normally as if it was a normal subarray problem , i.e at each elenment we add nums[i] and substract nums[i-k]
        // cout<<"current_sum"<<current_sum<<" "<<mp[nums[0]]<<endl;

        //if our current set has three element then it's a possible answer
        if(st.size() == k)ans = max(ans,current_sum);
        //trying other windows
        for(int i=k; i<n; i++){
            //trying to remove the i-kth element 
            //decreasing it's count
            mp[nums[i-k]]--;
            //if the count of nums[i-k] == 0 it will be removed
            if(mp[nums[i-k]] <=0){
                st.erase(nums[i-k]);
                //remove it from the map because it went out
                mp.erase(nums[i-k]);
            }
            //insert the new element in the window
            st.insert(nums[i]);
            //update the current element being added count in the window to the map as well
            if(mp.find(nums[i]) == mp.end())mp[nums[i]]=1;
            else mp[nums[i]]++;
            //updating the current sum normally
            current_sum+= (nums[i] - nums[i-k]);
            //if our current window has k elements it means it's a possible answer
            if(st.size() == k)ans = max(ans, current_sum);
        }
        return ans;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        return solMaximumSubarraySum(nums, k);
    }
};
