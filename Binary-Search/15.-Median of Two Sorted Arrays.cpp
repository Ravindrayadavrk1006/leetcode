class Solution {
    /*
        approach1--> we merge both the sorted arrays using merge sort approach 
        and then return the (m+n)/2 th element if m+n is odd else return sum of    (n/2)-1 th and (n/2)-1+1  and half it 
        T.C-> O(n+m) S.C -> O(n+m)
    
    */
private:
    double approach_1(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3(n+m);
        //using merge algo for merging two sorted arrays
        int i = 0 ; 
        int j = 0;
        int k = 0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                nums3[k++]=nums1[i++];
            }
            else nums3[k++]=nums2[j++];
        }
        while(i<m)nums3[k++]=nums1[i++];
        while(j<n)nums3[k++]=nums2[j++];
        //now nums3 is sorted 
        //finding the median value
        //i.e size of nums3 is odd
        if((m+n)%2 != 0)return (double)nums3[(m+n)/2];
        else
        {
            int pos = (m+n)/2;
            double first = (double)nums3[pos-1];
            double second = (double)nums3[pos];
            return (first+second)/2.0;
        }
    }
    //we can improve this above solution since we need the element m+n/2 in case of odd and m+n/2 and (m+n/2)-1th element in case of even
     //so we keep a counter instead of sorting and placing the element we keep on incremting k and when we see that k has reached the required number we just take those elements and return t.c will be reduced a lot

     /*
        APPROACH 2 -->
        using binary search t.c Olog(n)
     */

     /*
        explained in CP notes under binary search topic
     */
     double approach_2(vector<int>& nums1, vector<int>& nums2)
     {
         //for reducing the time complexity of logn we take the left array to be smaller size
         if(nums2.size()<nums1.size())return approach_2(nums2,nums1);
         int n1 = nums1.size();
         int n2 = nums2.size();

        int left = 0;
        int right = n1;
        while(left<=right)
        {
            //cut in first array
            int cut1 = (left+right)/2;
            //cut in second nums2 array
            //n1+n2+1/2 is the numbe of element we require in the left side i.e incudling from both first array and second array in total
            int cut2 = (n1+n2+1)/2-cut1;


            //if there are no element in left side from any let's set to int_min since int-min will always satisfy the comparison we ar going to have further in if conditions
            int left1 = cut1 ==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 ==0? INT_MIN : nums2[cut2-1];
            //similary if there are not right elements in the cut array we will set to int_max for the sake of unfailing comparisons
            int right1 = cut1==n1?INT_MAX:nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX:nums2[cut2];


            //if this if conditions satisfies it means we have made correct cuts
            if(left1<=right2 && left2<=right1)
            {
                //if total elements are odd , it means we return maximum of both the left part
                if((n1+n2)%2 != 0 )return (double)max(left1,left2);
                //if n1+n2 is even
                else
                {
                    int first = max(left1,left2);
                    int second = min(right1,right2);
                    return (double)(first+second)/2.0;
                }

            }

            //if the cut made is not at right place
            //if left part has a number greater than the right part it means we have to remove some element from left part and hence we move do that
            else if(left1>right2)
            {
                right = cut1-1;
            }
            else 
            {
                left = cut1+1;
            }
        }
        return 0.0;
     }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return approach_1(nums1,nums2);
        if(nums1.size()==0)
        {
            int n2 = nums2.size();
            if(n2%2 != 0)return (double)nums2[n2/2];
            else 
            {
                double left = (double)nums2[n2/2];
                double right =(double)nums2[n2/2-1];
                return (left+right)/2.0;
            }
        }
         if(nums2.size()==0)
        {
            int n1 = nums1.size();
            if(n1%2 != 0)return (double)nums1[n1/2];
            else 
            {
                double left = (double)nums1[n1/2];
                double right =(double)nums1[n1/2-1];
                return (left+right)/2.0;
            }
        }
        return approach_2(nums1,nums2);
    }
};
