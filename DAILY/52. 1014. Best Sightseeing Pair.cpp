class Solution {
private:
    /*
        basic two nested loop approach
    */
    int bruteForce(vector<int>& values){
        int ans = INT_MIN;
        int n = values.size();
        for(int i =0; i<n; i++ ){
            for(int j = i+1; j<n; j++){
                ans = max(ans, values[i]+ values[j]+ i-j);
            }
        }
        return ans;
    }
    /*
        for each index finding the maximum values of nums[i]+ i where i is less than current index
        then in the above for each element , for each element adding  nums[j]-j  and then returning the maximum of these eleemnt


        approach->
            for each element using the approach of prefixSum finding the maximumValue of nums[i]+ i where i is less than current element
            for it we are starting with index 2, setting for index 1 the maxum nums[i]+i will be nums[0]+0 and curr_max = nums[0] + 0 and hence will , this curr_max for each element we are storing in another array called maxForEl[i] = curr_max
            for index 2 we just have to do curr_max = max(curr_max, nums[2-1]+ 2-1 ) and so forth for each index just have to maximize by just checking for previous index 



            now once we have maxForEl element ready we have nums[i]+i for each element we just have to do nums[j]-j 

            which can be easly done
            so we proceed by taking a ans = INT_MIN and run a for loop from i to n
            calculating  ans = max(ans, maxForEl[j]+ nums[j] - j)


            and finally return this ans
    
    */
    int sol2(vector<int>& values){
        int n = values.size();
        if(n == 1)return values[0];
        vector<int> maxForEl(n, 0);
        int curr_max = values[0];
        maxForEl[1] = values[0];
        for(int i = 2 ; i <n ; i++){
            curr_max = max(curr_max, values[i-1]+i-1);
            maxForEl[i] = curr_max;
        }
        int ans= INT_MIN;
        for(int i= 0; i<n; i++){
            ans = max(ans, maxForEl[i] + values[i]- i);
        }
        return ans;
    }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // return bruteForce(values);


        return sol2(values);
    }
};
