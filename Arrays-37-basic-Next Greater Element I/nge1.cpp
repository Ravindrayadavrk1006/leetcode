class Solution {
    /*
    simple approach for each element of nums1 we go in nums2 and look which element is equal to nums1 that element save the nums2 element index which is equal to nums1 element in a var called greater_index 
    again start a for loop which traverse ahead of grater_index index and if find a element greater then we save in ans otherwise the value is set -1 by default for all
    
    */
private:
    vector<int> sol(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1,-1);
        for(int i = 0;i<n1; i++)
        {
            int greater_index = -1 ;
            for(int j = 0; j<n2; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    greater_index = j+1;
                    break;
                }
            }
            for(int j = greater_index; j<n2; j++)
            {
                if(nums2[j]>nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }

        }
        return ans;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return sol(nums1,nums2);
    }
};
