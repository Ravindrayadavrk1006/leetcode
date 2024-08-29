#include <bits/stdc++.h>
QUESTION LINK -> https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
/*
    always try to write recursion because we know recursive dp is nothing but recursion with two extra line

    here we are trying all the ways possible and returing the maximum out of all the ways
    


    explanation of approach ->
        we are starting from n-1 and prev_task = 3 since we are assuming non task is done before,
        we are trying to try all the ways except if prev_task since we can't go vertically as told in the question
*/

int recursive_dp(int day, int prev_task,vector<vector<int>> &points,vector<vector<int>>& dp){
        if (day < 0 )return 0;
        //normal cases
        if(dp[day][prev_task] != -1)return dp[day][prev_task];
        int max_i = INT_MIN;
        for(int i = 0; i<=2; i++){
            if(i != prev_task){
                int curr_point = points[day][i] + recursive_dp(day-1, i,points,dp);
                max_i = max(max_i, curr_point); 
            } 
        }
        return dp[day][prev_task] = max_i;
}

/*
    follow the procedure given in dp notes how to convert recursive in tabulation
    we are just writing the variables of recursive funtion as loops and internal everyting will be same

*/
int tabulation_dp(int n , vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int max_i = INT_MIN;

    //more than one row and normal code
    /*writing the base cases here we at looking the recursive approach we saw if we are coming for f(0,0) it means we we will take max of (0,1) and (0,2)
        similarly when coming for f(0,1) we will take max of (0,0) and (0,2) 
        and similary when coming for f(0,2) we will return max of (0,0) and (0,1) index
        doing same when writing the below base conditions since tabulation is bottom up approach
    
    */
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));
    //below two for loops are for function call
    for(int day = 1; day<n; day++){
        for(int prev_task=0; prev_task<4; prev_task++){

            //now copy exactly everyting what's done inside the recursion and just change the function call with dp value

            dp[day][prev_task] = 0;
            for(int i = 0; i<=2; i++){
                if(i != prev_task){
                    int curr_point = points[day][i] + dp[day-1][i];
                    dp[day][prev_task] = max(dp[day][prev_task], curr_point); 
                } 
            }
            }
    }

    //this is exactly same as what we call recursive function with i.e last fuction to be executed in top down approach
    return dp[n-1][3];

}

int space_optimized(int n, vector<vector<int>> &points){
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][1],max(points[0][2],points[0][0]));


    /*
        using the same code as in tabulation dp , just changing where storage is happeing
    */
    for(int day = 1; day<n; day++){
        vector<int> temp(4,0);
        for(int prev_task=0; prev_task<4; prev_task++){
            //now copy exactly everyting what's done inside the recursion and just change the function call with dp value

            temp[prev_task] = 0;
            for(int i = 0; i<=2; i++){
                if(i != prev_task){
                    int curr_point = points[day][i] + prev[i];
                    temp[prev_task] = max(temp[prev_task], curr_point); 
                } 
            }
        }
        prev = temp;

    }

    //this is exactly same as what we call recursive function with i.e last fuction to be executed in top down approach
    return prev[3];

}
int ninjaTraining(int n, vector<vector<int>> &points)
{   /*
        from the notes we found out that dp array will be same size as number of changing variables in the dp 
        we have two variables in array day and prev_task and hence we will keep a array of that size
        max of days = n 
        max of prev_task = 3 hence we will create vector of size n*3
*/

    //BELOW 3 LINES FOR CALLING RECURSIVE DP
    // vector<vector<int>> dp(n, vector<int>(3+1,-1));
    //initially the prev_task is 3 since none task is done so it will never class with any of 0 to 2 tasks
    // return recursive_dp(n-1, 3, points, dp);



    //2. CALLING TABULATION OR MEMOIZATION  DP
    // return tabulation_dp(n, points);


    //3. calling space optimization
    return space_optimized(n, points);
}
