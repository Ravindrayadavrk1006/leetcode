class Solution {
private:
    *important
    //naive soln. tc nlogn +n
    int sort_method(vector<int>& nums)
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n; i++)
        {
            if(nums[i]==nums[i-1])return nums[i];
        }
        //the program will never come here
        return 0;
    }
    /*
    2. extra spaced solution 
    has extra space of O(n)
    t.c -> O(N)
    */
    int space_used(vector<int>& nums)
    {
        int n= nums.size();
        vector<int> counter(n,0);
        for(int i=0 ; i<n; i++)
        {
            if(counter[nums[i]]==1)return nums[i];
            else counter[nums[i]]++;
        }
        return 0;
    }

    //it won't work since one test case i.e [2,2,2,2,2] is wrong
    int sum_sol(vector<int>& nums)
    {
        int n = nums.size();
        int array_sum = 0;
        for(int i = 0; i<n ; i++)array_sum+=nums[i];
        int sum_without_duplicate=((n-1)*n)/2;
        return (array_sum - sum_without_duplicate);
    }
    int cycle(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        //finding cycle
    //moving slow by one position and fast by two position
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //finding start of cycle
        //now keeping the fast at nums[0] and slow at the met position in earlier loop we move both fast and slow by one position and where they meet is the our answer
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        } 
        //we return either fast or slow
        return slow ;
    }
public:
    int findDuplicate(vector<int>& nums) {
        //1.
    //    return sort_method(nums); 
        //2.
        // return space_used(nums);

        //3.
        // return sum_sol(nums);

        //4.
        return cycle(nums);
    }
};
