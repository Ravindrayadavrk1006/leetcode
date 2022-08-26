/* --------------SELF -----------------
    IDEA-> with initiating total_profit,least amount at which we buy the NEXT STOCK as lsf
    initial at prices[0]
    and the profit so far(psf) from the the point we bought the stock and current point where we are in the array
    we start from i=1 and the point where we find a lower prices then the current lsf we sell the stock with the psf added to total_profit else if the current profit which we get by prices[i]-lsf greater than psf then we update the psf
*/
class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
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
        
    }
};

/*----------------------------------------OTHER APPROACHES---------------------------
APPROACH 1 -->>GREEDY APPROACH
IF WE PLOT THE PRICES ON A GRAPH THEN WE WILL FIND THAT SOME SHAPE OF PRICES. THE RISING SLOP(ASENT) WILL BE PROFIT AND HENCE WE CAN ADD THAT PART TO THE TOTAL PROFIT
IMPORTANT POINT ->> A RISE WITH POINTS A-B-C-D    THE PROFIT WILL BE D minus A which can be written as B-A + C-B + D-C  
hence we can say that will be profit when the present point value-previous point value >0 we will add this to the total profit 
TC- O(N)
    

*/
