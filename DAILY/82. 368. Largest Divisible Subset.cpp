class Solution {
private:

    //SOL 1 
    /*
        Verdict -> FAILS TEST CASES

        explanation -> this approach talks about generating all the subset and then checking if current subset is a valid answer or no .
    
    */
    //find the largest divisible subset
    //brute force , it will fail 
    vector<int> largest_subset;
    void brute_force(vector<int>& nums){
        //sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //it won't work since can store only till 2^31
        int total_subset_count = 1<<n;
        //using bitmasking, to generate all the subset of a set
        //generate bitmask of all the subset
        for(int subset_mask = 0; subset_mask < total_subset_count; subset_mask++){
            vector<int> current_subset;
            for(int bit =0; bit <n; bit++){
                if(1<<bit & subset_mask){
                    current_subset.push_back(nums[bit]);
                }
            }
            for(int el: current_subset)cout<<el<<" ";
            cout<<endl;
            //checking if every pair is divisible or not
            bool internal_loop_broken = false;
            int curr_subset_size = current_subset.size();
            for(int i = 0; i<curr_subset_size; i++){
                for(int j = i+1 ; j< curr_subset_size; j++){
                    //if neither is a multiple of other
                    //then we break;
                    if(current_subset[i]%current_subset[j] != 0 && current_subset[j]%current_subset[i] != 0){
                        internal_loop_broken = true;
                        break;
                    }
                }
                if(internal_loop_broken)break;
            }
            //means didn't got out of the loop when elements were not multiple
            if(!internal_loop_broken ){
                if(curr_subset_size > largest_subset.size())largest_subset = current_subset;
            }

        }
    }
    //observation
    //wrong solution fails for test case {5,9,18,54,108,540,90,180,360,720}
    vector<int> sol2(vector<int>& nums){
        int n = nums.size();
        vector<int> final_ans;
        //sort the nums vector, so that smaller element lies before larger element
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++)
        {
            //with current element let's try to see, how many further elements are divisible
            vector<int> curr_vec;
            curr_vec.push_back(nums[i]);
            for(int j = i+1; j<n; j++){
                //if j'th element is divisble by last inserted element of curr_vec 
                if(nums[j]%curr_vec.back() == 0){
                    curr_vec.push_back(nums[j]);
                }
            }
            if(curr_vec.size()>final_ans.size())final_ans = curr_vec;
        }
        return final_ans;
    }



    //using the concept of lis(longest increasing subsequence)

    //using the concept of lis 
        //for storing the list of element
        /*
    
            remember this below is done for finding longest increasing subsequence this same can be used for divisibilty by changing the increasing condition  sorting the array  and then with divisibility 
            let's take a array hash which will initially have self index 
            i.e 
            index        0 1 2 3 4 5
            hash values  0 1 2 3 4 5 
            which states that only  the current element is contributing in the lis
            now when we use the below technique most_optimized to fill lis 
            and lets's try to fill
    
            eg .          5 4 11 1 16 8 
            lis          [1,1,1,1,1,1]
            hash intitially has 0 1 2 3 4 5 
            at 4 we will try to find all the previous for it which can satify the condition of less than it since none hence lis remains same and hash also doesn't update
            at 11 finding lower elements than it we found 5 and we update lis[2]
            and since lis is updated we put the index of 5 i.e 0 in hash at index 2 which states that 2 is the next element in the element to go to.
            when chcking for 4 since less than 11 but we already have 2 value in lis vector for 11 hence no update
        */
    vector<int> sol3_using_lis(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //intially each element will be it's longest subsequence
        vector<int> lis(n,1);
        //hash is used to find the previous element which is part of lis, it will be helpful in finding all the elements of LIS
        /*
            index   0 1 2 3 4 5
            hash    0 1 0 2 1 3


            and we got the final_index of largest lis to be 5
            then we can get all the elements eg .  5 go to 3 then from 3 to 2 and from 2 go to 0
            and hence we got all the elments of the lis
        
        */
        vector<int> hash(n);
        for(int i=0; i<n; i++){
            hash[i] = i;
        }
        int largest_index = 0;
        for(int i = 0; i<n; i++){
            //asking all the previous elemnts to it 
            for(int j=0; j<i; j++){
                //if current i'th element is divisible by previous elmeent and previous element contribution increases current lis value then we add update the lis for current element and also make the previous elment as it's hash
                //i.e the current element is greater to the previous element we asking if it could contirubte in lis
                if(nums[i]% nums[j] == 0  && lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                    hash[i]  = j;

                    //updating the hash for keeping a track
                    if(lis[i]> lis[largest_index])largest_index = i;
                }
            }
        }


        //forming the largest lis by traversing all it's element
        vector<int> final_ans;
        int i = largest_index;
        while(true){
            if(hash[i] == i)break;
            final_ans.push_back(nums[i]);
            i = hash[i];    
        }
        final_ans.push_back(nums[i]);
        return final_ans;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //CALLER BRUTE FORCE(SOL 1)
        // brute_force(nums);
        // return largest_subset;

        //SOL 2
        // return sol2(nums);



        //WORKING SOLUTION
        //SOL 3
        return sol3_using_lis(nums);
    }
};
