/*
    explanation:
       just for better pictorial explanation see this explanation we have used exactly this approach 
       https://leetcode.com/problems/minimum-array-end/solutions/5083945/filling-zero-bits-visualized-step-by-step-beginner-friendly

    explanation in our own language:
        the question description is a bit too much but this is the way question will be asked so understand,
        it is asking about the largest number of increasing  n numbers whose AND will give x,


        AND has property that to make something 1 , all the bits being and shoudl be 1,

        so if given x = 4 => in binary 100  , if we want 3bit to be 1 , all the bits at this position should be 1 , so if asked n = 5 then all the 5 numbers will have their 3bit 1, in place of two zeros we can have any bit.


        so when n = 5           we can have   1 fixedand other numbers 0100,0101, 01010, 0111, 1100,
        in above if we see on removing the fixed 1, we have 100 which is 4 which is 5-1 so if we subsitute  three zeros of x  from left side with 100 then we will have our answer.





*/

class Solution {
public:
    long long minEnd(int n, int x) {
        //converting in long long since answer is required in that format
        long long num = x;
        //fyi: long long has 64 bits that's all
        //decreasing 1 from the n as per explanation this is what to be susbituted in place of leftmost zeros
        long long  to_add = n-1LL;
        //this variable will be used for keeping a track of index from last of to_add
        int pos = 0;
        //since the output is a long long hence trying for all 64 bits
        for(int i = 0; i< 64 ; i++){
            //fetching that bit
            long long  bit = (num>>i) & 1LL;
            //if that bit is zero then we will subsitute with the value of to_add bit 
            if(!bit){
                //getting the bit of number to_add
                long long tosetwith = (to_add >> pos) & 1LL;
                //we will increament the position of index of to_add
                pos++ ;
               //if tosetwith bit is 1 and current bit of num is 0 we are trying to make that bit of num 1
               //since replacing zero with zero there is no meaning
                if(tosetwith){
                    //set the ith bit of num
                    num = (1LL<<i) | num;
                }
            }
        }
        return num;
    }
};
