class Solution {
private:
    /*
    using the concept of FRONT PARTITION
    very similar to palindrom paritioning 
    here they are that a partition can be max of size k 
    i.e means it can have 1 to k elements 
    hence we consider all the cases from 1 to k and return the maximum out of them
    for ex.  arr = [1,15,7,9,2,5,10], k = 3
    here we can have (1{15,7,9,2,5,10}), (1,15{7,9,2,5,10}),(1,15,7{9,2,5,10})
    we can have as the above parition and the {} need to be solved recursively
    */
    int sol(int i,vector<int>& arr, int k,int n , vector<int>& dp)
    {
        if(i==arr.size())return 0;

        //normal cases
        //exploring all the possibilities of parition of size 1 to k
        //note j<min(n,i+k) min done since i+k may exeed the n values hence till n only
        
        if(dp[i] != -1)return dp[i];
        //for finding the max value as per question
        int max_val = -1e9;
        //keeping track of max value and length till now since we have to do according to question max_val_of_current_parition*lengthof_current_parition
        int length_of_current_parition = 0;
        int max_val_of_current_parition = -1e9; 
        for(int j = i; j<min(n,i+k) ; j++)
        {
            length_of_current_parition++;
            max_val_of_current_parition= max(max_val_of_current_parition,arr[j]);
            int curr_val = length_of_current_parition*max_val_of_current_parition + sol(j+1,arr,k,n,dp);
            max_val = max(max_val , curr_val);
        }
        return dp[i] = max_val;

    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return sol(0,arr,k,arr.size(),dp);
    }
};
