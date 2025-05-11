//DONE IN LEETCODE/DAILY 90. also, we have refactored it to to categorize it

class Solution {
private:
    /*
        using the sliding window protocol, since if we use the Brute force then from current position everytime next three element need if odd need to be calculated, this will lead to time complexity of 3*N


        //using sliding window protocol 
            1. k = window size = 3 
            2. intialize the first window of size 3 check how many odds are present, if 3 return true from here
            3. for remaining window, while adding next element check if it's odd if yes then increase the count of currOddCount, also if first element of window is odd the decreae the count of currOddCount by 1
    
    */
    bool solUsingSlidingWindowProtocolFixed(vector<int>& arr){
        int n = arr.size();
        //window size
        int k = 3;
        if(n<3)return false;
        int currOddCount = 0; 
        //sliding window, intial window value
        for(int i = 0; i < k; i++){
            if(1 & arr[i])currOddCount++;
        }
        if(currOddCount == 3)return true;
        //now moving the window to check for all the remaining windows
        for(int i=k; i<n; i++){
            //adding new elmeent to the window
            if(1 & arr[i])currOddCount++;
            //removing the first element of the window
            if(1 & arr[i-k])currOddCount--;
            if(currOddCount == 3)return true;
        }
        return false;
    }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        return solUsingSlidingWindowProtocolFixed(arr);
    }
};
