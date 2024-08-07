/*
    approach -> exactly finding the smallest value here we have to just find where the smallest number index would lie
    problem link -> https://www.geeksforgeeks.org/problems/rotation4723/1
*/
class Solution {
  public:
  
    int findKRotation(vector<int> &arr) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        int min_val = INT_MAX;
        int min_val_index = n ;
        while(low<=high){
            int mid = (low+high)/2;
            //if means left is sorted
            if(arr[low] <= arr[mid]){
                if(arr[low]<min_val){
                    min_val = arr[low];
                    min_val_index = low;
                }
                //now left is search, search in the right
                low = mid+1;
            }
            //if left was not sorted then right would be sorted
            else{
                if(arr[mid] < min_val){
                    min_val = arr[mid]; 
                    min_val_index = mid;
                }
                //we have tried finding smallest index in the right array let's search in the left array
                high = mid-1;
            }
            
        }
        //modulus used since n times rotation is 0 times rotation
        //we are just doing it for satisfying our case of initial value of n other value won't come more than n 
        return min_val_index%n;
    }
};
