/*
    explanation->
        since it is given it is a even length string, no need to think much about boundary condition,
        here we are using a for loop to traverse the entire string, and if s[pos] != s[pos+1] then it means that either s[pos]and s[pos+1] is 01, 10 but we need 00, 11 hence one change is required , we increment our change count , if s[pos] == s[pos+1] is same then we don't have to change anything since according to question have to have even number of 1 or 0 in even length substring.
        

        1 question in mind would be coming why not try to partition at all even length string using recursion, eg parition at length 2 and call recursive, partion at 4 and call recursive remaining,
        if we think deep the answer would be same for this approach and uselessly increasing complexity for no gains
*/
class Solution {
private:
    int ans = INT_MAX;

    //giving TLE, just done to do hands on on recursion and internal recursion
    int solBeautifulString_withreturn(int pos , string s, int changes, int n){
        cout<<pos<<" ";
        if(pos>=n){
            return changes;
        }
        //normal cases
        //given string is even length and hence no border condition checking
        if(s[pos] == s[pos+1]){
            ans = min(ans,solBeautifulString_withreturn(pos+2, s, changes, n));
        }
        else{
            ans = min(ans,solBeautifulString_withreturn(pos+2,s, changes+1,n));
        }
        return ans;
    }

    //giving TLE, recursion ,no inplace return
    
    void solBeautifulString(int pos , string s, int changes, int n){
        cout<<pos<<" ";
        if(pos>=n){
            ans = min(ans,changes);
            return;
        }
        //normal cases
        //given string is even length and hence no border condition checking
        if(s[pos] == s[pos+1]){
            solBeautifulString(pos+2, s, changes, n);
        }
        else{
            solBeautifulString(pos+2,s, changes+1,n);
        }
    }


    //SOL 3 WORKING
    //non-recursive , working sol

    int non_recursive(string s, int n){
        int my_ans = 0;
        cout<<my_ans<<" "<<n<<endl;
        for(int pos = 0; pos<n; pos+=2){
           if(s[pos] != s[pos+1]){
                my_ans+=1;
           }
        }

        //SAME CODE USING WHILE LOOP
        // int pos = 0;
        // while(pos<n){
        //     if(s[pos] != s[pos+1]){
        //         my_ans= my_ans+1;
        //     }
        //     pos+=2;
        // }
        return my_ans;
    }

public:
    int minChanges(string s) {
        int n = s.size();
        // solBeautifulString(0,s,0,n);
        // return ans;

        //calling SOL2
        //trying non-recursive
        // return solBeautifulString_withreturn(0,s,0,n);


        //calling correct SOL3
        //calling nonrecursive
        return non_recursive(s, n);

        
    }
};
