/*
  basic approach of take and non-take recursion
  see where the range of values is from -ve to +ve is managed in index, eg. -1e4 to 1e4 for it we have created index from 0 to 2*1e4

*/
class Solution {
private:
    //APPROACH 1
    int recursive_sol(int i,int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        //base case
        if(i == nums.size())return 0;
        
        //normal cases
        //since have to find the subsequence hence will take the approach of take not take
        if(dp[i][prev+10001] != -1)return dp[i][prev+10001];
        //NOT TAKE
        //since we aren't taking hence no condition check
        //we will move on the next element and prev will remain same since not taken current element and since not taken will contirbute 0 in the subsequence lenght increase
        int not_take = 0 + recursive_sol(i+1,prev,nums,dp);

        //TAKE
        
        //since there is a condition check when we go for take path hence we have initialized with 0 contribution initially
        int take = 0;
        if(nums[i]> prev) take = 1 + recursive_sol(i+1,nums[i],nums,dp);
        return dp[i][prev+10001] = max(not_take,take);
    }

    //APPROACH 2
    //HERE INSTEAD OF KEEPING A TRACK OF PREVIOUS VALUE WE WILL TRY TO KEEP A TRACK OF PREVIOUS INDEX
    //VERY SIMILAR CODE TO ABOVE
    int approach_previous_index(int i,int prev_index, vector<int>& nums, vector<vector<int>>& dp)
    {
        //base case
        if(i == nums.size())return 0;
        
        //normal cases
        if(dp[i][prev_index+1] != -1)return dp[i][prev_index+1];
        //NOT TAKE
        int not_take = 0 + approach_previous_index(i+1,prev_index,nums,dp);

        //TAKE

        int take = 0;
        //if prev_index == -1 it means we have not taken any element yet hence we can take the current element or we can take the current element if nums[current_index i.e. i ]> nums[prev_index]
        if(prev_index==-1 || nums[i]> nums[prev_index]) take = 1 + approach_previous_index(i+1,i,nums,dp);
        return  dp[i][prev_index+1] = max(not_take,take);
    }
    //APPROACH 2 TABLUATION 
    //important to note here that since we did a index shift and now prev_index in real is prev_index+1 and hence wherever refering to dp for getting the values we will ask for prev_index+1 in earlier it was handled by function call and asked at this point if(dp[i][prev_index+1] != -1)return dp[i][prev_index+1];
    int tabulation(vector<int>& nums)
    {
        int n = nums.size();
        //initialize with 0 since we will fill every cell hence no need of -1 and since nth row we need all 0 hence better to initialize with 0
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i =n-1 ; i>=0 ; i--)
        {
            for(int prev_index = n-1; prev_index>=-1 ; prev_index--)
            {
                //in our dp prev_index is represented by prev_index +1 hence doing the same
                int not_take = 0 + dp[i+1][prev_index+1];
                int take = 0;
                if(prev_index==-1 || nums[i]> nums[prev_index]) take = 1 + dp[i+1][i+1];
                dp[i][prev_index+1] = max(not_take,take);    
            }
        }
        return dp[0][0];
    }
    int space_optimized(vector<int>& nums)
    {
        int n = nums.size();
        //initialize with 0 since we will fill every cell hence no need of -1 and since nth row we need all 0 hence better to initialize with 0
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        //and we know  from approach 2 tabulation dp[i+1] means prev
        for(int i =n-1 ; i>=0 ; i--)
        {
            for(int prev_index = n-1; prev_index>=-1 ; prev_index--)
            {
                //in our dp prev_index is represented by prev_index +1 hence doing the same
                int not_take = 0 + prev[prev_index+1];
                int take = 0;
                if(prev_index==-1 || nums[i]> nums[prev_index]) take = 1 + prev[i+1];
                curr[prev_index+1] = max(not_take,take);    
            }
            prev = curr;
        }
        return prev[-1+1];
    }

    //approach 3 non dp solution 
    //here we are taking a different approach trying to find all the subsets sizes possible for a element
    /*
                            5 4 11 1 16 8 
    no. of elmnts for lis   1 1  1  1 1 1 intitally all will have 1
    we will try to ask for each elements all it's previous if they can contribute in that elements lis
    eg . for 4 we ask 5 if it is smaller than 4 says no hence lis remains 1
    for 11 we ask 5 it is smaller than 11 hence lis becomes 2(1(initial value)+1),
    we ask for 4 if can contribute it says yes will become 1+1 hence we already 2 for 11 won't include it i.e we try to have the max.
    hence the lis for 11 becomes 2 from 1 we update the initial lis for 11 and we keep on doing so for all the elments and whoever have max lis we print that
    */
    int most_optimized(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> lis(n,1);
        int max_final_lis = 1;
        for(int i = 0 ; i<n; i++)
        {
            //asking all the previous elemnts to it 
            for(int j= 0; j<i; j++)
            {
                //i.e the current element is greater to the previous element we asking if it could contirubte in lis
                if(nums[j]<nums[i])
                {
                    //comparing between including the (previous and current element) and current_lis 
                    lis[i] = max(lis[j]+1, lis[i]);
                    max_final_lis = max(max_final_lis,lis[i]);
                }
            }
        }
        return max_final_lis;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {

        //APPROACH 1 CALL
        //in dp since the min value acc. to constraints is -10001 hence we are making it positive by making a shift of +10001 so that -10001 is represented by -10001+10001 = 0 and hence our values will go upto 20002
        // vector<vector<int>> dp(nums.size(), vector<int>(20002,-1));
        // return recursive_sol(0,-10001,nums,dp);


        //APPROACH 2 CALL
        // int n = nums.size();
        //since we have taken -1 as index hence we have to do shifting of index
        //since shifting of index won't change the cod but will change only the places of representation in the dp hence using the same trick in approach_previous_index
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        // return approach_previous_index(0,-1,nums,dp);

        //APPROACH 2 TABLUATION 
        //return tabulation(nums);


        //APPROACH 2 space_optimized
        // return space_optimized(nums);

        return most_optimized(nums);
    }
};
