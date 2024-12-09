class Solution {
private:
    vector<bool> solLineSweepAlgorithm(vector<int>& nums, vector<vector<int>>& queries){

        // nums.push_back(1- nums[nums.size()-1]%2);
        vector<vector<int>> startStops;
        int qSize = queries.size();
        for(int i = 0; i< qSize; i++ ){
            startStops.push_back({queries[i][0],1,i});
            startStops.push_back({queries[i][1], -1, i});
        }
        vector<bool> ans(qSize, true);
        //sort the startStops vector
        sort(startStops.begin(), startStops.end());
        auto& prev = startStops[0];
        int n = startStops.size();
        for(int i = 1; i<n; i++){
            auto& curr = startStops[i];
            // cout<<i<<" "<<curr[0]<<" "<<curr[1]<<" "<<curr[2]<<endl;
            //i.e both are start
            if(curr[1] == 1 && prev[1] == 1){
                int end = curr[0];
                int start = prev[0];
                while(end> start){
                    if(nums[end]% 2 == nums[end-1]%2){
                        ans[prev[2]] = false;
                        break;
                    }
                    end-=1;
                }
            }
            //previous is a start and current is a stop
            else if(prev[1] == 1 && curr[1] == -1){
                int end = curr[0];
                int start = prev[0];
                while(end> start){
                    if(nums[end]% 2 == nums[end-1]%2){
                        ans[prev[2]] = false;
                        ans[curr[2]] = false;
                        break;
                    }
                    end-=1;
                }
            }
            else if (prev[1] == -1 && curr[1] == -1){
               int end = curr[0];
                int start = prev[0];
                while(end> start){
                    if(nums[end]% 2 == nums[end-1]%2){
                        ans[curr[2]] = false;
                        break;
                    }
                    end-=1;
                } 
            }
            //do nothng
            // else if(prev[1] == -1 && curr[1] == 1){
                
            // }
            prev = curr;
        }
        for(int i = 0; i< qSize; i++){
            if(queries[i][0] == queries[i][1])ans[i] = true;
        }
        return ans;
    }

//working solution , travese the code to know the approach
    vector<bool> usingPrefixSum(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        //using the concept of prefix sum , we are calculting the number of no special adjacent's we have
        vector<int> prefix(n,0);
        for(int i = 1; i<n; i++){
            //if current is non-special , this add to the previous value
            if(nums[i]%2 == nums[i-1]%2){
                prefix[i] = prefix[i-1] + 1;
            }
            //if parity are different then we keep the same count
            else{
                prefix[i] = prefix[i-1];
            }
        }
        int qSize = queries.size();
        vector<bool> ans(qSize, true);
        //for each query we are checking if there is any element which can make the range non-special
        for(int i= 0; i<qSize; i++){
            if(prefix[queries[i][1]] - prefix[queries[i][0]]  > 0 )ans[i] = false;
        }
        return ans;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        return solLineSweepAlgorithm(nums, queries);

        // return usingPrefixSum(nums, queries);
    }
};
