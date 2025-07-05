class Solution {
private:
    int sol(vector<int>& arr){
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int el: arr){
            mp[el]++;
        }
        int ans = -1;
        for(auto el: mp){
            if(el.first == el.second){
                ans = max(ans, el.second);
            }
        }
        return ans;
    }
public:
    int findLucky(vector<int>& arr) {
        return sol(arr);
    }
};
