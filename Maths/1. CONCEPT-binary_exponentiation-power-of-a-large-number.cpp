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
