/*
    here i am using recursive appraoch to solve the problem

    we have three options to choose from->
        from current position can take 1day pass, 7days, or 30 days pass and we have to find the minimum
        if we take 7days pass let's suppose on 3rd then it will be valid for 3,4,5,6,7,8,9 i.e days[pos]+6 where days[pos] = 3
    


    so in below code at current index(i.e pos variable used in the code) we are taking three possible type of passes and adding their costs and whichever is minimum
    now to which position i will go from current position in one day pass we can go to next day,
    for 7 days pass we have to go for pos where value is greater than days[pos]+6 and , for finding this position we are using binary search (for finding value greater than or equal to)


    fyi:
        above is the explanation of top-down approach, i.e starting from 0 and going towards last index
        
        in bottom up appoarch we are moving from last index towards 0 index and hence the position in three conditions are called accordingly also , in binary search instead of finding element greater than the current element we are finding the elemnet which is just smaller then that


*/


class Solution {
private:
    //for finding element just greater than the current element
    int find_greater_than(int day, vector<int>& days){
        int start = 0;
        int end = days.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(days[mid] <= day)start = mid+1;
            else end = mid-1;
        }
        return start;
    }
    int sol_recursive_top_down(int pos,vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(pos >= days.size())return 0;
        //normal try all three posibilities
        // int ans = INT_MAX;
        if(dp[pos] != -1)return dp[pos];
        int first = costs[0] + sol_recursive_top_down(pos+1, days, costs, dp);
        int el = find_greater_than(days[pos]+6, days );
        int second = costs[1] + sol_recursive_top_down(el, days, costs, dp);
        int el_30 = find_greater_than(days[pos]+29, days);
        int third = costs[2] + sol_recursive_top_down(el_30, days, costs, dp);
        return dp[pos] = min(first, min(second, third));

    }





    /*
            below code is bottom down approach and it is preffered appraoch
    */
    //for finding value just smaller than the currente elment
    int find_smaller_than(int day, vector<int>& days){
        int start = 0;
        int end = days.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(days[mid] >= day)end = mid-1;
            else start = mid+1;
        }
        return end;
    }
    //bottom up approach of dp, ie. from larger to smaller
    int sol_recursive_bottom_up(int pos,vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(pos < 0)return 0;
        //normal try all three posibilities
        // int ans = INT_MAX;
        if(dp[pos] != -1)return dp[pos];
        int first = costs[0] + sol_recursive_bottom_up(pos-1, days, costs, dp);
        int el = find_smaller_than(days[pos]-6, days );
        int second = costs[1] + sol_recursive_bottom_up(el, days, costs, dp);
        int el_30 = find_smaller_than(days[pos]-29, days);
        int third = costs[2] + sol_recursive_bottom_up(el_30, days, costs, dp);
        return dp[pos] = min(first, min(second, third));

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);

        //CALLING BOTTOM UP APPROACH
        // return sol_recursive_bottom_up(days.size()-1, days, costs, dp);

        //CALLING TOP DOWN APPROACH
        return sol_recursive_top_down(0, days, costs, dp);  
        
    }
};
