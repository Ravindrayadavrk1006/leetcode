/*
appraoch from striver 1 
not the one used coded below
O(n^3 ) complexity 
we take three loop 
i -> 0->n-1
j-> i to n-1
k runs from i to j to calculate the sum of this subarray

the idea behind this approach we try to form all the subarray and callculate their sum and compare with a final_sum which is intialized to nums[0];

appraoch from striver 2:
    O(n^2)
    since k is just used to calulate the sum we intialize sum = 0;
    in ith loop and in jth loop for each run we just do sum+nums[j] and compare it with the final_sum value

appraoch 3 from striver kadanes algorith:
    O(n)
    here we keep sum intialized to 0
    and max_val = nums[0];
    we start traversing and if the sum value become less than 0 we mkae sum =0 afte comparing it with max_val=max(max_val,sum)
    we are updating to 0 since if the value is coming negative that won't be usefull in the coming subarray
    and hence when the sum value becomes <0 then we say we won't be using this subarray le't try to form a new subarray with intial value 0

*/






class Solution {
private:
//appraoch 3 from striver kadanes algorithm:
    int kadane_algo(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        int max_val = nums[0];
        for(int i = 0 ;i<n ; i++)
        {
            sum+=nums[i];
            max_val = max(max_val,sum);
            if(sum<0)sum = 0;
        }
        return max_val;
    }
public:

    //approach 3 --> divide and conquer approach
    int cross_sum(vector<int>& nums, int p, int q)
    {
        int mid=(p+q)/2;
        int left_sum=0;
        int left_best_sum=0; 
        for(int i=mid;i >= p;i--)
        {
            left_sum+=nums[i];
            if(left_sum > left_best_sum)
            {
                left_best_sum=left_sum;
            }
        }
        //right side of cross sum
        int right_sum=0;
        int right_best_sum=0;
        for(int i=mid+1;i<=q;i++)
        {

                right_sum +=nums[i];
                if(right_sum > right_best_sum)
                {
                    right_best_sum=right_sum;
                }
        }
        return right_best_sum+left_best_sum;
    }
    int help(vector<int>& nums, int p, int q)
    {
       if(p==q)return nums[p];
       else
       {
           int mid=(p+q)/2;
           int left_sum=help(nums,p,mid);
           int right_sum=help(nums,mid+1,q);
           int cross_sum_result=cross_sum(nums,p,q);
           return max(left_sum,max(right_sum,cross_sum_result));
       }
        
    }
    int maxSubArray(vector<int>& nums) {
        // int temp=0;
        // int n=nums.size();
        // return help(n,nums); 
        //handling negative cases
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]>=0)break;
            i++;
        }
        if(i == nums.size() )return (*max_element(nums.begin(),nums.end()));
        //calling the solution 3 Dviide and Conqueor
        // else return help(nums,0,nums.size()-1);
        //calling kadanes algo striver sol 3
        else return kadane_algo(nums); 
    }
};




//approach 2
// class Solution {
// public:
//     int help(int n, vector<int>& nums)
//     {
//         int max_sum=nums[0];
//         int curr_sum=nums[0];
//         // int start_pos=0;
//         int curr_pos=1;
//         while(curr_pos<n)
//         {
//             // curr_sum+=nums[curr_pos];
//             if(curr_sum>0)
//             {
//                 // start_pos=curr_pos+1;
//                 curr_sum+=nums[curr_pos];
//             }
//             else
//             {
//                 curr_sum=nums[curr_pos];
//             }
//             if(curr_sum>max_sum)
//             {
//                 max_sum=curr_sum;
//             }
//             curr_pos++;
//         }
//         return max_sum;
        
//     }
//     int maxSubArray(vector<int>& nums) {
//         int temp=0;
//         int n=nums.size();
//         return help(n,nums); 
//     }
// };
//approach 1
// class Solution {
// public:
//     int help(int n, vector<int>& nums)
//     {
//         int max_sum=0;
//         int curr_sum=0;
//         // int start_pos=0;
//         int curr_pos=0;
//         while(curr_pos<n)
//         {
//             curr_sum+=nums[curr_pos];
//             if(curr_sum<=0)
//             {
//                 // start_pos=curr_pos+1;
//                 curr_sum=0;
//             }
//             if(curr_sum>max_sum)
//             {
//                 max_sum=curr_sum;
//             }
//             curr_pos++;
//         }
//         return max_sum;
        
//     }
//     int maxSubArray(vector<int>& nums) {
//         int temp=0;
//         int n=nums.size();
//         handling negative values very neive solution
//         while(temp<n && nums[temp]<0)temp++;
//         if(temp==n)return *max_element(nums.begin(), nums.end());
//         return help(n,nums); 
//     }
// };
