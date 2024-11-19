class Solution {
private:
    /*
        using sliding window algorithm
        1. in cases of k<0 and k>0 using the sliding window protocol
        2. creating the intial window size and then for proceeding as in normal cases of sliding window protocol
    */
    vector<int> slidingWindowDecrypt(vector<int>& code, int k){
        int n = code.size();
        vector<int> ans(n, 0);
        if(k== 0)return ans;
        //if k> 0 
        if(k>0){
            //creating intial window
            int window_sum = 0;
            //sum for elements of index i+1,i+2,...., i+k for first window
            for(int i = 1; i<=k; i++){
                window_sum+=code[i%n];
            }
            //storing in intial position
            ans[0] = window_sum;
            //for every ans we substract the current element and add i+k th position elemetn
            for(int i = 1; i<n; i++){
                window_sum = window_sum -  code[i] + code[(i+k)%n];
                ans[i] = window_sum;
            } 

            return ans;
        }
        if(k<0){
            //creating intial window
            int window_sum = 0;
            //converting into positive
            int required_k = abs(k);
            for(int i = 1; i<=required_k; i++){
                //n-i will give first window ith element from last in that window
                //since this is first window which is for ans[0] and the elemtns for this window are [code[n-k], code[n-k-1], code[n-k-2],...... code[n-1]]
                window_sum+=code[(n-i)%n];
            }
            //storing in intial position
            ans[0] = window_sum;
            for(int i = 1; i<n; i++){
                /*
                    logic for this n-required_k +i-1

                    n-required_k gives starting position of first window from last and i-1 gives that ith position element to remove from the starting position of first window
                */
                window_sum = window_sum + code[(i-1)%n] - code[(n-required_k +i-1)%n];
                ans[i] = window_sum;
            } 

            return ans;
        }

        //the code won't reach here,  but added to pass the function return type
        return ans;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        return slidingWindowDecrypt(code, k);
    }
};
