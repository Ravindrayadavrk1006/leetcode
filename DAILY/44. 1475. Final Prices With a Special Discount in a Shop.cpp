class Solution {
private:
    vector<int> naive(vector<int>& prices){
        int n = prices.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n;i++){
            //intially supposing no discout
            ans[i] = prices[i];
            for(int j=i+1; j<n; j++){
                if(prices[j]<= prices[i]){
                    ans[i]-=prices[j];
                    break;
                }
            }
        }
        return ans;
    }
//using the concept of next greater element

    /*
    
    NEXT GREATER ELEMENT:
            same below concept can be used for finding the next smaller element
            https://www.geeksforgeeks.org/next-greater-element/
            problem finding the next greater element for each element of an array,
                for example nums = [8,4,6,9,3,2,5]
                for nums[0] next greater element towards the right is nums[3] i.e 9 , for 4 it is 6 , for 9 there is none or we can say -1 , for 3 it is 5 , for 2 it is 5
            
                ans = [9,6,9,-1,5,5,-1]
            
            we will use stack to solve this problem idea-> we will traverse all the elements of the nums array and we will pop all the elements from stack which is smaller than current ith nums element , we will set their next greater element as current nums[i]
            
            algorithm -> 
                1. take a stack and insert nums[0] and initiate a  array ans =[-1,-1,-1,-1,-1,-1,-1]
                2. now run a for loop for indexe =====>   1<=ind<n
                    a. if stack is empty then insert the current ind element and continue for next ind
                    b. for every element pop all the element from stack which are smaller than nums[ind] and set their ans[ind] =  nums[ind]
                    c. push the current element i.e nums[ind] in the stack
            
    */
    vector<int> usingNextGreaterElementConcept(vector<int>& prices){

        //here the answer array is intialized with prices since that is the default value
        vector<int> ans(prices);
        int n = prices.size();
        stack<int> st;

        //pushing the first element
        st.push(0);
        //now step 2. running from ind 1 to n 
        for(int i =1; i<n; i++){
            //step 2.a , if the stack is empty push the element and check for next element
            if(st.empty()){
                st.push(i);
                continue;
            }
            //step 2.b , for current prices[i] , pop all the previous element which are smaller than the current element and substract the curremtn prices[i] from them since current value is the discount 
            while(!st.empty() && prices[st.top()]>=prices[i]){
                ans[st.top()]-=prices[i];
                st.pop();
            }
            //step 2.c push the current element
            st.push(i);
        }
        return ans;
    }
public:
    vector<int> finalPrices(vector<int>& prices) {
        // return naive(prices);

        return usingNextGreaterElementConcept(prices);
    }
};
