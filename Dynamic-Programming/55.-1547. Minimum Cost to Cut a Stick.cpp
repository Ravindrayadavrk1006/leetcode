class Solution {
public:

    /*
        type --> PARITIONING DP 
        similar stuff --> very similar to Matrix chain multiplication(MCM)
        same idea as of MCM
    
    */
    int sol(int i , int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j)return 0;
        int min_val = 1e9;
        //normal cases
        if(dp[i][j] != -1)return dp[i][j];
        for(int k = i ; k<=j; k++)
        {

            /*
            cuts[j+1]-cuts[i-1]
            length of the current string since let's take cuts = [1 3 4 5 ]
            let's and size of array to be 7 let's insert 
            [0 1 3 4 5 7]   
            and we start form value 1 to 5 in the above array
            for size we will get cuts[j+1]-cuts[i-1] = 7-0 = 7
            let's suppose parition at 4
            ==> the parts will be sol(i,k-1)+sol(k+1,j) where in above case case k is index of 4 ;
            [0 1 3]  [5 ,7]
            for  [0 1 3] i = 1, j = 2 cuts[j+1] means value 4 which clearly states that we have are paritioning sticks with end like  (0 ,4),(4,7) since we are taking cuts[j+1]-cuts[i-1] 
            
            */
            int curr_val = cuts[j+1]-cuts[i-1]+sol(i,k-1,cuts,dp)+sol(k+1,j,cuts,dp);
            if(curr_val<min_val)min_val = curr_val;
        }
        return dp[i][j] = min_val;
    }
    // int tabulation(int n , vector<int>& cuts)
    // {
    //     cuts.insert(cuts.begin(),0);
    //     cuts.push_back(n);
    //     //imported to make it similart to matrix chain multiplication and we don't have to worry about places of cut when trying different cuts order
    //     sort(cuts.begin(),cuts.end());
    //     int cuts_size= cuts.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));

    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        //imported to make it similart to matrix chain multiplication and we don't have to worry about places of cut when trying different cuts order
        sort(cuts.begin(),cuts.end());
        int cuts_size= cuts.size();

        //important point ponder over the correct size of DP here taking a larger size of dp gave TLE in half of the cases
        vector<vector<int>> dp(cuts_size-1,vector<int>(cuts_size-1,-1));
        return sol(1,cuts_size-2,cuts,dp);
    }
};
