class Solution {
    /*
    simple approach for each element of nums1 we go in nums2 and look which element is equal to nums1 that element save the nums2 element index which is equal to nums1 element in a var called greater_index 
    again start a for loop which traverse ahead of grater_index index and if find a element greater then we save in ans otherwise the value is set -1 by default for all
    
    */
private:

    //APPROACH 1 BRUTE FORCE 0(1)
    vector<int> sol(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1,-1);
        for(int i = 0;i<n1; i++)
        {
            int greater_index = -1 ;
            for(int j = 0; j<n2; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    greater_index = j+1;
                    break;
                }
            }
            for(int j = greater_index; j<n2; j++)
            {
                if(nums2[j]>nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }

        }
        return ans;
    }
    /*
        APPROACH 2
        BETTER OPTIMIZED IN O(N)
        we find the next greater element for each element in the nums2 array and 
        approach for finding next greater elemnt
        we start from end of nums2 array
        if stack is empty we mark the current element NG(next greater) as -1
        and push the current element
        if stack is not empty we remove the element from stack which are smaller than current element and if stack is not empty we got the next greater element of current element the stack top is next greater element else
    if stack emppty there is no NG element for it
    after finding out NG we push the current element in stack
    we keep doing so for each element 

    */
    vector<int> stack_approach(vector<int>& nums1, vector<int>& nums2)
    {
        int n2 = nums2.size();
        vector<int> ans(n2,-1);
        stack<int> st;
        for(int i=n2-1; i>=0; i--)
        {

            while(!st.empty() && st.top()<=nums2[i])st.pop();
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(nums2[i]);
        }
        int n1 = nums1.size();
        vector<int> final_ans;
        for(int i = 0; i<n1; i++)
        {
            for(int j = 0 ; j<n2; j++)
            {
                if(nums1[i]==nums2[j])final_ans.push_back(ans[j]);
            }
        }
        return final_ans;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // return sol(nums1,nums2);


        //approach 2
        return stack_approach(nums1,nums2);
    }
};

