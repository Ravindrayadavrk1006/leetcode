class Solution {
private:

    /*
        approach -> calculated the sum from start and calculated the sum from end and at index i checking if   sum_start[i] >= sum_end[i+1];
    
    */
    int solPrefixSum(vector<int>& nums){
        int n = nums.size();
        int ans = 0;
        vector<long> sum_start(n);
        vector<long> sum_end(n);
        for(int i =0; i<n; i++){
            sum_start[i] = (long)nums[i];
            sum_end[i] = (long) nums[i];
        }
        for(int i=1; i<n; i++){
            sum_start[i]+= sum_start[i-1];
            sum_end[n-i-1]+=sum_end[n-i];
        }
        // for(auto el: sum_start)cout<<el<<" ";
        // cout<<endl;
        // for(auto el: sum_end)cout<<el<<" ";
        // cout<<endl;
        for(int i =0; i<n-1; i++){
            if(sum_start[i]>= sum_end[i+1])ans++;
        }
        return ans;
    }



/*
    if we just have sum_start array and total sum then we can calculate the right sum easily
    since sum_start[i] will become left part sum and total_arr_sum - sum_start[i] is the right sum
*/
    int sol2Easier(vector<int>& nums){
        int n = nums.size();
        vector<long> sum_start(n,0);

        //0th index prehand calculation
        sum_start[0] = nums[0];
        long total_arr_sum = nums[0];
        for(int i=1; i<n; i++){
            //in below two steps adding the previous sum and the current element i.e nums[i]
            sum_start[i]+=sum_start[i-1];
            sum_start[i]+=nums[i];
            total_arr_sum+=nums[i];
        }
        // for(auto el: sum_start)cout<<el<<" ";
        // cout<<endl;
        // cout<<total_arr_sum<<endl;
        int ans=0;
        for(int i =0; i<n-1; i++){
            //this below formula is from    sum_start[i] >= total_arrr_sum - sum_start[i] and then side changing of sum_start[i] 
            if(2*sum_start[i] >= total_arr_sum)ans++;
        }
        return ans; 
    }
public:
    int waysToSplitArray(vector<int>& nums) {
        // return solPrefixSum(nums);   
        return sol2Easier(nums);
    }
};
