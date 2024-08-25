/*
Intuition
simple using recursion to go to( let current index)inleft = i-arr[i] and in right = i+arr[i] and we return right logical OR left . since we get true for any we return true else we return false.

Approach
caviats --> start >= arr.size() , start < 0 and if we got stuck in a loop for handling the loop condition we go in left and when we go in right we tell to visited array that hey now I am going to right and and after it this index will be completely traversed and anyone after me should not come to visit this position to PREVENT ITSELF FROM BEING STUCK IN LOOP.

simpley using dp for preventing the repetative solution

Complexity
Time complexity:
O(n)

Space complexity:
O(n)
*/

class Solution {
public:
   bool help(int start, vector<int>& arr, vector<int>& dp, vector<bool>& visited)
    {
      // next two statement are used to prevent simple base condition of peeping outside of the arr  
        if (start >= arr.size()) return false;
        if(start < 0 )return false;
        if(arr[start] == 0)return true;
        if(dp[start] != -1)return dp[start];
        bool left,right;
        if(!visited[start])
        {
            left = help(start - arr[start], arr, dp, visited);
        }
        if(!visited[start])
        {
           //here the visited is made true saying i am going to visit the right side too now after me anyone coming in this path at this start position should not traverse it
           //since you will be stuck in loop
            visited[start]= true;
            right = help(start + arr[start], arr, dp, visited);
        }
        //making visited as false so that in other part it won't affect--> just simple backtracking the dirt we created
        visited[start]= false;
        return dp[start] = left || right;
    }
    bool canReach(vector<int>& arr, int start) {
    //visited will be used to prevent the loops
        vector<bool> visited(arr.size(),false);
        //it is used to prevent from visiting the visited node and preventing re-doing of already done stuff
        vector<int> dp(arr.size()+1,-1);
        bool a=help(start , arr, dp, visited);
        return a;
    }
};
