class Solution {
private:
    vector<int> solGetFinalState(vector<int>& nums, int k, int multiplier){
        //create offline queries
        vector<pair<int,int>> offlineQueries;
        int n = nums.size();
        for(int i=0; i<n; i++){
            offlineQueries.push_back({nums[i], i});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto el: offlineQueries){
            pq.push(el);
        }
        for(int i=0; i<k; i++){
            auto front = pq.top();
            pq.pop();
            pq.push({front.first*multiplier, front.second});
        }
        vector<int> ans(n);
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            ans[front.second] = front.first;
        }
        return ans;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        return solGetFinalState(nums, k, multiplier);
    }
};
