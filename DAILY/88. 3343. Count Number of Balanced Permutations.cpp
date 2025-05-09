class Solution {

//sol 1
/*
int n = 0;
int ans = 0;
*/
//sol 2
int MOD = 1e9 + 7 ;
int n = 0;
int totalSum = 0; 
long long totalPermPermutations = 0; 
private:
    //sol1 
    bool helper_balanced(string num){
        int sum_odd =0;
        int sum_even = 0;
        // cout<<num<<endl;
        for(int i =0; i<n; i++){
            //if current index is odd 
            if(1 & i)sum_odd+=(num[i]-'0');
            else{
                sum_even+=(num[i] - '0');
            }
        }
        if(sum_odd == sum_even)return true;
        return false;
    }
    //SOL 1
    void sol_permutations(int pos, string& num, set<string>& st){
        if(pos == n){
            // if(helper_balanced(num))ans++;
            st.insert(num);
            return;
        }
        for(int i =pos; i<n; i++){
            swap(num[pos], num[i]);
            sol_permutations(pos+1, num, st);
            swap(num[pos], num[i]);
        }
    }

    //SOL 2

    //our answer will be   ((n+1)/2)! * (n/2)! //if there were no duplicate elements
        /*
           (n+1)/2)! is the permutation of elments at the even place , n+1 since let's take n = 5 , then even indexes will be 0,2,4 i.e 3 and hence (5+1)/2 = 3 i.e 3 places and odd places will be 1,3  from formula also (n/2)= 5/2 = 2 

           if n = 4 then even indexes will be 0,2 from formula (4+1)/2  = 2 and for odd 1,3  from formula , (4/2 ) = 2


           now we are saying that let's say n = 5 ,   ((n+1)/2)! * (n/2)! =  total arangement,  (5+1/2) ! * (5/2)!
           now let's say there can be duplicate elements as well,
           in case of permutation when there are duplicat eelment i.e say there are n element and r duplicate elment then permutation become n!/r! 

            let's say  num = [1,2,2,2,3,2,3,3]   then if we want to find total permutations formula will be n!/(f1!)*f2!...
            i.e 6!/(4!)(3!)


            now in our case where we have to divide in odd and even places our even indices can have any number of the repeating elmeents and the remaming elements will be at odd places and hence we have to take into account


            we will be using recursion to do it,

            according to  question there will be elements from 0-9 i.e 10 elements 
            and each of these digits would have certain counts.
            eg [1,1,2,2,2,3,3]
            total sum = 14 , we want evenindex to be of sum = 7 and number of even digit will be (n+1)/2  = 8/2 = 4
            1 - 2
            2 - 3 
            3 - 3 
            now lets starting taking 

            1->1->->2->3
            2->2->3
            1->3->3

            these are valid combination we check for each digit and when we finally after checking for all the digits, if sum = half of total sum and even digit count = (n+1)/2 it means it's a valid balanced permutation then we add it in the response 



            above is the approach and solution->
            few small points factorial and 1/f!  is fermat factorial we will compute prehand

        */

    //binary exponentiation
    long long findPower(long long a, long long b){
        if(b == 0)return 1;
        long long half = findPower(a, b/2);
        long long result = (half * half)%MOD;
        //if b is odd then multiply with a
        if( 1 & b){
            result= (result*a) %MOD;
        }
        return result;
    }

    long long solve(int digit, int evenDigitCount, int  currentEvenSum, vector<int>& freq, vector<long long>& fermatFact, vector<vector<vector<int>>>& dp){
        if(digit == 10){
            if(evenDigitCount == (n+1)/2 && currentEvenSum == totalSum/2 )return totalPermPermutations; //return the numberator, if it's a balanced permutation,  else return 0;
            return 0;
        }

        if(dp[digit][evenDigitCount][currentEvenSum] != -1 )return dp[digit][evenDigitCount][currentEvenSum];

        long long ways = 0;
        for(int count =0; count<=min(freq[digit], (n+1)/2 - evenDigitCount); count++){
            //count no of frequency of current digit will be at even positions
            int evenPosCount = count;
            //freq[digit] - count at even places, counts of this digit will be at odd places
            int oddPosCount = freq[digit]- count;
            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])%MOD;
            long long val = solve(digit+1, evenDigitCount + evenPosCount, currentEvenSum+ evenPosCount*digit, freq, fermatFact, dp) %MOD;
            ways = (ways + (div* val)%MOD)%MOD;
        }
        return dp[digit][evenDigitCount][currentEvenSum] = ways;
    }
public:
    int countBalancedPermutations(string num) {



        //SOL 1

        //brute force appproach
        /*
            we are generating all the permutation and saving in a set to store only unique permutation and then for each permutation checking if it is balanced or not, if it is balanced then it's a valid permuation 
        
        */
        /*
        int total_sum =  0;
        for(char c: num){
            total_sum+=(c-'0');
        }
        if(1 & total_sum)return 0;
        n = num.size();
        set<string> st;
        sol_permutations(0, num, st);
        for(auto el: st){
            if(helper_balanced(el))ans++;
        }
        return ans;
        */


        //SOL 2
        //this solution from https://www.youtube.com/watch?v=_9YlLoFT8JQ
        n = num.size();
        //counting the frequency of each element
        vector<int> freq(10,0);
        for(int i =0; i<n; i++){
            freq[num[i]- '0']++;
            //totalSum is a global variable
            totalSum+=(num[i]- '0');
        }
        //if totalsum is odd, then answer is not possible
        if(1 & totalSum)return 0;
        

        //precompute factorial
        vector<long long > fact(n+1,1);
        fact[0] =1;
        fact[1] = 1;
        for(int i =2; i<=n;i++){
            fact[i] = (fact[i-1]*i)%MOD;
        }
        //fermat factorial or inverse factorial
        vector<long long > fermatFact(n+1, 1);
        for(int i=0; i<=n; i++){
            //findPower is the function for finding power of very large number 
            fermatFact[i] = findPower(fact[i], MOD - 2 ) % MOD;
        }
        totalPermPermutations = (1LL * fact[(n+1)/2]* fact[n/2]) %MOD;
        int digit = 0;
        int evenIndexDigitsCount = 0;
        int currSum = 0;

        //adding memoization, since gives TLE
        //since there are three changing variables hence dp
        vector<vector<vector<int>>> dp(10, vector<vector<int>>((n+1)/2 + 1, vector<int>(totalSum +1 ,-1)));
        return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, dp);
    }
};
