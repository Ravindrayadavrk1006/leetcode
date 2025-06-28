class Solution {
private:
    //important thing 
    /*
        1. subsequence can contain any elements but the order need to be maintained i.e  smaller index element should come first


        approach ---->
            as per explanation in the EDITORIAL
            create offline queries where first element is index and second is value 
            then sort in descending order as per second elements so that we get the k greatest elements
            //now since we want the asnwer in order of smaller index first then we sort these greatest k elements as per their first element i.e indexes
            and return that as answer

    */
    vector<int> using_editorial( vector<int>& nums, int k){
        int n = nums.size();
        vector<pair<int,int>> offline_queries;
        for(int i =0; i<n; i++ ){
            offline_queries.push_back({i, nums[i]});
        }
        //sort in descending order
        sort(offline_queries.begin(), offline_queries.end(), [&](auto el1, auto el2){ return el1.second > el2.second;});

        //now we have elements sorted in descending order our required k elements will be at start
        //now we are sorting in ascending order as per the index of k greatest elements
        sort(offline_queries.begin(), offline_queries.begin() + k);
        vector<int> ans;
        for(int i=0; i<k; i++)ans.push_back(offline_queries[i].second);
        return ans;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        return using_editorial(nums, k);
    }
};
