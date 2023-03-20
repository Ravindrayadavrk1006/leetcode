exactly same as Arrays-30-[Binary-Search]-Minimum Speed to Arrive on Time


class Solution {
private:
    bool possible_to_reach(vector<int>& arr,int mid, int st)
        {
            double t = 0;
            double max_time = (double)st;
            int n = arr.size();
            for(int i =0; i<n-1; i++)
            {
                t+=ceil(1.0*arr[i]/mid);
                if(t>max_time)return false;
            }
            t+=(1.0*arr[n-1]/mid);
            if(t<=max_time)return true;
            return false;
        }
    int BS(vector<int>& arr,int st)
        {
            //defining the search space
            //minimum interger speed 
            int left = 1;
            
            //tried to take a max value here our test cases are sufficed by INT_MAX/2  
            int right =  INT_MAX/2;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if(possible_to_reach(arr,mid,st))
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
    int minEatingSpeed(vector<int>& piles, int h) {
        return BS(piles,h);
    }
};
