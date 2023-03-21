using concept of minimize the maximum 
good use of above concept
for help refer to solutions arrays-28-binary-search and arrays-29 


class Solution {
int check(vector<int>& bloomDay,int mid, int m, int k)
{
    int count= 0;
    int n = bloomDay.size();
    int i = 0;
    while(i<=n-k)
    {
        bool runner = true;
        for(int j=i;j<i+k;j++)
        {
            if(bloomDay[j]>mid)
            {
                //the point where we found bloomDay[j]>mid since it is in range of k from i that's why we won't be able to find any pattern in betwen next i should be kept j+1
                i=j+1;
                runner = false;
                break;
            }
        }
        if(runner)
        {
            count++;
            i = i+k;
            if(count>=m)return true;
        }
    }
    return false;
}

int BS(vector<int>& arr,int m,int k)
    {
        //defining the search space
        int left = 0;
        int right = 0;
        int n = arr.size();
        for(int i = 0;i<n; i++)
        {
            // left = min(left,arr[i]);
            // right = max(right,arr[i]);
            if(arr[i]>right)right = arr[i];
        }
        int initial_right = right;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(check(arr,mid,m,k))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        if(left>initial_right)return -1;
        return left;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long )m*(long long)k>(long long )bloomDay.size())return -1;
        return BS(bloomDay,m,k);
    }
};
