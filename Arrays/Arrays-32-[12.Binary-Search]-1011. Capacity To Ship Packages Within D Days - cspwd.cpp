using the concept of minimize the maximum approach
see arrays-29-binary search for reference and better explanation

class Solution {
private:
    bool _allocation_possible(vector<int>& arr, int mid, int st )
    {
        int temp_st = 0;
        int pages = 0;
        for(int i =0;i<arr.size(); i++)
        {
            //since a entire book has to be atleast allocated to a person
            if(arr[i]+pages > mid)
            {
                pages = arr[i];
                temp_st++;
                if(pages>mid)return false;
            }
            else
            {
                pages+=arr[i];
            }
            
        }
        if(temp_st<st)return true;
        return false;
    }
    int BS(vector<int>& arr,int st)
    {
        //defining the search space
        int left = 0;
        int right = 0;
        int n = arr.size();
        for(int i = 0;i<n; i++)
        {
            // left = min(left,arr[i]);
            right = right+arr[i];
        }
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(_allocation_possible(arr,mid,st))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        return BS(weights,days);
    }
};
