problem link ---> CODING NINJA --> https://www.codingninjas.com/codestudio/problems/ninja-and-ladoos_1112629?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;
/*
approach finding the median of two sorted arrays leetcode question

*/
int sol(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    if(m>n)return sol(row2,row1,n,m,k);
    int left = 0;
    int right = 0;
    //few edge cases handling 
    /*
        //suppose k = 3  and m = 5 and n = 2
        we can take max of 3 elements from left and min of zero,
        hence right = min(m,k)   //right is the starting of binary search high

        //suppose k =6  m = 4 , n = 4
        max element we can take from left = 4 all four of them and 2 from right
        min element we have to take from left we can't take 0 since second array has just 4 element which is less than 6
        hence minimum elemnt we can take  is 2 hence
        left = max(0,k-n)   //left is low of starting binary search
    */

    left = max(0,k-n);
    right = min(m,k);
    while(left<=right)
    {
        int cut1 = (left+right)/2;
        int cut2 = k-cut1;

        ///finding the elements of cut array
        int left1 = cut1==0?INT_MIN:row1[cut1-1];
        int left2 = cut2 == 0?INT_MIN:row2[cut2-1];

        //finding the rights
        int right1 = cut1==m?INT_MAX:row1[cut1];
        int right2 = cut2 ==n?INT_MAX:row2[cut2];

        if(left1<=right2 && left2<=right1)
        {
            return max(left1,left2);
        }
        else if(left1>right2)
        {
            right = cut1-1;
        }
        else{
            left = cut1+1;
        }
    }
    return 0;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    if(k==n+m)return max(row1[m-1],row2[n-1]);
    return sol(row1,row2,m,n,k);
















    
}
