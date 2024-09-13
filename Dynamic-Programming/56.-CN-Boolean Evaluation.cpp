problem link https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?leftPanelTab=0

problem link https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?leftPanelTab=0
#include <bits/stdc++.h> 
using namespace std;
long long  mod = 1000000007;
//THE problem is a modification of Matrix Chain Multiplication
//TYPE partition DP
//FindTrue variable is used to determine that whether
//we are finding the count of True or False rn
int sol(int i , int j, bool findTrue,string & exp,vector<vector<vector<long long>>> & dp)
{
    if(i>j)return 0;
    //base case
    //if i == j i.e just T or F remaining
    if(i==j)
    {
        if(findTrue)return exp[i]=='T';
        else return exp[i]=='F';
    }

    //normal cases
    /*
        eg. exp = T|T&F^T
        the idea here is we divide the string into parts from the position 
        of operands into parts and try to find various no of evaluation of 
        expression as True
        we will divide like (T)(T&F^T) , (T|T)(F^T) , (T|T&F)(T)
        here we figure that we can divide the expression into parts at operands
        and operands are present at interval of +2 and start from i+1
        hence we will use MCM for loop with interval of +2 and starting at i+1


        counting trues and false
        when the operand 
        1. & --> only T&T = T this implies we have to find all the 
        ways in which the left expression can give true and all ways in which the right 
        expression can give true and multiply 
        2. |    T*F ,F*T , T*T gives true hence we find the ways in which the left,
        right expressions can be true and false and multiply as 
        leftfalse*righttrue , leftture*rightfalse, leftture*righttrue to count the no of trues
        3.^       only T*F and F*T is true hence we find 
        counts of leftfalse*righttrue , leftture*rightfalse to make true
        
    */

    //total count to return 
    if(dp[i][j][findTrue] != -1)return dp[i][j][findTrue];
    long long  times = 0;
    for(int index= i+1 ;index<=j-1; index+=2)
    {
        //finding count of true in left parition
        long long  leftT = sol(i,index-1,1,exp,dp);
        //finding count of false in left parition
        long long leftF = sol(i,index-1,0,exp,dp);
        //finding count of true in left parition
        long long rightT = sol(index+1,j,1,exp,dp);
        //finding count of false in left parition
        long long rightF = sol(index+1,j,0,exp,dp);
        if(exp[index] == '&')
        {
             
            //if we are to find noofTtrue i.e findTrue = 1
            if(findTrue)
            {
               times= (times + (leftT*rightT)%mod)%mod;
            }
            else
            {
                times= (times + (leftT*rightF)%mod)%mod;
                times=(times+ (leftF*rightT)%mod)%mod;
                times= (times + (leftF*rightF)%mod)%mod;
            }
        }
        else if(exp[index] == '|')
        {
             
            //if we are to find noofTtrue i.e findTrue = 1
            if(findTrue)
            {
               times= (times + (leftT*rightT)%mod)%mod;
               times= (times + (leftT*rightF)%mod)%mod;
                times=(times+ (leftF*rightT)%mod)%mod;

            }
            else
            {
                
                times= (times + (leftF*rightF)%mod)%mod;
            }
        }
        else
        {
             
            //if we are to find noofTtrue i.e findTrue = 1
            if(findTrue)
            {
               times= (times + (leftT*rightF)%mod)%mod;
                times=(times+ (leftF*rightT)%mod)%mod;

            }
            else
            {
                
                times= (times + (leftF*rightF)%mod)%mod;
                times= (times + (leftT*rightT)%mod)%mod;
            }
        }
    }
    return dp[i][j][findTrue] = times%mod;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    //since three vars hence 3d DP
    vector<vector<vector<long long >>> dp(n,vector<vector<long long >>(n,vector<long long>(2,-1)));
    return sol(0,n-1,1,exp,dp);
    // Write your code here.
}
