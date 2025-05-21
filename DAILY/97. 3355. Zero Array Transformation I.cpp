class Solution {
private:  
    /*

        brute force approach ->

            we are doing noting but running over all the queries and in a reduction arr storing the values to be substacted for each index and finally substracting giving TLE 

        time complexity -> O(n*k) where at max (n*n) i.e 10^5*10^5 which emplies that n^2 not good enough
    
    */

    //GIVING TLE
    bool brute_force(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        int k = queries.size();
        vector<int> reduction_arr(n,0);
        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            for(int i = start; i<=end; i++){
                reduction_arr[i]++;
            }
        }
        //now we have the reduction array maintained let's try to decremenet
        for(int i =0; i<n; i++){
            if(nums[i]- reduction_arr[i] >0)return false;
        }


        return true;
    }
    /*
        using line sweep algorithm->


            line sweep algorithm ->  we are taking each query which is a range ->
            we are inserting the query[0], +1  -> +1 denotes it's the starting of the query, we are inserting query[1] + 1 , -1  -> -1 denoting it's a end of a query  ,  also +1 is being done because according to the question till current element it will be considered but not from next element because according to the question [1,3] represent the line is from 1 till 3 after 3 the line won't be there and since the point are integer hence query[1]+1   therefore that (+1) is done.



            once we have inserting, we do the sorting (normal line sweep)

            then we take a element called current which will calcuate the current value
            and we travese the elements of line_sweep sorted vector
            we keep on updating the current vector and also marking in a vector called range_substraction the boundary value i.e pair.first with the current value

            range_substraction vector is saying that where till non-zero next value current value will be considered

            eg [2,0,0, 4, 0,0, 1]  -> from index 0 to 2  -> 2 value will be considered , from index 3 to 5 -> 4 value will be considered and on 6 -> 1 value will be considered.

            we are filling same thing i.e above vector making it [2,2,2,4,4,4,1] in the next for loopp i.e STEP 4


            in the STEP 5 we are substracting from the nums array and if at any point we find the value after substraction is greater than 0 then we return false else return true;
    
    
    */
    bool using_line_sweep(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        int q = queries.size();
        vector<pair<int,int>> line_sweep;
        //STEP 1
        for(auto query: queries){
            line_sweep.push_back({query[0], 1});
            line_sweep.push_back({query[1]+1, -1});
        }

        //STEP 2
        //sorting the line sweep vector
        sort(line_sweep.begin(), line_sweep.end());
        // unordered_set<int> lines_st;
        vector<int> range_substraction(n+1,0);
        int curr = 0;

        //STEP 3
        for(auto el: line_sweep){
            int line_pos = el.first;
            curr+=el.second;
            range_substraction[line_pos] = curr;
        }

        //STEP 4
        //run a for looop and fill the range_substraction array
        int filler = 0;
        for(int i =0; i<n; i++){
            if(range_substraction[i]== 0)range_substraction[i] = filler;
            else{
                filler = range_substraction[i];
            }
        }



        //STEP 5

        //we can run this for loop in the above for loop after updating the value of filler
        for(int i =0; i<n; i++){
            if(nums[i]- range_substraction[i]>0)return false;
        }

        return true;
    }

    //SOL 3 -> working
    //DIFFERENCE ARRAY TECHINQUE
    //EXPLAINED IN THE CP NOTES as well
    /*
        
        in the below steps STEPS marked are part of core concept of difference array techique
    
    */
    bool difference_arr_technique(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        int q = queries.size();
        //STEP 1. difference array step 1
        //create a update array of size n and initialize by 0
        vector<int> update(n, 0);

        //STEP 2. process each query and for each query by whatever number we have to incrememnt let's say it's like
        //(1,3, +3) -> i.e for element between 1 to 3 update with +3 so we will do update[1]+=(+3) and update[3 + 1]-=3
        //i.e at start of query we add the number and at end+1 we substract the number
        //in our question we have to deal with just 1 hence we will do -> +1 and -1

        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            update[start] +=1;
            //checking if end+1 is in our range 
            if(end+1<n){
                update[end+1]-=1;
            }
        }

        //STEP 3 -> do the cumulative sum of the update array
        for(int i =1; i<n; i++){
            update[i] = update[i]+update[i-1]; 
        }

        //STEP 4. do the processing that's in the original array if addition or substraction to be done
        //in our case we have to decrement
        for(int i=0; i<n; i++){
            if(nums[i]- update[i]>0)return false;
        }
        return true;
    }
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //SOL 1 brute force
        // return brute_force(nums, queries);


        // return using_line_sweep(nums, queries);


        return difference_arr_technique(nums, queries);
    }
};
