/*
    explanation:
        here we are using the concept of bubble sort which store the biggest element in each iteration at last by comparing two adjacent elements and other concept is of finding the number of set bits using bit manipulation


    so first checking if adjacent elements has same number of set bits if yes , then checking if it is swapable according to bubble sort, if yess we swap 

*/

class Solution {
private:
    int countsetbit(int num){
        
        int setbitcount = 0;
        for(int i = 0; i<32; i++){
            if((num>>i)&1)setbitcount++;
        }
        return setbitcount;
    }
    bool sortingArray(vector<int>& nums){
        int n = nums.size();
        bool swapped = false;
        //doing n-1 passes
        for(int i = 0; i<n-1; i++){
            //for each pas doing the comparision in each pass each element will be placed at correct places from end and hence there is i in j<n-i-1 
            for(int j=0; j<n-i-1; j++){
                //checking if both numbers has same number of set  bits
                //next checking normal condition of bubble sort
                if((countsetbit(nums[j]) == countsetbit(nums[j+1])) && nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped= true;
                }
            }
            //if in the current pass no elements are swapped then we need to break because it is already sorted or not sortable at all
            if(!swapped)break;
        }


        for(int i= 0; i<n-1; i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
public:
    bool canSortArray(vector<int>& nums) {
        return sortingArray(nums);
    }
};
