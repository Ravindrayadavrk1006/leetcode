class Solution {
private:
    /*
        NOTE -> * is xor here
        since all the node are connected we can do zero of ANY of two nodes any two nodes 
            reason -> let's say     we want to xor node 4 and 6 we can do it  4 * 2 * 2 * 1*1*3*3*6   and since xor of same elements is zero hence only thing that remain is xor of 1*6, because of this we can xor any two node
              1
            /  \
           2    3
        /   \   /  \
     4      5  6    7

        now let's say we will xor for all the nodes and wherever the value is increasing we will save in a vector. 
        we will sort the vector and since the xor will always happen in pair from above understanding and also given in the question. hence we will be able to add only total even count xor.

        forming answer ->
            we will have a counter which will count the number of places where zero increases the value, and we will have a variable where increased xor value if increasaes, if it decreases then we will add current value and also we will store  in a variable which will store the minimum decrement. 

     
    */

    /*
    
        LEARNINGS ->
            1. xor of  a*a = 0, 0*a = a
            2. in a tree if we can xor edge nodes any number of times then we can xor any two nodes, without any second thought and that value will be a*b i.e those two node value 

            as shown in above explanation -> because a*b * b*c = a*c  => which states all the nodes in between will become zero since a*b = 0

    
    
    */
    long long ans_using_xor_property(vector<int>& nums, int k, vector<vector<int>>& edges){
        using ll = long long;
        ll minimum_loss = (ll)INT_MAX;
        ll ans = 0 ;
        int total_values_xored = 0;
        for(int el: nums){
            ll xored_value = el^k;

            //xor value is greater than the original element then we store the xored_value
            if(xored_value > el){
                total_values_xored++; 
                ans+=xored_value;
            }
            //if xor doesn't give greater value then we take the original value
            else{
                ans+=el;
            }

            //we are storing the minimum loss, minimum loss will be close to zero
            /*
                     //it is outside the else part since let's say
                     let's say xor increments(not the final xor values) are 1 4 1  3 
                     but the decrement are 5 8 14 45 i.e all are greater than the increment, so if we had put it in else block then minimum_loss value would be 5, but if we had put this outside the else part then it would be 1 which says that's we remove the increment that's why it's outside
            */
            minimum_loss = min(minimum_loss, abs(el - xored_value));
            
        }    

        if((total_values_xored & 1) == 0)return ans;
        return ans - minimum_loss;    
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        return ans_using_xor_property(nums, k, edges);
    }
};
