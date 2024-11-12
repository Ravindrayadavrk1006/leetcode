/*
    explanation -> 
        asked about maximum beauty, where price is equal to or less than queries[i], this we have to do for all  elements of queries,


        how we proceed , we have sorted the items array this is done in order that price get's sorted, we create offline queries from queries array this is done in order to sort the queries and saving the index as well.
        we are sorting the offline queries so that for each querie we find the index number from items smaller or equal to offlinequery[i][0] and insert all the items smaller index .

        we are sorting the qeueries so that we can keep track of elements inserted till now and we don't have to insert the elements again and again.
        we insert the beauty of items till then or equal to that price in the max priority queue so that we can get the element in one hit

*/

class Solution {
private:
    //binary search for finding less than or equal to
    int helper_binary_search(vector<vector<int>>& items,int el){
        int start = 0;
        int end = items.size()-1;
        while(start<= end){
            int mid = (start + end)/2;
            if(items[mid][0]>el)end  = mid-1;
            else start = mid+1;
        }
        //if the value is smaller then items[0][0] then it will return -1
        return end;
    }
    vector<int> solMaximumBeauty(vector<vector<int>>& items, vector<int>& queries){
        //sort the items
        sort(items.begin(), items.end());
        int n_queries = queries.size();
        vector<int> ans(n_queries); 
        //this variable tracks till what index of sorted items array we have inserted beauty till now
        int inserted_till_now = 0;
        //creating a max heap for inserting beauty so that at any time the maximum element is at top
        priority_queue<int> pq;
        //creating offline queries
        //this is done so that we can sort the queries and also track the index of query in original queries , these index are require because we need to insert in the answer array
        vector<vector<int>> offline_queries(n_queries, vector<int>(2));
        for(int i = 0; i<n_queries; i++){
            offline_queries[i] = {queries[i], i};
        }
        //sorting the offline queries according to the queries[i] 
        sort(offline_queries.begin(), offline_queries.end());
        //for each element of offline queries 
        //findng the index in sorted items whose price is equal to just smaller than the offline_queries[i][0]
        for(int i = 0; i<n_queries; i++){
            //findng the index of item whose price is equal to or just smaller than 
            int insert_till = helper_binary_search(items, offline_queries[i][0]);
            if(insert_till <0){
                ans[offline_queries[i][1]] = 0;
                continue;
            }
            while(inserted_till_now <= insert_till){
                pq.push(items[inserted_till_now][1]);
                inserted_till_now++;
            }
           ans[offline_queries[i][1]] = pq.top();
        }
        return ans;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        return solMaximumBeauty(items, queries);
    }
};
