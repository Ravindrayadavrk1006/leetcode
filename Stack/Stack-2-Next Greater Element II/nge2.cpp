class Solution {
private:

    //BRUTE FORCE APPROACH
    vector<int> sol(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i = 0; i<n; i++)
        {
            int j = (i+1)%n;
            int count = 0;
            while(count<n)
            {
                if(nums[j]>nums[i])
                {
                    ans[i]=nums[j];
                    break;
                }
                else
                {
                    count++;
                    j=(j+1)%n;
                }
            }
        }
        return ans;
    }

    //APPROACH 2
    //OPTIMIZED STACK APPROACH--->
    //for reference look at Next Greater Element I solution
    /*
        using approach of next greater element and since here we have to deal the case of circular array hence we just copy paste all the element once more at last in the new array and find next greater element 
        the array on which we perform NG(next greater stack approach) will be of size of 2*size of nums 
    */
    vector<int> stack_approach(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> new_vec;
        // for(int i = 0; i<n; i++)new_vec.push_back(nums[i]);
        // for(int i = 0; i<n; i++)new_vec.push_back(nums[i]);
        int new_vec_size = 2*n;
        vector<int> ans(2*n,-1);
        stack<int> st;
        for(int i=new_vec_size-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<=new_vec[i])st.pop();
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(new_vec[i]);
        }
        vector<int> ans_final;
        ans_final.assign(ans.begin(),ans.begin()+n);
        return ans_final;
    }
    //same above approach a bit cleaner and more optimized
    /*
        we will use modules to get value above n 
        suppose array 1 2 1 
        n =3 for repeating element for getting element at 4th index place we do 4%3 i.e we get 1 index i.e 2 
        also we don't need to store values for above n 
    */
    vector<int> cleaner_approach(vector<int> & nums)
    {
        int n = nums.size();
        vector<int> ans(n,-1);
        int traverse = 2*n ;
        stack<int> st;
        for(int i = traverse-1; i>=0; i--)
        {
               while(!st.empty() && st.top()<=nums[i%n])st.pop();
               if(i<n)
               {
                    if(!st.empty())
                    {
                        ans[i]=st.top();
                    }
               }
               st.push(nums[i%n]);
        }
        return ans;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // return sol(nums);

        // return stack_approach(nums);
        return cleaner_approach(nums);
    }
};
