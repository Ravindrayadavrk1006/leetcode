class Solution {
private:
    //idea we count the number of 0,1,2 and then places the numebr of elements in the array
    void sol_count(vector<int>& nums)
    {
        int zeros = 0;
        int ones = 0;
        int twos= 0;
        int n =nums.size();
        for(int i = 0;i<n ; i++)
        {
            if(nums[i]==0)zeros++;
            else if(nums[i]==1)ones++;
            else twos++;
        }

        //we have the count
        int pos = 0;
        for(;pos<zeros;pos++)
        {
            nums[pos]=0;
        }
        for(;pos<zeros+ones; pos++)
        {
            nums[pos]=1;
        }
        for( ;pos<n;pos++)
        {
            nums[pos]=2;
        }
    }
    //T.C --> (2*n )
    void sol_swap(vector<int>& nums)
    {
        int n = nums.size();
        //this will represent the 0 to which all are sorted
        int s_pt_0 = 0;
        //this is used to find all the 0 
        int pt_0 = 0;
        for(pt_0 = 0 ; pt_0<n; pt_0++)
        {
            if(nums[pt_0] == 0)
            {
                //swap the element
                nums[pt_0] = nums[s_pt_0];
                nums[s_pt_0] = 0;
                s_pt_0++;
            }
        }
        //placing all the twos to right side
        int s_pt_2 = n-1;
        int pt_2 = n-1;
        for(pt_2 = n-1 ; pt_2>=0; pt_2--)
        {
            if(nums[pt_2] == 2)
            {
                //swap the element
                nums[pt_2] = nums[s_pt_2];
                nums[s_pt_2] = 2;
                s_pt_2--;
            }
        }
    }


    /*

    DUTCH NATIONAL FLAG ALGORITHM
    solving in order of 1 
    the idea is use to use a singler pointer which
     1.when find 0 replaces with the poisition which represent all the elemtns 0 's right i.e s_pt_0 in above solution
     2. when find 2 it replaces with the position on right with the pointer which represent 2's sorted position

    swapping rule
    if nums[pt] == 1 we simply increment pt value
    if nums[pt] ==0 we swap and increment pt_0 and pt value
    if nums[pt] == 2 we decrment pt_2 value and keep the pt value at same position because the swapped value which came might be 0 which need to be swapped to pt_0 position
    we didn't keep pt at same position in case of nums[pt] == 1 since there won't be any 2 there since pt would have travelled that position already
    */
    
    void sol_2(vector<int>& nums)
    {
        int n = nums.size();
        int pt_0 = 0;
        int pt_2 = n-1;
        while(pt_2>=0 && nums[pt_2] == 2 )pt_2--;
        int pt = 0;
        while(pt<=pt_2)
        {
           if(nums[pt] == 0)
           {
               nums[pt] = nums[pt_0];
               nums[pt_0] = 0;
               pt_0++;
               pt++;
           }
           else if(nums[pt] ==2)
           {
               nums[pt]=nums[pt_2];
               nums[pt_2] = 2;
               pt_2--;
           }
           else pt++;
        }
    }
    
public:
    void sortColors(vector<int>& nums) {

        //1 count sol
        // sol_count(nums);
        // sol_swap(nums);
        sol_2(nums);

    }
};
