/*
  concept of DIGIT DP

  suppose we have to find all numbers between 0 to R, which satisfies some condition, let's say f(x) , this fx can be anything can be range of number, sum, atleast a digit k appears 4 times and so on


  1. we can't solve using using in O(n) i.e check for each nubmer since the R they give is in order of 10^18 which linearly can't be solved
  2. we can't use permutation and combination because that become very hard to solve and logic is very very almost impossible to build and lot lot of caveat and hence out of discussion
  3. we use a modified dynamic programming approac to solve it.


  approach of digit dp->
  suppose someone want's us to find nubmer beween  0 to  99 whose sum is 6
  there are 2 places at max to be filled ->
  
  _ _    , first position can be filled with any digit between 0-9 and
  suppose we set 0 on first position second position can be occupied with any digit 0-9
  suppose we set 1 on first position on first place and second position can be occupied with any digit 0-9.

  this way we can keep filling each possible digit on each position and keep addoing that digit to our curr_sum

  let's say
  first position we placed 1, second position we can place 0-9
  if we place 0 in second place sum will becom 1+0
  if 1 -> 1+1 = 2
  if 2 -> 1+2 = 3
  if 3 -> 1+3 = 4
    4 -> 1+4 
    5 -> 1+5  ---> this will satisfy our requirement
    7-> 


so approach we follow is we try to all positions with valid numbers
now let's say R is something like 53
then in first position we can go from 0-5 and when first position is 5 then in second position we can go from 0-3 only but if first position is 0-4 then in second position we can go anythign
from 0-9 

we will be using this logic to fill position,
for it we are using a variable called tight, if tight is true in the current position we can go from
0 to i'th index elmeent of R,

if we are given to find the elemement which satisfies given condition between L and R
then we can find element from which satisfies our condition from [0-L) not including L
and then find elmeent from [0-R] and and then we substruct first [0-L) result from  [0-R]

*/







#include <bits/stdc++.h>

class Solution {
private:
    //using DIGIT DP
    const int MOD = 1e9 + 7;

//this is the main function
    int digit_dp(int pos, int curr_sum, bool tight, string& num, int min_sum, int max_sum, vector<vector<vector<int>>>& dp){
      //if curr_sum become greater than 400 given in the constraint then we return 0
        if(curr_sum >400)return 0;
      //if pos == num.size() i.e length of num then total sum till now is according to the asked condition then we return 1 else 0
        if(pos == num.size()){
            if(curr_sum>= min_sum && curr_sum<= max_sum)return 1;
            return 0;
        };
        if(dp[pos][curr_sum][tight] != -1)return dp[pos][curr_sum][tight];
        //normal cases

        //if tight variable is true then we can go from 0 to R's pos element else we can go from 0-9
        int ub = tight ? num[pos] - '0': 9 ;
        int ans = 0;

        //at current position trying valid numbers which can placed at current position
        for(int digit = 0; digit<=ub; digit++){

            //addingt the current digit in curr_sum and then trying for next pos, also if current is tight and digit==ub i.e it's the last digit then set tight true else false
            ans+=digit_dp(pos+1, curr_sum+digit, (tight && digit == ub), num, min_sum, max_sum, dp);
            ans%= MOD;
        }
        return dp[pos][curr_sum][tight] =ans;
    }
    string decrement(string num) {
        if(num == "0")return num;
        int i = num.size() - 1;
        while (i >= 0 && num[i] == '0') {
            num[i] = '9';
            i--;
        }
        if (i >= 0) {
            num[i]--;
        }
        // Remove any leading zero
        if (num[0] == '0') {
            num = num.substr(1);
        }
        // If the number became empty (e.g., num was "0"), return "0" or "" as per your use case
        if (num.empty()) return "0";
        return num;
}

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        vector<vector<vector<int>>> dp(num1.length(), vector<vector<int>>(401, vector<int>(2, -1)));
        //from [0-L) , hence doing L-1
        string lower = decrement(num1);
        cout<<lower<<endl;
        //finding  answer for [0-L) 
        int first =  digit_dp(0, 0, 1, lower, min_sum, max_sum, dp);
        // Resetting the entire dp
         dp = vector<vector<vector<int>>>(num2.length(), vector<vector<int>>(401, vector<int>(2, -1)));
      //calling the second answer
        int second =  digit_dp(0, 0, 1, num2, min_sum, max_sum, dp);
        return (second-first+ MOD)%MOD;
    }
};
