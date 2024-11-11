/*
    explanation -> 
        approach we are using , for each nums[i] we are trying to substract the largest prime number which is smaller than nums[i] such that , the resultant substraction is just greater than the previous nums[i-1] substraction result
        1. find all the prime numbers till 1000
        2. once we have all the prime numbers trying to find a prime number just smaller than nums[i] for it we are using the trick of binary search to find just smaller number , we are using the function helper_find_just_smaller_prime()

*/
class Solution {
private:
    //simple application of binary search to find just smaller number than 
    int helper_find_just_smaller_prime(vector<int>& prime, int num){
        int start = 0;
        int end = prime.size()-1;
        while(start<= end){
            int mid = (start+end)/2;
            // if(prime[mid] == num)return mid;
            if(prime[mid]< num)start = mid+1;
            else end = mid-1; 
        }
        return end;
    }
    bool sol2(vector<int>& nums){
        vector<int> prime;
        //t.c O(1000*1000)
        //finding prime numbers
        //prime number are from 2 to n,[2,3,5,7,11,13,........]
        for(int i = 2; i<1000; i++){
            bool is_prime = true;
            for(int j = 0; j<prime.size();j++){
                //if divisble by any previous prime then it is not a prime
                if(i%prime[j] == 0){
                    is_prime = false;
                    break;
                }
            }
            if(is_prime)prime.push_back(i);
        }
        int n = nums.size();
        int curr_min = INT_MIN;
        //for each element findng the just smaller than it prime number and trying to do maximum substraction 
        for(int i = 0; i<n; i++){
            int lesser_prime_index =  helper_find_just_smaller_prime(prime,nums[i]);
            int set = false;
            // cout<<"nums[i] "<<nums[i]<<" prime "<<prime[lesser_prime_index]<<endl;
            for(int pos = lesser_prime_index; pos>=0; pos--){
                if(nums[i]- prime[pos] > curr_min){
                    curr_min = nums[i]- prime[pos];
                    set = true;
                    break;
                }
            }

            //this condition to check that if we can not substract 
            if(!set && nums[i]>curr_min){
                set = true;
                curr_min = nums[i];
            }
            if(!set)return false;
        }
        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        return sol2(nums);
    }
};
