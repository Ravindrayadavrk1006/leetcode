class Solution {
private:
    long long sol_minSum(vector<int>& nums1, vector<int>& nums2){
        //oth index is of num1 , 1st index is for nums2
        //first row is sum, second row is no of zeros
        vector<vector<long long>> metrices(2, vector<long long>(2,0));
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i =0;

        //finding sum and count of zeros in each array
        for(; i<min(n1, n2); i++){
            if(nums1[i] == 0)metrices[1][0]++;
            else metrices[0][0]+=nums1[i];
            if(nums2[i] == 0)metrices[1][1]++;
            else  metrices[0][1]+=nums2[i];
        }
        while(i<n1){
            if(nums1[i] == 0)metrices[1][0]++;
            else metrices[0][0]+=nums1[i];
            i++; 
        }
        while(i<n2){
            if(nums2[i] == 0)metrices[1][1]++;
            else  metrices[0][1]+=nums2[i];
            i++; 
        }

        //core functionality

        //if neither of array has count of zeros = 0
        if(metrices[1][0] != 0 &&  metrices[1][1] != 0){
            //we are adding sum and adding the count of zeros for both array separately, return which has greater sum of it's element and count of zeros
            return max((metrices[1][0] + metrices[0][0]), (metrices[1][1] + metrices[0][1]));
        }
        //if both arrays has no zeros, then sum of elements should be same
        if(metrices[1][0] == 0 && metrices[1][1] == 0){
            if(metrices[0][1] == metrices[0][0])return metrices[0][1];
            return -1;
        }
        //if nums1 has no zeros, then
        if(metrices[1][0] == 0){
            //sum of nums1 - sum of num2 shoudl be equal to, greater than no of zeros in nums2
            if(metrices[0][0] - metrices[0][1] >= metrices[1][1])return metrices[0][0];
            return -1;
        }
        //if nums2 has no zeros
        if(metrices[1][1] == 0){
            //sum of nums1 
            if(metrices[0][1]- metrices[0][0] >= metrices[1][0])return metrices[0][1];
            return -1;
        }
        return -1;
        
    }
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        return sol_minSum(nums1, nums2);
    }
};
