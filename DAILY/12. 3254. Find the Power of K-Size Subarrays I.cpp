class Solution {
private:

    //SOL 1
    //T.C O(n^2) sol1 works fine since the constraint n < 1000 which is much smaller than 10^5 where usually O(n^2) solutions doesn't work
    /*
        basic approach ->
            for each element from i = 0 to i = n-k we are just checking if k elements from that i are consecutive or not if consecutive we save the ans[i+k-1] as the ans[i] otherwise the ans[i] = -1   
    
    */
    vector<int> trivialSol(vector<int>& nums,  int k){
        int n = nums.size();
        vector<int> ans(n-k+1,-1);
        for(int i = 0; i<= n-k; i++){
            bool power = true;
            // cout<<"i "<<i<<endl;
            for(int j = i; j<i+k-1; j++){
                // cout<<"j "<<j << endl;
                if(nums[j] +1 != nums[j+1]){
                    // cout<<" num[j] "<< nums[j]<<" nums[j+1] "<<nums[j+1]<<endl;
                    power = false;
                    break;
                }
            }
            // cout<<"power "<<power<<endl;
            if(power)ans[i] = nums[i+k-1]; 
        }
        return ans;
    }
    //NOT COMPLETED, TO DO
    vector<int> sol2SlidingWindow(vector<int>& nums, int k ){
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        //preparing the initial window 
        int i = k-1;
        while(i > 0){
            if(nums[i]  = nums[i-1]+1){
                i--;
            }
            else break;
        }
        int ans_size = n-k+1;
        if(i= 0)ans[0] = nums[k-1];
        int start = i-1;
        int end = 
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        return trivialSol(nums, k);
    }
};
