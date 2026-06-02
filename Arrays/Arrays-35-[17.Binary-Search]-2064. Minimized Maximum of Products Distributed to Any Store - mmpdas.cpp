concept of minimize the maximum


class Solution {
private:

//APPROACH 1
//this approach doesn't work
    int sol(vector<int>& quantities, int n)
    {
        int q_size = quantities.size();
        if(q_size>=n)
        {
            int max_el = 0;
            for(int el:quantities)max_el = max(el,max_el);
            return max_el;
        }
        long long sum = 0;
        for(int el:quantities)
        {
            sum+=(long long )el;
        }
        if(sum%long(n) != 0)return (sum/(long)n)+1;
        else return sum/(long)n;
    }

//APPROACH 2 
//BINARY SEARCH APPROACH

#here by looking at the problem statement we see that only one item at max can be given to a store and hence tried to do same
#if we try to give mid amount to each one and if some element are left from that quantity we give the remaining to the next store and that next store
#can't take any more element since can take only one item type 
bool _this_amount_possible(vector<int>& quantities,int mid, int n)
{
    int temp_n = 0;
    for(int i = 0;i<quantities.size(); i++)
    {
        if(quantities[i]%mid == 0)temp_n+=quantities[i]/mid;
        else
        {
            temp_n+=quantities[i]/mid+1;
        }
        if(temp_n>n)return false;
    }
    return true;
}
int BS(vector<int>& quantities,int n)
{
    int left = 1;
    int right = 0;
    //store the maximum value in right since one store can get max of one lot only
    for(int i:quantities)
    {
        if(i>right)right = i;
    }
    while(left<=right)
    {
        int mid = (left+right)>>1;
        if(_this_amount_possible(quantities,mid,n))
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
    int minimizedMaximum(int n, vector<int>& quantities) {
        //approach 1 giving wrong answer
        // return sol(quantities,n);

        //APPROACH 2
        return BS(quantities,n);

    }
};
