#include<bits/stdc++.h>
using namespace std;
/*
APPROACH 1:
    WE PUT THE ENTIRE VALUES IN A ARRAY AND SORT IT IN M*NLOG(M*N) T.C 
    we then return n*m/2th index element that will be our median element

APPROACH 2:
    we uses binary search for finding out the element
    approach -->
    we try to do binary search for the count of element
    eg. elements since interger will be between 1 to 1e9
    but let's take for simplicity 
    1 to 100 as given in example 1
    we find mid 1+100 /2  = 50
    we find count of element which are smaller or equal to 50
    we find 23 elements smaller than 50 
    since 23 is larger than n*m/2  i.e ideally how many elements should be on one side
    so we move the right to mid-1
    i.e search space becomes 1 - 49
    we find mid 1+49/2 = 25
    we find count of element smaller or equal to 25
    we find 22 element which is much larger than n*m/2 hence we shift right
    to mid -1
    search space 1 to 24
    mid now -> 1+24 /2 = 12
    count of number smaller than or equal to 12
    15 elements smaller than 12 
    which is greater than n*m/2 i.e 12
    hence mid moved to mid -1 = 11
    seach space 1 - 11
    mid = 6
    elements smaller or equal to 6-> 8 elements are smaller than 12
    but since 8 is smaller than 12 hence we move left to mid+1
    search space 7 - 11
    mid -> 9
    counts of elements smaller or equal to 9-> 12 we move the left to mid+1
    i.e 10 
    search space 10,11
    now on left 13 elements greater than 12 ie n*m/2 hence let's move right to mid-1
    i.e search space becomes 10,10
    now till 10 13 elements so we move right to mid -1 
    since left becomes larger than right we return left 


    ---for finding the number of elements smaller or equal to a given number
    we use upper_bound logic to count's 
    we execute upper bound logic in every row to find the elemnts

*/
int countequalorlessthan(vector<int>&row, int element)
{
    //implementing upper_bound logic
    int left = 0;
    int right = row.size()-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(row[mid]<=element)left=mid+1;
        else right = mid-1;
    }
    return left;
}
int sol(vector<vector<int>> &matrix, int m, int n)
{
    //row -> m col->n
    int left = 1;
    int right = 1e9;  //let's assume the search space is entire interger array will take very few iteraton to comes to required but if went into the 
    //matrix and find out max for keeping right it would take O(n*m) for finding max
    int ideal_el_count_in_one_side = m*n/2;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int el_count = 0;
        for(int i = 0 ; i<m ; i++)
        {
            el_count+=countequalorlessthan(matrix[i],mid);
        }
        if(el_count <= ideal_el_count_in_one_side)left = mid+1;
        else right = mid-1;
    }
    return left;
}
int findMedian(vector<vector<int>> &matrix, int m, int n)
{
    return sol(matrix,m,n);
}
