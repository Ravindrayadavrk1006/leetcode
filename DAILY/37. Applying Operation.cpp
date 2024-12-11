class Solution {
private:

    //giving TLE
    /*
        for each element, we are finding what elements it can be eg , k = 2 and 4 can be 2,3,4,5,6
        for all these elements we are trying to make a count , if further elements can become that element,
        we are storing each element's count in a hashmap , beause if once we have found count of 2 then it's needless to do it again

    */
    int solBruteForce(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int n = nums.size(); 
        //for each element of nums
        for(int i =0; i<n; i++){
            //form which element it can become i.e it can be nums[i]-k to nums[i]+k, for each element we are checking if the other elements can become this element 
            for(int val = nums[i]-k; val<= nums[i]+k; val++)
            {
                //if current element is already checked we don't have to check for it again
                if(mp.find(val) != mp.end())continue;
                //increment this element count
                mp[val]++;
                for(int j= i+1; j<n;j++){
                    //using nums[j]-x = val-> just transfer it to become nums[j]-val = x  , we are saying if by substracing two value we get a number whose absolute value is less than k we can it lie's in our range
                    if(abs(nums[j]- val) <= k)mp[val]++;
                }
            }
        }
        int ans = 1;
        for(auto el: mp){
            ans = max(ans, el.second);
        }
        return ans;
    }


    //-----------WORKING SOLUTION
    //let's try to do it with line sweep algorithm
    int solLineSweepAlgorithm(vector<int>& nums, int k){
        int n = nums.size();
        vector<vector<int>> startStop;
        //we are creating the ranges
        /*
            here for end we have used 2 as marker because we wan't to consider if one has a starting point and other has a ending point at that location then , the answer need to be two
        */
        for(int i = 0; i<n; i++){
            //pushing the start
            startStop.push_back({nums[i]-k, 1});
            //pushing the stop, {, denotes it is ending}
            startStop.push_back({nums[i]+k, 2});
        }
        int curr_count = 0;

        //sort the elements
        sort(startStop.begin(), startStop.end());
        int ssSize = startStop.size();
        int ans = 1;
        //for each range we have to just find the max elements which lies in a range
        for(int i = 0; i<ssSize; i++){

            //if it's a starting we add one to the current_count and when the count increases we try to compare and maximize the answer
            if(startStop[i][1] == 1){
                curr_count++;
                ans = max(ans, curr_count);
            }
            //if it's a ending we reduce the current count
            else{
                curr_count--;
            }
        }
        return ans;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // return solBruteForce(nums, k);

        return solLineSweepAlgorithm(nums, k);
    }
};
