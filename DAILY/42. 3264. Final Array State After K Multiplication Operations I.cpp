/*
    1.form offline queries to remember the index of the element,
    2.after forming offline queries insert all the elements in the min-heap since we need smallest element element which we can get in logn time here 
    3.pick top k elements one by one, for each element picked insert  the element*mutliplier and it's index
    4. form a answer array of nums array size , now run a while loop to fetch all the elements of the min-heap and keep inserting in the answer array at index of el.second for each element picked from min-heap

*/


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
