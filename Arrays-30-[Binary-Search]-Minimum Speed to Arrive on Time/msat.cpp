
CONCEPT OF MINIMIZE THE MAXIMUM

class Solution {
    //using the concept of minimize the maximum
    /*
    
        at a time we are taking a certain amount of speed and checking if possible to reach our destination at this speed in the given time ==> we say okk if we could reach in this amount of speed let's try to check if we could reach the destination in less than this speed [for trying these speeds we are using binary search]
        in possible_to_reach funtion what we do is by taking that speed which we are trying we try to run and check if are able to reach the destination in the given time, if yes we are able to try to reduce the speed and check if we can reach by travelling at less speed then the speed we tried. If possible_to_reach functions says we are not able to reach we try to increase the speed and check


        T.C --> O(nlogn)
        S.C --> O(1)
    */
private:
    bool possible_to_reach(vector<int>& arr,int mid, double st)
    {
        double t = 0;
        int n = arr.size();
        for(int i =0; i<n-1; i++)
        {
            t+=ceil(1.0*arr[i]/mid);
            if(t>st)return false;
        }
        t+=(1.0*arr[n-1]/mid);
        if(t<=st)return true;
        return false;
    }
    int BS(vector<int>& arr,double st)
    {
        //defining the search space
        //minimum interger speed 
        int left = 1;
        
        //tried to take a max value here our test cases are sufficed by INT_MAX/2  
        int right = INT_MAX/2;
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
        if(left>=1e9)return -1;
        return left;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        return BS(dist,hour);
    }
};
