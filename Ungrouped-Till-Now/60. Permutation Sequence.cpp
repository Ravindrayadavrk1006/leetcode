class Solution {
    int counter = 0;
private:
    //SOL 1

    in brute force accordin to striver just to normal permutation finding and then sort the the answer in lexograpical order and return ans[k-1] 
    //simple approach [BRUTE FORCE]
    /*
        idea is simple we are trying to generate all the possible permutation till we find our answer . 
        for generating the required format of  permutation, we do normally swap the element(as in normal permutation) but for in required format we sort the elements next to the current element swapped . i.e sort from ith+1 element to end 
        on coming back if current recursion doesn't give solution , to remove the disturbance just simply replace with non sorted intial string for it before swaping and sorting save intial string in a var and replace back on backtrack step.

        for finding the asked kth permutation kept a counter var which will increment when we found a permutation. and once we find our desired solution will simply return true at the point .
    */
    bool  bruteForce(int i ,string & s, int n , string& final_ans, int k, int & inplace_counter ){
        if(i >= n  ){
            inplace_counter++;
            if(inplace_counter == k){
                final_ans = s;
                return true;
            }
        }
        //normal conditions
        
        for(int j = i; j < n ; j++){
            string temp_str = s;
            swap(s[i], s[j]);
            sort(s.begin()+i+1,s.end());
            if(bruteForce(i+1, s,n,final_ans, k,  inplace_counter))return true;
            s = temp_str;
        }
        return false;
    }
    string sol_2(int n, int k){
        string s ;
        int factorial = 1;
        for(int i = 1; i<=n ; i++){
            s+=to_string(i);
            factorial = factorial*i;
        }
        k = k -1;
        cout<<s<<" "<<endl;

        //removing the last factorial 
        factorial = factorial /n;
        int s_size = s.size();
        string final_ans ;
        while(true){
            final_ans += s[k/factorial];
            s.erase(k/factorial,1);
            if(!s.size())break;
            k = k%factorial;
            factorial = factorial/s.size();
        }
        return final_ans;
    }
public:
    string getPermutation(int n, int k) {
        //CALLING SOL 1
        /*
        string s;
        //forming initial string
        for(int i = 1 ; i<=n; i++)s+=to_string(i);
        //calling the function 
        string final_ans;
        int inplace_counter = 0;
        bruteForce(0,s, n, final_ans , k, inplace_counter);
        cout<<final_ans;
        return final_ans;

        */
        //CALLING SOL 2
        return sol_2(n, k);

    }
};
