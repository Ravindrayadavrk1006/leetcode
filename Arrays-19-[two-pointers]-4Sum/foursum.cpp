class Solution {
/*
    refer 3Sum problem for better understading
    using the same concept as 3Sum 

*/
private:
    vector<vector<int>> two_pointers(vector<int>& nums,int target)
    {
        //since we want the ans in form of vector
        vector<vector<int>> ans;
        // unordered_set<vector<int>> s;
        int n = nums.size();
        for(int p=0; p<n-3;p++)
        {
            if(p==0 || (p>0 && nums[p]!=nums[p-1]))
            {
                for(int q=p+1;q<n-2;q++)
                {
                    if(q==p+1 || (q>1 && nums[q]!=nums[q-1]))
                    {
                        int i = q+1;
                        int j =n-1;
                        long long req = (long long)target - ((long long )nums[p]+nums[q]);
                        while(i<j)
                        {
                            if(nums[i]+nums[j] == req)
                            {
                                ans.push_back({nums[p],nums[q],nums[i],nums[j]});
                                int temp = nums[i];
                                //here suppose we have taken into account ith element to be -1 and suppose next element is also -1 
                                //then we will get duplicates hence to avoid that we keep the i at such position where nums[i] != ith element which has been already used               
                                i++;
                                while(i<j && nums[i]==temp)i++;
                            }
                            else if(nums[i]+nums[j] < req)
                            {
                                i++;
                            }
                            else
                            {
                                j--;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return two_pointers(nums,target);
    }
};
