/*


**************READ THE DP NOTES FROM ALGORITHM GATE NOTEBOOK , ADDED AT LAST OF NOTEBOOK
1.  DP is basic recursion with an extra part of storing the result in a array and , and if for current recursion call we check if value already exists  if it does then we use that which is O(1)
instead of calling the recursion again to find the already existing value.
2. we need to always draw the recursion graph , since then we will see the overlapping part and DP help us not computing the already computed overlapping part
3. we can see in the below fibbonaci code we just have to add two extra line of code in all recursion and we have the DP solution for it line 1 and line 2, 
4. in below code t.c complexity reduced from 2^n to O(n) , just extra space will be required O(n). here we have to use O(n) recursion stack space

[****important****]
5. in DP it is very important to find for bigger values using smaller values i mean to say we must find for n using smaller values , writing funtion to find for n , 
so that smaller are done first and we can use those values when they repeat since we already will have those values stored
*/

//this below is recursion approach in which we start from n and goes to base case and then again come back to the answer.
//RECURSION APPROACH ->
1...
//simple fibonachi DP implementation
int recursive_dp(int n, vector<int>& dp){
    if(n<=1)return n;
  // this is the line added because of DP ------> line 1 added for dp
    if(dp[n] != -1)return dp[n];
  //[**additional for DP] storing in the dp array before returning  -------> line 2 added for dp
    return dp[n] = recursive_dp(n-1,dp) + recursive_dp(n-2,dp);
}
int main() {
    int n = 6;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
    return 0;
}

/*
first recursion will be written and then using the recursion we will write the logic for tabulation it will become easier

*/

2..
//TABULATION APPROACH

/*
  understand how the things are happening we will have base case i.e value of dp[0] and dp[1]
  so what we can do is we can start fromt here and go the final answer without using the recursion

  **[important] -> here important thing is that we realize the logic how the data is flowing in above recursion case 


  **tabulation dp doesn't recursion recursion stack space
*/
int tabulation(int n,vector<int>& dp){
    dp[0] = 0;
    dp[1] =1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}



/*
3..  [***IT IS NOT REQUIRED FOR DP LEARNING BUT JUST SIMPLE LOGIC]

/*
  optimizing the above solution to remove the space complexity or the vector itself , since we require only previous two values for finding the current values so we can use two variable and be doing it
*/

//remove the stack space
int remove_sc(int n){
    //storing value of fib 0 in prev2 and storing value of fib1 in prev
    int prev2 = 0;
    int prev = 1;
    for(int i = 2; i<=n; i++){
        int curr = prev2+prev;
        
        //in below two lines preparing data for next iteration
        //storing prev value in prev2
        prev2 = prev;
        //storing the current value in prev2
        prev = curr;
    }
    return prev;
}

*/
