if we take 3 numbers a,b and n in such a way that,
a and b < n
then we can write a equation a = a + b(n)
and a&b can be retrieved by a = a%n and b = a/n;
so taking a = nums[i] and b = nums[nums[i]] and n = size of array
we can write following code :


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            nums[i] += (nums[nums[i]]%n)*n;
        }
        
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]/n;
        }
        return nums;
    }
};
