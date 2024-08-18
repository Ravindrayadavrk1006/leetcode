/*
    explanation:
        eg. 25
        for it 1*1 2*2 3*3 4*4 5*5 6*6 7*7 8*8 9*9
        the answer would be 5 since 5*5 is 25 and it also tells that the answer won't lie in range 6*6 and above and hence in a way telling the search space, we can use the concept of binary search to find the answer
        also if x = 28 then also answer returned will be 5 since 6*6 is 36 and hence lower answer is returned.
        also when using binary search the search space would be 
        from 1 to 25 in above question because  x lies in range 1*1 and 25*25 


        ***important point:-
            here important point is how we decided the range of answer, we would be facing questions where range of answer will be search space and that we need to figure out what could be 
            range of anwer.
            like here we find out our answer will lie in range 0 to x since  given x  is in range 0*0 to x*x at max we would also try till x/2 
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        int low = 0;
        int high = x;
        int ans = INT_MIN;
        while(low<=high){
            long long  mid = (low + high)/2;
            //either smaller or it will be equal to x it means if smaller then could be a possible answer and if equal yes could be answer so we update the answer and try to find bigger answer which could satisfy the value
            if(mid*mid <= x){
                ans = mid;
                low = mid + 1 ;
            }
            //the answer could lie in left
            else{
                high = mid-1;
            }
        }
        return ans;

    }
};
