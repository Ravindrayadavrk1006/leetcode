/*
    approach -> since the array is rotated then on finding the mid , either left-mid or mid-right part would be sorted , in sorted part we are sure that the first element in that range is smallest value whereas we are not sure about the unsorted part, so we take a global ans variable ans initialized to int_max and then we update with the minimum value of sorted part and we move to other side unsorted side to check if that part could further reduce or give better minimum answer

*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ;
        int n = nums.size();
        int high = n-1;
        int ans = INT_MAX;
        while(low<= high){
            int mid = (low+high)/2;
            //it means left is sorted
            if(nums[low]<=nums[mid]){
                //we take the minimum value from the sorted part and if it is smaller than the previous minvalue of ans we update the ans and move right
                ans = min(nums[low],ans);
                //then we go right and find answer in the right since the array is rotated so minimum might lie in right
                low = mid+1;
            }
            //if left is not sorted then the right might be sorted
            else{
                ans = min(nums[mid],ans);
                //we have the right smallest element and we compared with the exisiting answer value and smaller than existing value we update the answer
                high = mid-1;
            }
        }

        return ans;
    }
};
