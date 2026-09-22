class Solution {
public:

    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int left = 0 ;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)return true;
            /*in repeated element case we can have condition like [1,0,1,1,1]
               in the above example we can't be sure which part is sorted mid = 1 left =1 right is also 1, so when we check the condition of sorted arr[left]<= arr[mid] we get true but if we
               see the left part is not sorted therefore. 
                here we can't be sure in which range the element will lie and hence we can trim search space(so that we can remove the duplicates and be certain that one part will be sorted) since the repeated element are not usefull at all
             so we are making the left to move one ahead and right to move one left
            */
            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left = left+1;
                right = right-1;
                continue;
            }
            //checking if left part is sorted
            if(nums[mid]>=nums[left])
            {
                //checking if the target lies in the left part
                //if no then we will have to check the target value in right half since rotated
                if(nums[left]<=target && target<=nums[mid])right = mid-1;
                else left = mid+1;
            }
            //left part is not sorted lets check in right part
            else
            {
                if(nums[right]>=target && target>=nums[mid])left = mid+1;
                else right = mid-1;   
            }

        }
        return false;
    }
};
