class Solution {
private:
    //WRONG SOLUTION
    //below one is failing in the case , suppose [4,52,38,59,71,27,31,83,88,10] , 52 will be swapped with 38 but later we can swap 38 with 27 but in solution same index is not allowed to swap again which is wrong, it should be allowed change the logic
    vector<int> brute_force(vector<int> & nums, int limit){
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int curr_min_ind = i;
            int curr_diff = 0;
            for(int j=i+1; j<n; j++){
                if(nums[j]< nums[i] && abs(nums[j] - nums[i])<= limit && abs(nums[j] - nums[i])> abs(nums[i] - nums[curr_min_ind]) ){
                    curr_min_ind = j;
                }
            }
            swap(nums[i], nums[curr_min_ind]);
        }
        return nums;
    }


    //comparator function
    static bool compare_by_second(const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second;
    }
     /*
        approach ->
            created offline queries and stored in min-heap.
            in min-heap element will be sorted it means that the element which can be swapped among themselves all will be together,
            now we use a vector for storing the element whose difference is less than or equal to limit 

            so we starting popping the element from min-heap ans storing in vector , we pop if the vector is empty or the last element of vector and top element of min_heap has a diffrence <= limit
            we copy this vector and sort on basis of second element  to get the sorted index also since el.second is the index, in the sorted order of index we store the element from the orginal vector since they are already in sorted order
    
    */
    vector<int> working_sol(vector<int>& nums, int limit){
        int n = nums.size();
        //create offline queries and insert these offline queries  in min-heap
        //min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(int i = 0; i<n; i++){
            min_heap.push({nums[i], i});
        }
        // cout<<"size initial"<<min_heap.size()<<endl;
        while(min_heap.size()){
            //vector to store all those element whose difference <= limit
            vector<pair<int,int>> temp_store;

            //[NOTE***]
            //when while nested loop always remember to put the exit condition of upper loop
            //in other condition checking if the vector is empty or the top element of min_heap and last elemet of vector has difference under the limit
            while(min_heap.size() && (temp_store.size() == 0 || abs(temp_store[temp_store.size() - 1].first- min_heap.top().first)<= limit) ){

                //pshing the elment in the vector
                temp_store.push_back(min_heap.top());
                //removing the element from the heap
                min_heap.pop();
            }


            //for storing the index of temp_store element in sorted order
            vector<pair<int,int>> indexes = temp_store;
            // cout<<"remaining size"<<min_heap.size()<<endl;
            //sort the indexes
            sort(indexes.begin(), indexes.end(),compare_by_second );
            int temp_n = temp_store.size();
            //now at these index place the sorted element
            //i.e we have element and their index we sort the index and elements are already sorted so place them in that order
            for(int i =0; i< temp_n; i++){
                nums[indexes[i].second] = temp_store[i].first;
            }
        } 
        return nums;
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // return brute_force(nums, limit);
        return working_sol(nums, limit);
    }
};
