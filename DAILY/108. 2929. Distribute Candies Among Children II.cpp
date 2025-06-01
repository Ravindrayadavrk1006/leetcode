typedef long long ll;
class Solution {
private:
    //SOL 1
    //recursive apporach 
    //TLE
    //O(n^3)
    ll recursive(int pos, int curr_n, int limit, string& curr_str){
        if(pos == 2){
            if(curr_n>=0 && curr_n<= limit)return 1;
            return 0;
        }
        long long ans = 0;
        //min taken since let's say curr_n = 5 and limit = 10 then it's useless to go till 10
        for(int i=0; i<=min(limit, curr_n); i++){
            //
            if (curr_n -i < 0)break;
            curr_str.push_back(i+'0');
            ans+=recursive(pos+1,curr_n-i, limit, curr_str);
            curr_str.pop_back();
        }
        return ans;
    }

    //SOL 2
    //Iterative approach
    //GIVING TLE
    //O(n3)
    ll sol_iterative(int n , int limit){
        ll ways = 0;
        //min being taken since let's suppose limit = 1000 but n = 10 then we have chance to take from 0 to 10 only not till limti
        for(int ch1=0; ch1<=min(limit, n); ch1++ ){
            //max done so that when we have don substaction it doesn't become negative
            for(int ch2 =0; ch2<=min(limit,max(0, n-ch1)); ch2++){
                for(int ch3 =0; ch3<= min(limit, max(0, n-ch1-ch2)); ch3++){
                    if(ch1+ch2+ch3 == n)ways++;
                }
            }
        }
        return ways; 
    }

    /*
        improving on sol_iterative 

        in the final we are doing the for loop which is not required
        we can straigt take ch3 = n - ch1-ch2  ===>> if ch3 is in limit then it's a answer

    
    */
    //SOL 3
    //O(n^2)
    //TLE
    ll improvement_sol_iterative(int n , int limit){
        ll ways = 0;
        //min being taken since let's suppose limit = 1000 but n = 10 then we have chance to take from 0 to 10 only not till limti
        for(int ch1=0; ch1<=min(limit, n); ch1++ ){
            //max done so that when we have don substaction it doesn't become negative
            for(int ch2 =0; ch2<=min(limit,max(0, n-ch1)); ch2++){
                //ch3 will become n - ch1 - ch2
                int ch3 = n - (ch1+ ch2);
                //checking if ch3 is a valid range i.e [0, limit]
                if(ch3>=0 && ch3<= limit)ways++;
                
            }
        }
        return ways; 
    }

    //SOL 4
    //WORKING solution 
    //O(N)
    /*
        apporach ->
            let's say we have been given n=5 and limit = 4
            and we just have two children 1 and 2
            let's forget the limit for now and say we have n = 5 sweets and we have to distribute between two child
                      ch1       ch2
    no of sweets      0         5-0
                      1         5-1
                      2         5-2
                      3         5-3
                      4         5-4
                      5         5-5 

        to explain a row we are saying if we give 0 candies to ch1 then ch2 can have 5 total candies - candies give to ch1 i.e 5-0 = 5

        total ways of distribution    5-0 + 1 i.e 6 ways   formlua maxch1 - minch1 +1      
        i.e max candies that can be given to ch1 - min candies that can be given to ch1 +1

        now let's say we have limit= 4 also the distrution will be 

        ch1         ch2
        0           5-0 = 5 which is not valid because we can give max 2   (invalid)
        1           5-1 = 4 valid
        2           5-2 = 3   valid
        3           5-3= 2    valid 
        4           5-4 = 1   valid
        5           5-5 = 0   invalid 

        if we look closes the minimum valid value for ch1 =   n- limit  = 5-4  = 1
        maximum valid for ch1  = limit i.e 4
        also in upper case case where there was no limit minch1 = n - limit = 5-5 = 0
        maxch1 = limi i.e 5 since we can go till 5 hence we can say 5 is limit


        this formulat explantion in depth 
        minCh1 we are saying that we will give maximum to ch2 and n- maxCh2 i.e  n - limit will be maxCh1
        minCh1 we are saying that we can give max limit to ch1


        now let's talk about when we have three children we can extend the same for three children how let's talk

        minCh1 = n-  2* limit  = 5- 2*4  = 1 
        maxCh1 = limit = 4 
        ch1 can run from 1 to 4 and le't say when ch1 = 1 then for ch2 and ch3 we will have value n-ch1 to be distributed among them  
            now N = n - ch1 and we have just two children to distribute ch2 and ch3 and we can do in same way as if the problem was of two childrens
    */
    ll sol4_optimal(int n, int limit){
        ll ways = 0;
        //this because n could also be less then limit then we will go till min of two
        int maxCh1 = min(limit, n);
        //max (0, ) being done so that it doesn't go below 0 
        //also 2* being done because to get min value we are giving maximum values to ch2 and ch3
        int minCh1 = max(0, n - 2*limit);
        for(int ch1 = minCh1; ch1 <= maxCh1; ch1++){
            //for c2 and c3 the value will be
            //since substraction is being done therefore taking the base value in consideration  
            int N = max(0, n - ch1);
            //now calculating no of ways we can distribute between two child by using the same formula
            //just limit substraction since there is just one child ch3 apart from ch2
            int minCh2 = max(0, N- limit);
            int maxCh2 = min(N, limit);
            int curr_count = (ll)maxCh2- minCh2 + 1;
            ways+= curr_count ;

        }

        return ways;
    }   
public:
    long long distributeCandies(int n, int limit) {
        // if(n/limit > 3)return 0;
        // string curr_str = "";
        // return recursive(0,n, limit, curr_str);   

        // return sol_iterative(n, limit);

        // return improvement_sol_iterative(n, limit);

        return sol4_optimal(n, limit);
    }
};
