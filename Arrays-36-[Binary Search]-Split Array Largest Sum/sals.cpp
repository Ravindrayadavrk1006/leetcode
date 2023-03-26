Intuition
since the problem is of minimize the maximum hence took the famous approach of BS of minimizing the maximum

Approach
here using a binary search approach -->
we know minimum sum can be 0 and maximum can be sum of arrays element when k =1
hence used binary search with search spae left = 0 right sum_of_quantities
we try to divide the array element in parts so that sum doesn't execeed max value (here used variable mid ) in consideration

Complexity
Time complexity:
O(nlogn)

Space complexity:
O(1)

Code
class Solution {
bool _this_amount_possible(vector<int>& quantities,int mid,int k)
{
    int n = quantities.size();
    int temp_k = 1;
    int temp_sum =quantities[0] ;
    if(temp_sum>mid)return false;
    for(int i =1 ; i<n; i++)
    {
        if(quantities[i]>mid)return false;
        
        if(temp_sum+quantities[i]>mid)
        {
            temp_k++;
            temp_sum = quantities[i];
        }
        else
        {
            temp_sum+=quantities[i];
        }
        if(temp_k>k)return false;
    }
    if(temp_k <= k)return true;
    return false;
}
int BS(vector<int>& quantities,int k)
{
    int left = 0;
    int right = 0;
    //if arrays to be split is 1 then all the elements sum will be returned
    for(int i:quantities)
    {
        right+=i;
    }
    while(left<=right)
    {
        int mid = (left+right)>>1;
        if(_this_amount_possible(quantities,mid,k))
        {
            //if by taking this much max amount since have to minimize let's try for lesser quantity
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
    int splitArray(vector<int>& nums, int k) {
        return BS(nums,k) ;  
    }
};
