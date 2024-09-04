class Solution {
public:
    /*simple solution try by taking two string eg. s =  babgag  t= bag 
    lets start to match from (s_index , t_index) = (0,0)  the opposite of this is followed in the question we matched s[s_index] == t[t_index] we could take this b or we can skip this b and later on take b at s_index 2 and one answer we will get from there
    but if the char are not matching that means we have to look for the required char in the remaining s string skipping the current char since it didn't match and hence of no use .
     
    */
    int help(int i, int j, string & s , string & t, vector<vector<int>>& dp)
    {
        //base case
class Solution {
public:
    /*simple solution try by taking two string eg. s =  babgag  t= bag 
    lets start to match from (s_index , t_index) = (0,0)  the opposite of this is followed in the question we matched s[s_index] == t[t_index] we could take this b or we can skip this b and later on take b at s_index 2 and one answer we will get from there
    but if the char are not matching that means we have to look for the required char in the remaining s string skipping the current char since it didn't match and hence of no use .
     
    */
    int help(int i, int j, string & s , string & t, vector<vector<int>>& dp)
    {
        //base case 
        if(j < 0 )return 1;
        if(i < 0)return 0;
        //normal cases
        /*if the current element is matching, for counting we might consider this occurance of that char or we will say we won't take this we will take other occurance of this char hence trying to try  all the possible occurance for formining the string
        eg.s =  babgag  t= bag 
        suppose we standing at last g in both in s we may take this g or we might ignore and try to get the g at third last position hence trying all the possibilities
*/      if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j])
        {
            //getting all the sums
            int take = help(i-1,j-1,s,t, dp );
            int not_take = help(i-1,j,s,t, dp );
            return dp[i][j] =  take + not_take;
        }
        //if the current char doesn't match then just one possibility of trying in the remaining portion to find the char
        return dp[i][j] = help(i-1,j,s,t, dp);
    }
    //SOLUTION 2
    int tabulation(string s , string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        //since even long long  giving out of flow hence storing in form of double and when returing typecasting as int back
        vector<vector<double>> dp(s_size+1,vector<double>(t_size+1,0));
        //convert base case into normal cases
        //saying if j == 0 we make the element as 1
        for(int i= 0 ;i<=s_size; i++)dp[i][0]=1;
        for(int i = 1; i<= s_size; i++)
        {
            for(int j = 1;j<=t_size; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    //getting all the sums
                    dp[i][j] =  dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[s_size][t_size];
    }
    int numDistinct(string s, string t) {
        //solution 1 calling
        int s_size = s.size();
        int t_size = t.size();
        vector<vector<int>> dp(s_size,vector<int>(t_size,-1));
        return help(s_size-1,t_size-1,s ,t, dp); 
        
        //solution 2 tabulation 
        //CALLING SOLUTION 2;
        return tabulation(s,t);
    }
};
        //if while finding we finished the j i.e string to be matched then we found one match
        if(j < 0 )return 1;
        //if the main string in which the string is to be searched get exhausted it means we didn't find 
        if(i < 0)return 0;
        //normal cases
        /*if the current element is matching, for counting we might consider this occurance of that char or we will say we won't take this we will take other occurance of this char hence trying to try  all the possible occurance for formining the string
        eg.s =  babgag  t= bag 
        suppose we standing at last g in both in s we may take this g or we might ignore and try to get the g at third last position hence trying all the possibilities
*/      if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j])
        {
            //getting all the sums
            //left is take since we took the element and there for j-1
            int left = help(i-1,j-1,s,t, dp );
            //don't take the element and look in the remaing part
            int right = help(i-1,j,s,t, dp );
            return dp[i][j] =  left + right;
        }
        //if the current char doesn't match then just one possibility of trying in the remaining portion to find the char
        return dp[i][j] = help(i-1,j,s,t, dp);
    }
    int numDistinct(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        vector<vector<int>> dp(s_size,vector<int>(t_size,-1));
        return help(s_size-1,t_size-1,s ,t, dp);   
    }
};
