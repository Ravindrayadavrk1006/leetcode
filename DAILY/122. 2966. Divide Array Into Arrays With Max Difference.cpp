class Solution {
private:
    /*
        INTUTION -> for difference 

        approach ->
            when a array is sorted the elements with smallest distance are closest
            and we have elements sorted according to distance


            it will suit all cases let's say why

            2 2 3 3 5 7 
            in first array if we keep [2 2 3 ] i.e sorted element it will work
            but if we try to insert let's say 5 instead of 3 making it [2 2 5] then it will not work
            using this simple intution 

            sorting the array and then checking if the difference between first and last element of sorted array of each smaller array of size 3 is under range k if not it means they can't be placed in this array and if the sorted element can't be placed in a array then no other element can be placed to satisfy our solution.

            
    */
    vector<vector<int>> sol(vector<int>& nums, int k){
        int n = nums.size();

        //sort the array
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i =0;
        //checking if any smaller array can fail if yes then we return empty arry
        while(i <n){
            if(nums[i+3-1]- nums[i] > k)return ans;
            i+=3;
        }
        //if code is here it means there is possibility of answer
        i = 0;
        //group the sorted eelemnt in group of 3 elements and return
        while(i<n){
            //create a temp array to store array of 3 element from current position
            vector<int> curr_vec;
            for(int j =i; j<i+3; j++)curr_vec.push_back(nums[j]);

            //move i to i = i+3
            i+=3;
            ans.push_back(curr_vec);
        }
        return ans;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        return sol(nums, k);
    }
};
