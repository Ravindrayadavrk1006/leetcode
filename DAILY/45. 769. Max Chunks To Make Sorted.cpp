class Solution {
private:
    

    //checking if the element index 0 to max_element are marked true , if all are true then return true else return false
    bool helper_previous_all_marked(int curr_max,vector<bool>& vis){
        for(int i = curr_max; i>=0; i--){
            if(!vis[i])return false;
        }
        return true;
    }

    //approach 

    /*
        we are finding the max_element till now and if all the indexes from 0 to max_element index are marked true then it can form a group else not
    
    */
    int sol2(vector<int>& arr){
        int n = arr.size();
        vector<bool> vis(n, false);
        int chunks = 0;
        int curr_max = INT_MIN;
        for(int i = 0; i<n; i++){
            //find the max elment till now
            curr_max = max(curr_max, arr[i]);
            //marking the current element visited as well
            vis[arr[i]] = true;
            //checking if all the elements from index 0 to index max_element are visited if visited then it can be formed a group, visualize
            if(helper_previous_all_marked(curr_max, vis))chunks++;
        }
        return chunks;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        return sol2(arr);
    }
};
