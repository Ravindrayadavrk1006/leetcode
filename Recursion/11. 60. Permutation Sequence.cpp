#include <bits/stdc++.h>

using namespace std;
class Solution {
    int counter = 0;
private:
    //SOL 1

    //in brute force accordin to striver just to normal permutation finding and then sort the the answer in lexograpical order and return ans[k-1] 
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
            //we are storing the original string so that when we are back after doing the recursion we can proceed with original string
            //i.e remove the disturbance
            string temp_str = s;
            //normal swap
            swap(s[i], s[j]);
            //we want the answer in lexicographical order hence sort the remaining elements 
            sort(s.begin()+i+1,s.end());
            //wherever we find the answer we return from there
            if(bruteForce(i+1, s,n,final_ans, k,  inplace_counter))return true;
            s = temp_str;
        }
        return false;
    }
    /*
    
        appraoch suppose we want to find the k = 17th permuation of n = 4 ie 1234
        permutation range -> 
            starting with 1 (234)  -> 6 permutations   index 0-5
            starting with 2 (134)  -> 6 permutation    index 6-11
            starting with 3 (124) -> 6 permutations   index 12-17
            starting with 4 (123)  -> 6 permutations   index 18-23

            we want 17th which means 16th in 0 based indexing
            we will go to factorial 1-3 =>  6  fact = 6
            index value = 16/6  = 2  i.e 2index element ie from 1234  -> take 3 
            now remainng string to choose from will become (124)  and k will become 16%6 i.e 4 => from 124 elements permutations we need 4th permuation in 0 based indexing 
            lets proceed now k = 16%6 = 4 , fact = 6/string.size() = 6/3 = 2  this tells how many element will be there in each permutation set
            since    starting 1 (24)  -> 2 elemnt
                     starting with 2 (14) -> 2 element
                     staring with 4 (12) -> 2 element
            we want 4th pemutation in this
            4/fact = i.e 4/2 = 2 i.e 2index elemnt from (124) => i.e 4 

            now string will become = (12) , k will become => k%fact =  4%2 = 0 and fact = fact/str.size()  i.e 2/2 = 0;
            0/0 => 0 and we take 1  so our answer till nwo become 341 
            string becomes 2 , k becomes k%fact = 0%0 = 0, fact = 0/1(i.e string.size()) = 0
            now take 0/0 i.e 0 i.e take 2 and our asnwer become 3412 and string become {} empty and therefore no elemnts to take and hence we break and return tha answer
    */
    string sol_2(int n, int k){
        string s ;
        int factorial = 1;
        for(int i = 1; i<=n ; i++){
            //forming the string
            s+=to_string(i);
            //calcluating the initial fact
            factorial = factorial*i;
        }
        //k in 0 based indexing
        k = k -1;
        cout<<s<<" "<<endl;

        //removing the last factorial i.e doing fact = fact/string.size()
        factorial = factorial /n;
        int s_size = s.size();
        string final_ans ;
        while(true){
            //add k/fact element in the asnwer
            final_ans += s[k/factorial];
            //remove the k/factorial chracter from s
            s.erase(k/factorial,1);
            //if at any moment after erasing the s becomes 0 break
            if(!s.size())break;
            //k will become k%fact explained above
            k = k%factorial;
            //fact will become fact/s.size
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
