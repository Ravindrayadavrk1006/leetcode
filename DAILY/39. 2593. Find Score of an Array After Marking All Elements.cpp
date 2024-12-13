class Solution {
private:
/*
    basic problem->
        create offline queries with each element as pair and first part as nums[i], and second part i so {nums[i], i}  and then sort them,
        we traverse all the elements of this sorted offline query, if the ith element is not marked(all the elements which are makred, their original indexes i.e i, we are storing in a set), we add this value to answer and then store mark i, i-1, i+1 as visited indexes
*/
    long long solOfflineQueries(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>> offlineQueries;
        //creating offline queries
        for(int i = 0; i<n; i++){
            offlineQueries.push_back({nums[i], i});
        }
        //sort the offline queries
        sort(offlineQueries.begin(), offlineQueries.end());
        long long ans = 0;
        unordered_set<int> st;
        int i = 0;
        //traverse all the elements of the sorted offline query
        while(i<n){
            //if the elemnt is not marked, add it to answer and mark this index and it's adjacent element as marked
            if(st.find(offlineQueries[i].second) == st.end()){
                ans+=(long long)offlineQueries[i].first;
                st.insert(offlineQueries[i].second);
                st.insert(offlineQueries[i].second -1);
                st.insert(offlineQueries[i].second + 1);
            }
            i++;
        }
        return ans;   
    }
public:
    long long findScore(vector<int>& nums) {
        return solOfflineQueries(nums);
    }
};
