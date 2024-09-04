
/*
  using the concept of print lcs i.e 38th question in dp solutions here in github,
  since we want a superstring so we need all the characters which do not match as well apart from those that are matched, when a character is not matched we take the element which is greater in value of either since our solution is coming from that direction 
  and if we draw the recursion tree we will understand more

*/
class Solution {
public:
//also we can't take the approach of finding the lcs only and then substracting the lcs from first and taking the remaining element of first string + second string since the order of subsequence will be disturbed
    string tabulation(string text1, string text2)
    {
        int text1_size = text1.size();
        int text2_size = text2.size();
        vector<vector<int>> dp(text1_size+1, vector<int>(text2_size+1,-1));
        //by seeing the base case in shiftindex make all 0 row and 0th column 0 
        for(int pos2 = 0 ; pos2<= text2_size; pos2++)dp[0][pos2]= 0;
        //making the 0th column elements as zero
        for(int pos1= 0 ; pos1<= text1_size; pos1++)dp[pos1][0]= 0;
        //normal case
        //copy the remaining logic of above
        for(int pos1 = 1 ;pos1<=text1_size; pos1++)
        {
            for(int pos2= 1; pos2<=text2_size; pos2++)
            {
                if(text1[pos1-1] == text2[pos2-1])
                {
                    dp[pos1][pos2] = 1 + dp[pos1-1][pos2-1];
                }
                else
                {
                    dp[pos1][pos2] = max(dp[pos1-1][pos2],dp[pos1][pos2-1]);
                }

            }
        }
        /*
         here we are tyring to print the supersequence using the table of lcs
         once we have the lcs table
         concept used
         eg. brute groot
         we standing at last position 5 since shifting of index done we check if the current char is same if yes we take the char once , if the char's are not equal then we compare which is larger the comparision done between (pos1-1,pos2) and (pos1,pos2-1) element in dp suppose (pos1-1,pos2 ) element is bigger we have to move at that position which states the left dp element (visualize in the dp table) which was smaller will be left out of comparision since the part left for comparision will be text1[pos1-1-1](since we have done shifiting of index and if standing at position pos1-1 then element in text will be equivalent pos1-1-1) and in text2[pos2] hence we take the text1[pos1-1] element similarly if we move left then oppsite element is taken into consideration.

        */
        string sup_seq = "";
        int pos1 = text1_size;
        int pos2 = text2_size;
        while(pos1 >0 && pos2>0)
        {
            if(text1[pos1-1] == text2[pos2-1])
            {
                sup_seq = text1[pos1-1] + sup_seq;
                pos1--;
                pos2--;
            }

            
            else if(dp[pos1-1][pos2]>dp[pos1][pos2-1])
            //up wala bda then since the left wala element will leave out for further comparison hence let's take it
            {
                //this part is different from print lcs
                sup_seq = text1[pos1-1] + sup_seq;
                pos1--;
            }
            else
            //leftward movement
            {
              // this below line is different from print lcs
                sup_seq = text2[pos2-1] + sup_seq;
                pos2--;
            }
        }
        if(pos1 == 0)
        {
            while(pos2>0)
            {
                sup_seq = text2[pos2-1] + sup_seq;
                pos2--;
            }

        }
        else 
        {
            while(pos1>0)
            {
                sup_seq = text1[pos1-1] + sup_seq;
                pos1--;
            }
        }
        return sup_seq;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string ret_lcs = tabulation(str1,str2);
        return ret_lcs;
    }
};
