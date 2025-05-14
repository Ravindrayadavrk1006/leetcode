class Solution {
private:
    int MOD = 1e9 + 7; 

    //BASIC Approach giving TLE
    /*
        explanation : we are using DP to solve it
        we are going from current position eg. 

           5 -> 6 and we move one step therefore remSteps-=1;
           while moving 5 will go to positions as described in the numbs if nums = 2
           5 -> 6,7 and hence doing the same
    
    */
    int solLengthAfterTransformations(int pos, int remSteps, vector<int>& nums, vector<vector<int>>& dp){
        if(remSteps == 0)return 1;

        //cases
        if(dp[pos][remSteps] != -1)return dp[pos][remSteps];
        int curr_count = 0;
        for(int i=1; i<=nums[pos]; i++){
            curr_count = (curr_count+ solLengthAfterTransformations((pos+i)%26, remSteps -1, nums, dp)) %MOD;
        }
        return dp[pos][remSteps] = curr_count;
    }


    //SOL 2 working solution
    /*
        approach is same as defined in the editorial and in the video ,
        https://www.youtube.com/watch?v=A9drIyqAaDI


        //intuition 
        if nums given as [1,2,3,1]
        read the definition of M matrix defined below -> def1.
        so it is saying that if we have  abcd  as s we will get  bcddbaa -> size 7
        let's say if we have aabccd  we will get cddbaaacdbb -> size 10

        we can keep the count of each character in a array [1 1 1 1] for abcd  now if we multiply [1 1 1 1] with the M we will get the matrix whose whose element will sum will be sum 7
        eg let's take [1,1,1,1] in column format

        1         0 0 1 1       1
        1         1 0 1 0    =  2
        1    *    0 1 0 0       3
        1         0 1 1 0       1
                               [sum = 7]

        this is for one transformation if we have to again do the transformation then 
        1          0 0 1 1       1
        2          1 0 1 0    =  4
        3     *    0 1 0 0       9
        1          0 1 1 0       1

        now formula ->  c1 = C0 * M
                        c2 = c1 * M
                        c3 = c2* M
                        ==> now if we do the subsitution
                        c3 = c1*M * M = C0 * M* M* M  = C0* (M)^3 hence we have the formula
                        we calculate M^3 using binary subistion or big power finding 

                        i.e our formula become  count * M^t    where count is the intial count of character in the given string, M is the matrix and t is the transformations

    


        //def1. DEFINITION OF MATRIX M 
        approach we will have matrix M of size 26*26 which shows a character transform to which characters
                              a b c d
        eg. if nums given as [1,2,3,1]
        we are saying a transforms to b, b transforms to c and d, c transforms to c and d and e, d transforms to e
        if we assume our dictionary has 4 alphabets instead of 26 we can write 

            a b c d
        a   0 0 1 1
        b   1 0 1 0
        c   0 1 0 0
        d   0 1 1 0
        the rounding also happens like c becomes -> d, a, b
        the columns names are the term which will transform and on left side names to which character they will transform to
        eg. a will transform to b, b will transform to c,d        c -> d,a,b 
    */

    vector<vector<long long>>matrix_multiply(vector<vector<long long>>& a, vector<vector<long long>>& b){
        int n = a.size();

        //response matrix
        vector<vector<long long>> res(n,vector<long long>(n, 0));
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    res[i][j] = (res[i][j] + (a[i][k]* b[k][j]) ) %MOD;
                }
            }
        }
        return res;
    }

    //using binary exponentiation for multiplication
    //when it's odd we multiply it with 
    vector<vector<long long>> matrix_power(vector<vector<long long>>& M, int power){
        int n = M.size();
        //forming unit matrix of size 26*26
        vector<vector<long long>> res(n, vector<long long>(n, 0));

        //devising a unit matrix for storing the data
        for(int i =0; i<n; i++){
            res[i][i] = 1;
        }
        while(power> 0){
            //if power is a odd number
            if(power &1){
                res = matrix_multiply(res, M);
            }
            M = matrix_multiply(M, M);

            //half the value of power
            power/=2;
        }

        return res;

    }

    //CORE caller
    int sol_2(string s, int t, vector<int>& nums){
        int n = s.size();
        //count occurances of each characters
        vector<int> count(26,0);
        for(int i =0; i<n; i++)count[s[i]-'a']++;

        //let's form the matrix M
        vector<vector<long long>> M(26, vector<long long>(26,0));

        for(int j =0; j <26; j++){
            int transformTo = nums[j];
            for(int i=1; i<=transformTo; i++){
                int nextChar = (j + i) % 26;
                //increment it
                M[nextChar][j]++; 
            }
        }

        //now let's find M^t
        vector<vector<long long>> resMatrix = matrix_power(M, t);

        vector<long long> ans(26,0);
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                ans[i] = (ans[i] + resMatrix[i][j]* count[j])%MOD;
            }
        }
        long long total = 0;
        for(auto el: ans){
            total = (total + el)%MOD;
        }
        return total;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

        //SOL1
        /*
        int ans = 0;
        int n = s.size();
        vector<vector<int>> dp(26, vector<int>(t +1 , -1));
        for(int i = 0; i<n; i++ ){
            ans = (ans + solLengthAfterTransformations(s[i] - 'a', t, nums, dp)) %MOD;
        }
        return ans;
        */


        return sol_2(s,t, nums);
    }
};
