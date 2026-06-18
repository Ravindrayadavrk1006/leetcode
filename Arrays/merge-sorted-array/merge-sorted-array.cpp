
//time complexity O(m+m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
        
    }
};