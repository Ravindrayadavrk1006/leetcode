class Solution {
private:
    const int MOD  = 1e9 + 7;
    //SOL 1, O(1)
    int good_number_brute_force(long long n){
        // string s = to_string(n);
        // int digit_count = s.size(); 
        long long ans = 1;
        for(int i = 0; i<n; i++){
            //if current index is odd
            if((i & 1) == 0){
                ans*=5;
               
            }
            else{
                ans*=4;
            }
            ans%=MOD;
        }
        return ans;
    }

    //SOL 2
    //GIVING TLE 

    //this is good but of no use, since giving TLE
    int recursive(long long n){
        //5*4*5 = 100
        if(n == 3)return 100;
        if(n == 2)return 20;
        // if(dp[n] != -1)return dp[n];
        long long left = n>>1;
        long long right = n - left;
        int mult_left = 1, mult_right = 1; 
        //when n is divided by 2 and if both the output are odd it means we have to adjust one 
        //if half value is odd, if left is odd then right also will be odd, take pen and paper and observe it 
        if((left&1) == 1){
            mult_left = 5;
            mult_right = 4;
            left-=1;
            right-=1;
        }
        long long left_recursive = recursive(left);
        left_recursive*=mult_left;
        left_recursive%=MOD;
        long long right_recursive = recursive(right);
        right_recursive*=mult_right;
        right_recursive%=MOD;
        return (left_recursive*right_recursive)%MOD;
    }

    //this is major and only thing that is being done
    //using bitwise to do a^b

    /*
        below exponent is using the concept of

        a = 3 b = 4
        3^4  =   (3^2)^2  = 9 => 9^2 == (9^2)^1

        i.e we are doing half of current raised power and in the bracket raising the inner number by 2
        also important thing when something like a = 5 b = 11 , i.e the power is odd
        then we    5^11 =    5*(5^2)^5  i.e we half the b and a is raised by 2 and outer is multiplied by a 

        in below cases we are doing the same, 


        refer to this solution for below code and entire code solution
        https://www.youtube.com/watch?v=y_XVeVUpdP4&t=21s
    */
    //T.C log(N)
    int get_exponent(long long a, long long b){
        long long ans = 1 ;
        //while b is not 0
        while(b >0){
            //if b is odd, then we need to mutlipy ans with current a
            if(b&1){
                ans*=a;
                //MOD is being done to avoid it not crossing the limit, ALL the MOD line in this function are not part of original exponent
                ans%=MOD;
            }
            //below line denotes a^2
            a*=a;
            a%=MOD;
            //b get's divided by half 
            b = b>>1;
        }
        return ans;
    }
    //SOL 3
    /*
        concept being used below
        filling the positions 
        even positions can be filled with 0,2,4,6,8 i.e by 5 numbers
        odd positions can be filled with 2,3,5,7 i.e by 4 numbers

        if n = 2  answer , Oth position will be occupied by 5 ways, 1th i.e odd position can be occupied by 4 ways hence answer = 5*4
        this also implied if n is even then ans will be  (5*4)^n/2  because half of them will be odd half of them will be even    simply put (5^n/2) * (4^n/2)


        if n is odd eg 3 then answer will be 5*4*5    , i.e Oth position 5 possibility, 1th position 4 possiblilty 2nd position 5 possibility
        in same fashion all odd will work and hence we can say if n is odd then
        eg. n =5    =>   (5*4)^n/2 * 5        5 is for the last index

        in below same is being done
    
    */
    int sol_from_neetcode(long long n){
        //mult is the number that get multipled finally in case of n is odd it is 5 and in case of n being even nothing get multipled hence it is 1
        int mult = 1;
        if((n & 1)== 1){
            //get half of n
            mult  = 5;
        }
        //below doing  5^n/2 * 4^n/2
        long long half = n>>1;
        //getting 5^(n/2)
        cout<<"half "<<half<<endl;
        long long exp_5 = get_exponent(5,half);
        cout<<exp_5<<endl;
        //getting 4^(n/2)
        long long exp_4 = get_exponent(4,half);
        cout<<exp_4<<endl;
        long long ans = (exp_5*exp_4)%MOD;
        return (ans*mult)%MOD;
    }
public:
    int countGoodNumbers(long long n) {
        // return good_number_brute_force(n);
        // if( n ==1 )return 5;
        // vector<long long> dp(n+1, -1);
        // return recursive(n);


        return sol_from_neetcode(n);
    }
};
