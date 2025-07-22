class Solution {
    /*
        HINT: sub array, which indicates towards sliding window protocol

        APPROACH:
            1. if the current element is already present in the current window then remove all the elements from start till the occurance of that element and from the sum keep substracting the removed value 
            2. insert the current element and add it to the current sum.

            3. we have to maximize the answer, hence taking an ans variable which will be maximized with the current sum.


        
        CODE:
            we will be using queue and set, and a variable sum which will store the current valid subarray sum and ans variable which will be storing the maximum value of sum.
            1. Traverse for all elements of the array
            2. If current element is already present,  from the queue start remove all element upto the current element, at the same time keep removing the element from the set as well and substracting from the sum since the element is being removed
            3. Insert the current element and increase the sum
            4. Try maximizing the ans with current sum value


    */
private:
    int sol(vector<int>& nums ){
        int n = nums.size();
        //inserting the elment so that the order is maintained and since the elements will be removed from the front and hence easy DS choice 
        queue<int> q;
        //for checking if current element is already present in the queue or not
        set<int> st;
        // st.insert(nums[0]);
        // q.push(nums[0])
        int sum = 0;
        int ans = 0;
        for(int i =0; i<n; i++){
            //if current element is al#ready present in the queue, remove all elements upto the first occurance of that element
            //if current element is already present
            if(st.find(nums[i]) != st.end()){
                //remove all elements upto the  occurance of nums[i]
                while(q.size()){
                    int front = q.front();
                    //remove from queue
                    q.pop();
                    //remove front stack
                    st.erase(front);
                    sum-=front;
                    if(front == nums[i])break;
                }
            }
            //insert the current element in set and queue
            st.insert(nums[i]);
            q.push(nums[i]);
            //update the sum
            sum+=nums[i];
            //maximize the ans
            ans = max(ans, sum);
        } 
        return ans;  
    }


    //above solution without using queues since instead using the concept of start and end and reading those index variable from the nums array instead of again storing it in some queue uselessly, here we are using the pure concept of sliding window protocol
    int sol_variable_size_sliding_window(vector<int>& nums ){
        int n = nums.size();
        int start = 0;
        //for checking if current element is already present in the queue or not
        set<int> st;
        // st.insert(nums[0]);
        // q.push(nums[0])
        int sum = 0;
        int ans = 0;
        int end = 0;
        while(end < n){
            //if current element is al#ready present in the queue, remove all elements upto the first occurance of that element
            //if current element is already present
            if(st.find(nums[end]) != st.end() ){
                //remove all elements upto the  occurance of nums[i]
                while(true){
                    int front = nums[start++];
                    st.erase(front);
                    sum-=front;
                    if(front == nums[end])break;
                }
            }
            //insert the current element in set and queue
            st.insert(nums[end]);
            sum+=nums[end];
            //maximize the ans
            ans = max(ans, sum);
            end++;
        } 
        return ans;  
    }
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // return sol(nums);


        return sol_variable_size_sliding_window(nums);
    }
};
