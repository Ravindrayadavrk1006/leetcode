class Solution {

    /*
        idea -->
        1 . first we try to check if the strings are valid or not
        for it we try to check while counting each element we try to check if a char appearing after a char eg . as r should appear before o we check if the count of 'o' is not greater than count of r. 
        done this so the oder of character is maintained
        2. finally the counts of each character should be same so checking that too 
        if either of 1 or 2 doesn't satisfy then the string is invalid

        once we have found that the string is valid:
        we try to check the  max_crocks required for it used the concept of count of platforms
        we increase the value of count var when we encounter a 'c' and  update the value of max_count if count val is greater than max_count . we decrement value of count when we encounter a k
    
    */
public:
    int sol(string str)
    {
        int n = str.size();
        unordered_map<char,char> before;
        before['r']='c';
        before['o']='r';
        before['a']='o';
        before['k']='a';
        unordered_map<char,int> count;
        for(int i = 0; i<n; i++)
        {
            count[str[i]]++;
            if(before.find(str[i]) != before.end() && count[str[i]] > count[before[str[i]]])return -1;
        }
        if (count['r'] != count['c'])return -1 ;
        if(count['o'] != count['r']) return -1;
        if(count['a'] != count['o']) return -1;
        if(count['k'] != count['a']) return -1;
        int counts=0;
        int max_count = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(str[i] == 'c')
            {
                counts++;
                if(counts>max_count)max_count = counts;
            }
            if(str[i]=='k')counts--;
        }
        return max_count;

    }
    int minNumberOfFrogs(string croakOfFrogs) {
        return sol(croakOfFrogs);
    }
};
