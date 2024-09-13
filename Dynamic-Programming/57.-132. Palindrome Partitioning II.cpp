class Solution {
    /*explanined well in the note as heading FRONT PARITION
    we try to find the palindrome from start for the current str we try to find all the palindrome from start and solve the remaining part recursively .
    from all the palindromic parition we have made we try to find the one which has minimum no of parition 
    eg for partition bababcbadcede 
    we can partition as b(ababcbadcede), bab(abcbadecede), babab(cbadcede)
    no other part from front form a palindrome the so we count the palindrome as one and give recursion to solve the part in bracket in each case 
    we return the minimum no of partition out of all the above three ways
    
    */
private:

    //functino to find if current str is palindrome
    bool isPalindrome(string & front_str)
    {
        int i = 0;
        int j = front_str.size()-1;
        while(i<j)
        {
            if(front_str[i] != front_str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    /*
    int sol(int i,int n ,string & str,vector<int>& dp)
    {
        //since in each case when recursion is called the i values is increasing so keeping a base base if i==n hence no more recursion required
        if(i==n)return 0;

        //normal cases
        if(dp[i] != -1 )return dp[i];
        //running a for loop for finding the string from front if that is a palindrome if yes we can explore this path further recrusively
        int min_count = 1e9;
        //this variable store the value of current front string
        string front_str  = "";
        for(int j = i; j<n ; j++)
        {
            //since we are running this loop linearly then the front_str will get the string
            front_str+=str[j];
            if(isPalindrome(front_str))min_count = min(min_count,1+sol(j+1,n,str,dp));
        } 
        return dp[i] = min_count;
    }
    */


    /*
        rules for converting a recursive sol to tabulation
        1.replicate the base case i.e here fill dp[n] = 0;
        2. reverse the start i.e there i ->0 to n-1 here i->n-1 to 0
        3.copy the remaining part
    */
    int tabulation(string & str)
    {
        int n = str.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            int min_count = 1e9;
            //this variable store the value of current front string
            string front_str  = "";
            for(int j = i; j<n ; j++)
            {
                //since we are running this loop linearly then the front_str will get the string
                front_str+=str[j];
                if(isPalindrome(front_str))min_count = min(min_count,1+dp[j+1]);
            } 
            dp[i] = min_count;
        }
        return dp[0];
    }
public:
    int minCut(string s) {
        //sol function will return the min no of palindrome since we need min no of partition which is equal to no.of palindrome-1
        // vector<int> dp(s.size(),-1);
        // return sol(0,s.size(),s,dp)-1;    



        //calling the tabulation 
         //tabulation function will return the min no of palindrome since we need min no of partition which is equal to no.of palindrome-1
        return tabulation(s)-1;
    }
};
