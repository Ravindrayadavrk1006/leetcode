class Solution {
    /*
        approach 1: naive approach for each element from last run a for loop 
        to find the number of elements whose value is greater than 2*for whom for loop is running
        T.C O(n*2)

        approach 2:
            See COUNT INVERSIONS saved in github not on leetcode

            we are using the same concept of merge sort
            how we are couting no of inversion

            eg. 
            [12,19,25,40]  [2, 6, 9]

            so what we do is we place i ptr in first array and j ptr in second array
            if array_left[i]>2*array_right[j] we increase j
            else we increase i

            since our observation :
            for elmnt at j is 2 and at i = 12
            we find that 12>2*2 hence we increase j thinking that 12 is satisfying for 2 and we say 12 satisfies for just 2
             let's see if it satisfies for others
            elmnt at j is 6 
            we find that  12 not greater than 2*6 hence we increment i
            el at i = 19 and at j 6 
            in final answer we will add 1 (no of elemtn to left of j)
            we will add to answer when we are incrementing i only reason is 
            we try to find all the element in right array which can sastisfied with the current i value and once we find the current i can't satisfy the current j value 
            we add all the element values which has been satisfied by the current i
            19>2*6 hence we increment j and
            now we see
            j at 9 and i at 19
            we see it satisfies for 9 too i.e 19>2*9 
            we incrmnt j 
            now j greater than array
            
            since j is finsiehd which means for 19 and all the other coming element in i will be satisfied  hence we add the right array size in for all the remaining i values
    */
    int _merge_algo(vector<int>& nums,int left,int mid ,int right)
    {
        int count = 0 ;
        vector<int> temp;
        int j = mid+1;
        for(int i = left; i<=mid; i++)
        {
            while(j<=right && (long long)nums[i]>2*(long long)nums[j])j++;
            count+=j-(mid+1);
        }
        //doing the merging algorithm now
        int i = left;
        j= mid+1;
        while(i<=mid && j<=right)
        {
            if(nums[i]<=nums[j])temp.push_back(nums[i++]);
            else
            {
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i++]);
        }
        while(j<=right)
        {
            temp.push_back(nums[j++]);
        }
        //copy the temp array in the original array nums
        int n = temp.size();
        for(int i =0; i<n; i++)
        {
            nums[left+i]=temp[i];
        }
        return count;
    }
    int merge_sort(vector<int>& nums,int left,int right)
    {
        if(left>=right)return 0;
        //divide
        int mid = (left+right)/2;
        int count = 0;
        //left side
        count+=merge_sort(nums,left,mid);
        count+=merge_sort(nums,mid+1,right);
        count+=_merge_algo(nums,left,mid,right);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};
