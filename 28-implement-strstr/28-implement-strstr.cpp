class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength=haystack.length();
        int needleLength=needle.length();
        if(needleLength==0)return 0;
        if(haystackLength==0)return -1;
        //traversing the haystack to find the first position of element same as first position
        //of our needle
        int i=0;
        while(i<haystack.length())
        {
            if(haystack[i]==needle[0] && haystackLength-i>=needleLength )
            {
                if(haystack.substr(i,needleLength)==needle)
                {
                    return i;
                }
            }
            i++;
        }  
        return -1;
    }
};