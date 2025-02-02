class Solution {
private:

    /*
        using the concept if a array is rotated by x positions , suppose A was rotated to become B
        then 
        A[i] = B[(i+x)%A.length]
        e.g B = [3,4,5,1,2] ,  A = [1,2,3,4,5]  x = 3(rotated_by) first index where element is less than previous element
    
    */
    bool sol_check(vector<int>& nums){
        int n = nums.size();

        //sorted a array
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int rotated_by = 0;
        // for(int i: sorted_nums)cout<<i<<" ";
        // cout<<endl;

        //finding x , i.e position at which that element is rotated
        for(int i =1; i<n;i++){
            if(nums[i]< nums[i-1]){
                rotated_by = i;
                break;
            }
        }
        // cout<<rotated_by<<endl;
        if(rotated_by == 0)return true;
        for(int i =0; i<n; i++){
            if(sorted_nums[i] != nums[(i+rotated_by)%n] )return false;
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        return sol_check(nums);
    }
};
