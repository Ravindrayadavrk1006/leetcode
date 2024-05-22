/*
  question link : https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-e
    explanation: simple dijkstra algorithm
    here we have to do mulitplication and since no of steps increase by one so already will be in sorted order so use normla queue
    
    
    here we are using steps array as dist array , we are having 100000 elements since we will try for all elements less than that and count the steps
    
    eg if arr = {2,5,7}
        and current queue element is {0,3} it means in zero steps we got multiplicatino value 3
        (1,3*2) , (1,3*5), (1,3*7)
        and then further when processing 1,3*2
        we will try for elements
        (2,3*2*2), (2,3*2*5), (2,3*2*7)
        
    
*/
class Solution {
  private:
    
    int sol_min_steps(vector<int>& arr, int start, int end){
        int mod  = 100000;
        //intialize for each number possible which can occur after mutliplication and modulus with INT_MAX , this will keep a track of number of stps
        vector<int> steps(mod,INT_MAX);
        steps[start] = 0 ;
        if(start == end)return 0;
        queue<pair<int,int>> q;
        //step taken to reach multiplcation value , mutliplication value
        q.push({0,start});
        while(!q.empty()){
            int steps_taken = q.front().first;
            int current_mult_result = q.front().second;
            q.pop();
            //mutliply current multiplication value with all the values of arr
            for(int el: arr){
                int val = (el* current_mult_result)%mod;
                int steps_to_reach_val_mult_value = steps_taken +1 ;
                if(steps_to_reach_val_mult_value < steps[val]){
                    //if we reach the required result and since already checked steps_taken +1 is less than steps[el] values
                    if(val == end)return steps_to_reach_val_mult_value ;
                    q.push({steps_to_reach_val_mult_value, val });
                    steps[val] = steps_to_reach_val_mult_value;
                }
            }
        }
        return -1 ;
    }
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        return sol_min_steps(arr,start,end);
    }
};
