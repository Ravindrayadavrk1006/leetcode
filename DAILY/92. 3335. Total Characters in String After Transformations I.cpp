class Solution {
private:
    /*

        explanation ->
            each char of given string s can go till s[i]-'a' + t 
            where s[i]-'a' is the value of a character will lie b/w 0-25
            at 26 it will break into two parts

               a
          26/     \26
           a        b
      26 /  \26   25/  \ 25
        a    b     a    b
        .    .     .    .
        .    .     .    .


        okey how it works 

        current char is b i.e 1    and t  = 52
        so  total will be 52+1

        0 -> a since 'a'-'a' = 0, b =  1 since 'b'-'a' = 1
        and we can start from 0 instead of position of a i.e 1 , since we have added it's position to t
        now     
            0, 53 -> it will take 26 and will be converted into a, b   so will become (0, 53-26),(1, 53-26) i.e 
            (0, 27), (1,27), now we will do recursively for (0,27) and (1, 27)
            (0, 27)->  (0, 1), (1, 1)  
            now for (1,27)-> (0, 2), (1,2) since 1 required only 25 to reach to 26 and divide into two parts


            same thing we are doing in the below recursive

    */
    int MOD = 1e9 +  7; 
    int recursive(int i, int curr_sum, vector<vector<int>>& dp){
        //if curr sum is less than 26-i  since if i =0 then we require 26 to break and if i = 1 we require 25 to break. for ex if i =1 and curr_sum = 25 so 25<25 false hence it will break into parts , take some examples to understand
        if(curr_sum < 26 - i)return 1;
        if(dp[i][curr_sum] != -1)return dp[i][curr_sum];
        //we are taking either 25 or 26 as per the value of i which could be 0,1  and going in both direction
        int left = recursive(0, curr_sum - (26-i), dp);
        int right = recursive(1, curr_sum - (26-i), dp);
        //counting total possibility
        return dp[i][curr_sum] = (left + right)%MOD;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(1e5+ 26, -1));

        //doing initial sum, i.e s[i] + t
        vector<int> initial_sum(n,0);
        for(int i=0; i<n; i++){
            initial_sum[i]+=(s[i]- 'a');
            initial_sum[i]+=t;
        }
        int total_sum =0;
        //now for reach s[i] we are running the recursion to find no of characters it will generate
        for(int i =0; i<n; i++){
            // cout<<s[i]<<" "<<initial_sum[i]<<" ";
            int rec_val = recursive(0,initial_sum[i], dp);
            // cout<<rec_val<<endl;
            total_sum = (total_sum + rec_val)%MOD;
        }
        return total_sum;
    }
};
