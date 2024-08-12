coding ninjas
problem link ---> https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0

--------------------   RECURSIVE AND DP APPROACH  --------------------
#include <bits/stdc++.h> 
using namespace std;
int sol_rec(int pos , int st,vector<int>& arr,vector<vector<int>>& dp)
{
    if(st==1)
    {
        int sum = 0;
        for(int i = pos; i<arr.size();i++)sum+=arr[i];
        return sum;
    }
    if(dp[pos][st] != -1)return dp[pos][st];
    //normal cases
    int g_min = INT_MAX;
    int first = 0;
    for(int i =pos; i<=arr.size()-st; i++)
    {
        first = first+arr[i];
        int second = sol_rec(i+1,st-1,arr,dp);
        g_min = min(g_min,max(first,second));
    }
    return dp[pos][st] = g_min;
}
/*
  binary seach approach explained well in notebook of cp 
  

*/
//binary search approach


bool _allocation_possible(vector<int>& arr, int mid, int st )
{
    int temp_st = 0;
    int pages = 0;
    for(int i =0;i<arr.size(); i++)
    {
        //since a entire book has to be atleast allocated to a person
        if(arr[i]+pages > mid)
        {
            pages = arr[i];
            temp_st++;
            if(pages>mid)return false;
        }
        else
        {
            pages+=arr[i];
        }
        
    }
    if(temp_st<st)return true;
    return false;
}
int BS(vector<int>& arr, int n, int st)
{
    //defining the search space
    int left = INT_MAX;
    int right = 0;
    for(int i = 0;i<n; i++)
    {
        left = min(left,arr[i]);
        right = right+arr[i];
    }
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(_allocation_possible(arr,mid,st))
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return left;
}


int allocateBooks(vector<int> arr, int n, int m) {
  
  //callling recursion approach 
//     vector<vector<int>> dp(arr.size(),vector<int>(m+1,-1));
//     return sol_rec(0,m,arr,dp);
  
  
  //binary search approach--->
//SOLUTION 1
    // vector<vector<int>> dp(arr.size(),vector<int>(m+1,-1));
    // return sol_rec(0,m,arr,dp);

    //SOLUTION 2
    return BS(arr,n,m);
}





//---------------------------------- in GFG ------------------
//PROBLEM LINK-> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution {
  private:
    bool _can_be_allocated(int n, int arr[], int m, int mid){
        int pages = 0;
        int curr_st = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(pages + arr[i] > mid ){
                pages = arr[i];
                curr_st++;
                if(arr[i]>mid)return false;
            }
            else{
                pages+=arr[i];
            }
        }
        //since count of students is starting from 0 ,if m number of students can be allocated properly then fine else not
        if(curr_st < m)return true;
        return false;
    }
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        int low = INT_MAX;
        int high = 0;
        for(int i = 0 ; i<n; i++){
            if(arr[i]<low)low = arr[i];
            high+=arr[i];
        }
        if(m>n)return -1;
        // cout<<"low"<<low<<" high"<<high<<endl;
        //working on logic 
        int ans = INT_MAX;
        while(low<=high){
            // cout<<"low"<<low<<" high"<<high<<endl;
            int mid = (low+high)/2;
            //if this much value can be allocated let's try for lower value
            if(_can_be_allocated(n,arr, m, mid)){
                // cout<<"can be allocated"<<mid<<endl;
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        // cout<<"mid"<<ans<<" high"<<high<< " low"<<low<<endl;
        return low;
    }
};
