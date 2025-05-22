/*
    reference video -> 
    https://www.youtube.com/watch?v=7jNS2hoM8Yw

    intution ->
        for each index of nums we are checking which lines cover this index and, while doing that we take the longest lines to cover it.
        since each line contribute one, we require nums[i] lines to be passing from i^th index of nums


        why we are using longest line => because the longest line will even encampass the smaller line, they are overlapping lines 
        -------   L1
        -----------------------  L2
        we will take L2 because L2 will cover all index of L1 and it will cover some extra indexes too, hence it will always be usedfull to take longer lines

        //we sort the lines as per the starting index index of each line(query) so that they get sorted from starting and we can process them

    APPROACH algorirthm ->>
        we traverse all the index of nums array
        for each index ->
        1.    we insert all the lines(query) which start at index i in a max-heap called avialable lines , it's a max-heap because so that it can store the longest line at the top.
            also we will insert only the end of the line because ending is only important where a line end not the starting, we will understand it better as we move forward.

        2. we have a used-query min-heap which store the line which are already used, we are using min-heap because at index i we also need to remove all the used-line which end at index i, so that at every moment we have the lines in used which can be used for current index.

        3. we used a counter called used_query_counter, it store the number of unique line which we will used,
        when we want to used a line we FIRST transfer it from available_queries to used_query then use it. and while transfering we increment this used_query_counter

        4. finally we return query_size() - used_query_counter i.e total queries - the queries we used
        

        ALGORITHM ->
            for each index of nums ->
                1. store all the line which start at index i, in the avialable_query
                2. use the line from used_query min-heap since at any moment only those queries will be in the used_query which can be used for current counter
                3. if after using the used_query still we require some lines, we transfer from availabe to used_queries and use them
                4. if there are not enough lines to fulfill our need even after transfering from available_queries we need to return -1
                5. remove all the lines from used_query which end at current index i.e i

*/
class Solution {
private:
    int sol_max_removal(vector<int>& nums, vector<vector<int>>& queries){
        //sort the queries as per the starting point
        sort(queries.begin(), queries.end());
        int n = nums.size();
        int q = queries.size();
        //create max-heap for storing the current available queries
        //this will only store the endoing point
        //we are using max-heap because we want to store the largest line at top, because we want to use the largest line among the overlapping lines
        priority_queue<int> available_queries;
        //create min-heap which will store the used queries, these will contain values transfered from available_queries
        //min heap being used because we will have to remove index which end at current index and hence can be done in O(1)
        priority_queue<int, vector<int>, greater<int>> used_queries;


        //all the queries starting with which index are to be inserted in the available query
        int query_pos = 0;
        int used_query_counter = 0;
        for(int i = 0; i<n; i++){
            //push all the queries starting at current index in the available query
            while(query_pos < q && queries[query_pos][0] == i){
                //push the ending of the query in the available query
                available_queries.push(queries[query_pos][1]);
                query_pos++;
            }
            //for current index use the Used query, since right now, query which can be used at current index will be in the used_query min-heap and then if used query are not sufficient then we can use from avaible by transfering them into the used query        
            //uing the queries from used_queries, since we can use the already used one
            nums[i]-=used_queries.size();
            //use query from available query if needed
            //query from available will be needed when nums[i]>0  even after doing nums[i]-=used_query.size();
            //available_queries.top() >= i  -> this is being done since there would be some queries which are already finsihed in the available query since we are not removing them from available query hence doing that check
            while(nums[i] > 0 && !available_queries.empty() && available_queries.top() >= i ){
                //transfer the current largest query from available query to used query , in below two steps
                used_queries.push(available_queries.top());
                available_queries.pop();
                //once less query is required now
                nums[i]--;
                //since transfered to used query hence increment
                used_query_counter++;
            }

            //if after used the used and transfering the valid queries, if we still have some query required for current index then it's not possible
            if(nums[i]>0)return -1;

            //remove the query from used_query which ends at current index;
            while(used_queries.size() && used_queries.top() == i){
                used_queries.pop();
            }
        }
        return queries.size() - used_query_counter;
    }   
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        return sol_max_removal(nums, queries);
    }
};
