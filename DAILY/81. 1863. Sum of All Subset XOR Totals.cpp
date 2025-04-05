
#include <bits/stdc++.h>

using namespace std;

class Solution {
    //for sol2 
    //xor of any number with 0 is that number itself since 0^1 = 1 , 1^0 = 1
    int final_ans = 0;
    private:
    
        //sol 1
        //brute force
        //generate all subset of the array
        void generate_all_subset(int pos, vector<int>& subset, vector<vector<int>>& all_subset, vector<int>& nums){
            if(pos<0){
              //let's do here only
               all_subset.push_back(subset); 
               int curr_xor = 0;
            }
            //take
            subset.push_back(nums[pos]);
            generate_all_subset(pos-1, subset, all_subset, nums); 
            //remove the disturbance
            subset.pop_back();
    
            //not take
            generate_all_subset(pos-1, subset, all_subset, nums);
        }



        //sol 2 helper
        void generate_all_subset_sol2(int pos, vector<int>& subset, vector<int>& nums){
            if(pos<0){
              //let's do here only
            //    all_subset.push_back(subset); 
               int curr_xor = 0;
               for(int el: subset){
                curr_xor^=el;
               }
               final_ans+=curr_xor;
               return;
            }
            //take
            subset.push_back(nums[pos]);
            generate_all_subset_sol2(pos-1, subset, all_subset, nums); 
            //remove the disturbance
            subset.pop_back();
    
            //not take
            generate_all_subset_sol2(pos-1, subset, all_subset, nums);
        }


        //sol 3

            /**
             explanation -> from editorial, sol 3 of editorial
            suppose length of nums = n 
             we take or of all the elements of the nums array and then add n-1 0 at tha last
             explanation given in the editorial
             */
            int sol3(vector<int>& nums){
                int len = nums.size();
                int or_of_array = 0;
                for(int el: nums){
                    or_of_array|=el;
                }
                return or_of_array<<len-1;
            }
    public:
        int subsetXORSum(vector<int>& nums) {
    
    
            //SOL 1
    
            /*
                approach generate all the subsets of the given set and then do the xor of each subset return the sum of all resultant subset
            
            */
            int len = nums.size();
            if(len == 0)return 0;
            int pos = nums.size()-1;
            vector<vector<int>> all_subset;
            vector<int> subset;
            generate_all_subset(pos, subset, all_subset, nums);
            
            int total_xor = 0;
            int total_subset = all_subset.size();
            //since last subset will be an empty subset therefore till total_subset-1 
            for(int i = 0; i<total_subset-1; i++){
                //taking the first element of subset as the intital xor of
                int curr_xor = all_subset[i][0];
                int curr_vec_len = all_subset[i].size();
                //doing xor of all element of current subset
                for(int j=1; j< curr_vec_len; j++){
                    curr_xor^=all_subset[i][j];
                }
                total_xor+=curr_xor;
            }
            return total_xor;






            /* SOL 2
            */


            /*
                T.C -> O(2^n)
                explanation ->
                here instead of generating all the subset pushing them in a subset and then processing all subset in the caller function, we in the generate_all_subset_sol2 function once one subset is generated we, find the final xor of that subset and add it to the final_ans var, in this we don't have to save in a all_subset vector and then process it later
                
            */

            int len = nums.size();
            if(len == 0)return 0;
            int pos = nums.size()-1;
            vector<vector<int>> all_subset;
            vector<int> subset;
            generate_all_subset_sol2(pos, subset, all_subset, nums);
            return final_ans;
        


            //sol 3
            return ans3(nums)
        }
    };
