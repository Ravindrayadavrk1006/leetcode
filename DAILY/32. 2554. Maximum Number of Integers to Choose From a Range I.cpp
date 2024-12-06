/*
    the problem is pretty simple and straight
    we have to count the maximum no of element such that the sum of those elements remains less than maxSum, the numbers we have to choose should be in the range [1,n]

    normal thought
        let's suppose the maxSum is 4, banned = [1,4] , n = 7 
        2+3 i.e two element sum makes 5, or just 4 will make the sum less than that,
        but the answer will be same in both cases that is we have reduce one element from 2+3 

        using this intuition---->
        

    approach of our solution->
        we inserted all the elements of banned in the map so that to check if a element is banned we have to spend just log time,
        we could reduce this insertion time by just doing a binary search check since the banned should be sorted but not given explicitivly that's why will have to sort it first

        then we have take two variable -> count and curr_sum whhich is current sum

        we add the current element in the sum if that element is not banned if the sum after adding exceede the maxSum then we return count-1 since one element will have to be removed anyhow to satisfy our answer.

        if after running the loop from [1,n]  the sum never exceeds the maxSum we finally outside the for loop return the count
 

*/

class Solution {
private:
    int solMaxCount(vector<int>& banned, int n , int maxSum){
        unordered_map<int, bool> mp;
        // int bannedSize = banned.size();
        //inserting the element in the map for easy checking 
        for(int el : banned){
            mp[el] = true;
        }

        int count = 0;
        int curr_sum = 0;
        for(int i = 1; i<=n; i++){

            //if the element is not banned 
            if(mp.find(i) == mp.end()){

                //add the current element in the sum
                curr_sum+= i;
                //increase the count
                count++;
                //if at any moment our sum exceed the maxSum we return the count-1
                if(curr_sum > maxSum)return count-1;
            }
        }

        //if after runnng the loop for all the elements the if condition would never have been satisified then only code reaches here
        //i.e the curr_sum after checkeing all the elemtns will be less than maxSum therefore we return the count  
        return count;
    }


    // sol 2

    //using binary search for finding the element if it is banned or not unlike in the first solution where we insert the element in the map and then search in logn time
    bool helper_binarySearch(int el, vector<int>& banned){
        int start = 0;
        int end = banned.size()-1;
        while(start <= end){
            int mid = (start + end )/2;

            //false states that element is present and banned
            if(el == banned[mid])return false;
            else if(banned[mid]> el)end = mid-1;
            else start = mid+1;
        }
        return true;
    }
    int sol2(vector<int>& banned, int n , int maxSum){
        sort(banned.begin(), banned.end());
        int count = 0, current_sum =0;
        for(int i = 1; i<=n; i++ ){
            if(helper_binarySearch(i, banned)){
                current_sum+= i;
                count++;
                if(current_sum > maxSum)return count-1;
            }
        }
        return count;
    }
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        //sol 1
        // return solMaxCount(banned, n, maxSum);


        //sol 2
        return sol2(banned, n, maxSum);
    }
};
