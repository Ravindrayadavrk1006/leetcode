/*
approaches --->>
[1]. since not given if sorted or not so we sort them
    [[1,3],[2,6],[8,10],[15,18]] standing at 1,3 we look if we can merge 2,6 in 1,3 we say so we current array become 1,6 now lookin gat 8,10 since we can't merge 8,10 in in 1,6 so we push 1,6 in the answer array
    and now current array become 8,10 we see if 15,18 can be merge in 8,10 which is no hence we push 8,10 in array 
    and now array becomes 15,18 since nothing to compare hence we push 15,18 in the array

    merge logic we compare if nums[i][1]>=nums[i+1][1] we merge and the new array become nums[i][0],max(max[i][1],max[i+1][1])

*/
class Solution {   
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sol(intervals,ans);
        if(intervals.size() == 0)return ans;
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];

        for(auto arr:intervals)
       
            if(arr[0]<=temp[1])
            {
                temp[1]=max(arr[1],temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = arr;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
