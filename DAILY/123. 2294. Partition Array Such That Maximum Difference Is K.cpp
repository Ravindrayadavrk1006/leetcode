class Solution {
private:
    /*
        category of problem -> min-max difference

        intuition ->
            normal approach of sorting the array and then running a for loop and when we find a element greater such that curr_el - curr_array_min-element > k we increase the number of subsequence count and set the current element as min element for next array
    
    */
    int sol(vector<int>& nums, int k){
        //sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i =0;
        //to store no of subsequence 
        int count_subseq = 0;
        //start index of current array
        int curr_subseq_start = 0;
        while(i<n){
            //if nums[i] - nums[start] > k then we have found a subseq aka array and we set current i as start for next
            if(nums[i] - nums[curr_subseq_start]> k){
                
                count_subseq++;
                // cout<<i<<" "<<count_subseq;
                curr_subseq_start = i;
            }
            i++;
        }
        //since the last subsequence would be in run when the loops compelete therefore add 1 
        return count_subseq + 1;
    }
public:
    int partitionArray(vector<int>& nums, int k) {
        return sol(nums, k);
    }
};
