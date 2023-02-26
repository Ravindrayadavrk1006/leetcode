class Solution {
private:

    //APPROACH 2
    /*
        in place sorting approach
        approach --> we use the merge sort approach by comparing the values in both the arrays
        if the element in first is smaller we incrment the pointer in first array 
        if the element in first is larger than the element in second array
        pointer position 
        we swap the values 
        after swapping we need to place the new value swapped to the nums2 at correct position for it we we use the insertion sort approach performing it's one pass 
        eg after swapping the value to the nums2 array nums2 look like
        9 5 6 10 --> 
        9 is the swapped element 
        we place the pointer at 9 and ask the next element if it's value is less than 9 if yes we swap and increment the counter we do so till 9 is reached at correct position 
    */
    void in_sort(int j ,vector<int>& nums2)
    {
        int n2 = nums2.size();
        while(j<n2-1)
        {
            if(nums2[j]>nums2[j+1])
            {
                //swap the values
                swap(nums2[j],nums2[j+1]);
            }
            j++;
        }
    }

    //main solution 2
    void sol_2(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        int j =0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])i++;
            //nums1[i] will be greater than nums2[j]
            else
            {
                swap(nums1[i],nums2[j]);
                i++;
                in_sort(j,nums2);
            }
        }
        //copying the remaining values from second array
        for(;j<n; j++)
        {
            //at i position swap and then increment i
            nums1[i++] = nums2[j];
        }
    }


    //APPROACH 3 
    /*
     see for take you forward video 
     IN PLAYLIST PLACEMENT SERIES(ARRAYS,SORTING ...) VIDEO TITLED -> MERGE TWO SORTED ARRAYS
     GAP METHOD APPROACH
    */
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //APPROACH 2

         //copy the elements of the nums1 in a temp vector
        if(n==0)
        {
            return;
        }
        //if m does not have any value
        if(m==0)
        {
            //copy nums2 values into nums1 array and return
            for(int i=0;i<n;i++)
            {
                nums1[i]=nums2[i];
            }
            return ;
        }
        sol_2(nums1,m,nums2,n);





        //APPROACH 1

        /*
        //copy the elements of the nums1 in a temp vector
        if(n==0)
        {
            return;
        }
        //if m does not have any value
        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                nums1[i]=nums2[i];
            }
        }
        vector<int> temp(m);
        for(int i=0;i<m;i++)
        {
            temp[i]=nums1[i];
        }
        //now just apply normal merge algorithm
        int i=0;
        int j=0;
        int k=0;
        
        if(m<=n)
        {
            while(i<m && j<n)
            {
                if(temp[i]<nums2[j])
                {
                    nums1[k++]=temp[i++];
                }
                else if(temp[i]>nums2[j])
                {
                    nums1[k++]=nums2[j++];
                }
                else
                    //both will be equal
                {
                    nums1[k++]=temp[i++];
                    nums1[k++]=nums2[j++];
                }
            }
            if(j==n)
            {
                for(;i<m;i++)
                {
                    nums1[k++]=temp[i];
                }
            }
            //the elements of temp array will be finished
            //copy the array elements of nums2 in nums1
            if(i==m)
            {
            for(;j<n;j++)
            {
                nums1[k++]=nums2[j];
            }
            }
        }
        
        if(m>n)
        {
            while(j<n && i<m)
            {
                 if(temp[i]<nums2[j])
                {
                    nums1[k++]=temp[i++];
                }
                else if(temp[i]>nums2[j])
                {
                    nums1[k++]=nums2[j++];
                }
                else
                    //both will be equal
                {
                    nums1[k++]=temp[i++];
                    nums1[k++]=nums2[j++];
                }
            }
            if(j==n)
            {
                for(;i<m;i++)
                {
                    nums1[k++]=temp[i];
                }
            }
            if(i==m)
            {
                for(;j<n;j++)
                {
                    nums1[k++]=nums2[j];
                }
            }
        }
    */




    }
    
};
