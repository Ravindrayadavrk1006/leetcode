/* --------------SELF -----------------
    IDEA-> with initiating total_profit,least amount at which we buy the NEXT STOCK as lsf
    initial at prices[0]
    and the profit so far(psf) from the the point we bought the stock and current point where we are in the array
    we start from i=1 and the point where we find a lower prices then the current lsf we sell the stock with the psf added to total_profit else if the current profit which we get by prices[i]-lsf greater than psf then we update the psf
*/
class Solution {
    
private:
    

    //SOLUTION 2 PART 1 
    //NORMAL RECURSIVE SOL T.C = 2*N SINCE MIN TWO RECRISVE CALL ON A PARTICULAR DAY 
   //DP solution time complextiy O(2*n = N) ,space complexity = n*2 + n(stack space) 
    int recursive_sol(int day , bool buy , vector<int>& prices, vector<vector<int>>& dp)
    {
        /*
            we will try to go through all the possibilities using recursion 
            at a day we can either sell or buy the stock so trying to explore all the posibilities . since it is said that we can't continuously keep selling or keep buying so we will keep a boolean  variable 'buy' to denote if we are to buy or sell today
            approach --> on a day we can either buy , not buy , sell, not sell  since we might skip to buy on another day or we might decide to sell on another day
            profit => sell - buy or we can write as +sell + -buy  
        
        */

        //base cases
        //if we have explored all the possibilites on all the days then return 0 after exploring all days
        if(day == prices.size())return 0;


        //checking if already solved
        if(dp[day][buy] != -1 )return dp[day][buy];
        //normal cases
        //if buy var value is 1 we will buy on that day or we don't buy and decide to buy on another day
        
        if(buy)
        {
        //since we buyed today we won't buy next day
        int buy_today =  -prices[day] + recursive_sol(day+1,0,prices, dp);
        //we didn't buy today and we have possibility to buy another day
        int not_buy_today = 0 + recursive_sol(day+1,1,prices, dp);
        return dp[day][buy] = max(buy_today,not_buy_today);
        }
        //if we don't buy then we can sell today
        else
        {
            //if we sell today we can buy next or further day this below recursion will send the call to above buy if 
            int sell_today = prices[day] + recursive_sol(day+1,1,prices, dp);
            int not_sell_today = 0 + recursive_sol(day+1,0,prices,dp);
            return dp[day][buy] =  max(sell_today,not_sell_today);
        }
        
    }
    //since tabulation covers all the possibilities hence doing the same
    /*
     considering dp[i][0] since 0 is sell as sell day and hence copying from above the logic of sell
     similarly for dp[i][1] since 1 is buy hence copying the copy logic from above

    T.C -> O(n*2 = n)
    S.C -> O(n*2 = n  the stack space is eliminated since recursion eliminated)
    */
    int tabulation(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));\
        for(int i = n-1; i>=0; i--)
        {
            //on this day  if sell
            dp[i][0] = max(prices[i] + dp[i+1][1], 0 +dp[i+1][0]);
            //on this if buy
            dp[i][1]= max(-prices[i] + dp[i+1][0] , 0+ dp[i+1][1]);
        }
        return dp[0][1];
    }   
    //converting the above tabulation solution to space optimized one by getting the hint since only the previous row is being used all the time
    int space_optimization(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> prev(2,0);
        vector<int> curr(2,0);
         for(int i = n-1; i>=0; i--)
        {
            //on this day  if sell
            curr[0] = max(prices[i] + prev[1], 0 +prev[0]);
            //on this if buy
            curr[1]= max(-prices[i] + prev[0] , 0+ prev[1]);
            prev = curr;
        }
        return prev[1];
    }
    
public:
    int maxProfit(vector<int>& prices) {


        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return recursive_sol(0,1,prices,dp);
        
        //DP TABULATION CALL
        // return tabulation(prices);

        //DP space optimized
        return space_optimization(prices);





        //SOLUTION 1
        /*
        if(prices.size()<2)return 0;
        int total_profit=0;
        int lsf=prices[0];  //least so far =lsf
        int psf=0;  //profit so far =psf
        int length_vector=prices.size();
        for(int i=1;i<length_vector;i++)
        {
            int cp = prices[i]-lsf;  //current profit =cp
            if(cp>psf)
            {
                psf=cp;
            }
            else if(cp<psf)
            {
                total_profit+=psf;
                psf=0;
                lsf=prices[i];
            }
        }
        return total_profit+psf;
        */
    }
};


/*----------------------------------------OTHER APPROACHES---------------------------
APPROACH 1 -->>GREEDY APPROACH
IF WE PLOT THE PRICES ON A GRAPH THEN WE WILL FIND THAT SOME SHAPE OF PRICES. THE RISING SLOP(ASENT) WILL BE PROFIT AND HENCE WE CAN ADD THAT PART TO THE TOTAL PROFIT
IMPORTANT POINT ->> A RISE WITH POINTS A-B-C-D    THE PROFIT WILL BE D minus A which can be written as B-A + C-B + D-C  
hence we can say that will be profit when the present point value-previous point value >0 we will add this to the total profit 
TC- O(N)
    

*/
