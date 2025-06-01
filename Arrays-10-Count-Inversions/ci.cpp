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
    
APPROACH 2-->
  
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
//APPROACH 2



//JUST ONE EXTRA LINE OF CODE IN THE MERGE SORT CODE 
#include <bits/stdc++.h> 
long long inversion_count = 0;
void merge(long long arr[], int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            //---------------THIS IS THE ONLY EXTRA LINE ADDED
            inversion_count+=(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

long long getInversions(long long *arr, int n){
   mergeSort(arr, 0, n-1);
   return inversion_count;
}
