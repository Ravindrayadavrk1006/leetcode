concept of minimize by taking a certain maximum i.e minimize the maximum 
for reference look at problem arrays-28 and arrays 29


class Solution {
private:
    bool possible_to_divide(vector<int>& arr,int mid, int st)
    {
        double t = 0;
        double max_time = (double)st;
        int n = arr.size();
        for(int i =0; i<n; i++)
        {
            t+=ceil(1.0*arr[i]/mid);
            if(t>max_time)return false;
        }
        if(t<=max_time)return true;
        return false;
    }
    int BS(vector<int>& arr,int st)
    {
        //defining the search space
        int left = 0;
        int right = INT_MAX/2;
        int n = arr.size();
        // for(int i = 0;i<n; i++)
        // {
        //     // left = min(left,arr[i]);
        //     right = right+arr[i];
        // }
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(possible_to_divide(arr,mid,st))
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        return BS(nums,threshold);
    }
};
