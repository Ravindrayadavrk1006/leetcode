class Solution {
    /*
        APPROACH 1 --> count the elements and then find which element has count = 1
        t.c -> O(n+n)  s.c -> O(n)
        approach 1.1
        APPROACH 2-> using the xor operator since xor uses the concept of if both are 1 or both are 0 then make 0 or in simple words for two equal numbers xor will be zero analyze by doing bitwise xor
    */
private:
    //T.C --> O(n)
    int approach_2(vector<int>& nums)
    {
        int n = nums.size();
        int single_element=0;
        for(int i=0; i<n; i++)
        {
            single_element = single_element^nums[i];
        }
        return single_element;
    }

    //T.C logN
    int approach_3(vector<int>& nums)
    {

        //using the logic
        /*
        APPROACH 3-->
            IDEA --> SINCE THE ARRAY IS SORTED AND THE PERSON WAN'T A T.C IN LOGN WE HAVE A INTUTION THAT WE WILL REQUIRE TO USE BINARY SEARCH SINCE THAT ALGO ONLY GIVES LOGN TC
            
            approach--->

            1 1|2 3 3 4 4 8 8 
            if left part is correct then
            first occurance occur at even index and second ocrrance appear at odd index
            using this logic to get the search space everytime
            eg
            . 
            3 3 7 7 |10 11 11 
            mid = 0+7 -> 3
            we check if we our current space space is correct or not
            for it we check if we are in left search space or not
            we check if left of mid index value is same as mid index value
            if yes it means the left part is correct and we will get our disturbance in right side of it
            so we make left = mid +1

        */
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            //mid is a even number
            if(mid%2==0)
            {
                if(mid !=n-1 && nums[mid] == nums[mid+1])left=mid+1;
                else right = mid-1;
            }
            else
            {
                if(mid>0 && nums[mid] == nums[mid-1])left=mid+1;
                else right = mid-1;
            }
        }
        return nums[left];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
         
        // return approach_2(nums);

        if(nums.size() ==1)return nums[0];
        return approach_3(nums);
    }
};
