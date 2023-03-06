problem :    https://www.codingninjas.com/codestudio/problems/count-inversions_615



#include <bits/stdc++.h> 
using namespace std;
/*
APPROACH 1:
    eg 3 2 1 
    if we count the inversion for 3 we will run a for loop for thee and found 
    all the elements which are in left of 3 and are smaller we get 2
    similarly we do for 2 we get 1 and similary for 1 which is 0 
    we add all and return
    T.C --> O(n*2)

APPROACH 2:
    eg 3 2 1 
    we start from right most element i.e last of array
    logic is since the element which is next smaller and present
    to the current element have already counted it's inversions and the inversion
    of current element will be the first smaller element to right of it +1

    explanation:
        for 1 no_of_inversion = 0;
        for 2-> 1 is the first smaller element to right of 2 we take it inversions
        and add 1 to it hence inversion for 2 -> 0+1 = 1
        for 3-> we find first smaller element to right of it and add one to it's inversion
        inversion for 3 -> 1+1 = 2
        total inversion = > 2+1 = 3
    slightly better solution than the previous one

APPROACH 3-->
  
    we will be using the MERGE SORT APPROACH 
    merge sort uses the technique of divide and conquer 
    so in our case we will normally divide our array
    and while merging 
    suppose 
    we have two arrays as
    [2 3 ]     [1]
    i ptr in first array and j ptr in second array
    i =0 ; j = 0
    b[j]<a[i]    no of inversion will be 2 since have have to cross two element



*/
//APPROACH 3
long long  merge_algo(long long *arr,long long &temp,int left,int mid ,int right)
{
    int  i,j, k;
    long long inv_count = 0;
    i =left;
    j=mid;
    k=left;
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count +=inv_count + (mid-i);
        }
    }
    //one of the array is finished
    while(i<=mid-1)temp[k++]=arr[i++];
    while(j<=right)temp[k++]=arr[j++];
    //copying the temp values in the original array i.e arr since it is outplace 
    //but for comparision arr is used
    for(i=left;i<=right; i++)
    {
        arr[i]=temp[i];
    }
    return inv_count;
}
long long merge_sort(long long &arr,long long &temp, int left , int right )
{
    int  mid
    long long inv_count = 0;
    if(left < right)
    {
        //divide
        mid = (left+right)/2;
        inv_count += merge_sort(arr,temp,left,mid);
        inv_count+= merge_sort(arr,temp,mid+1,right);

        //conqueor
        inv_count+=merge_algo(arr,temp,left,mid,right);
    }
    return inv_count;
}
long long getInversions(long long *arr, int n){
    long long temp[n];
    int ans(arr,temp,0,n-1);

}
