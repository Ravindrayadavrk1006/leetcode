important =>
if have to traverse till certain length of original string
=> for(int i=0;i<largerStringLength-smallerStringLength;i++)
**used the idea of replacting substring by a loop for matching character by character from that position**
​
int strStr(string haystack, string needle)
{
int n = haystack.size();
int m = needle.size();
​
if (m == 0)
return 0;
​
int i = 0, j = 0;
​
for (i = 0; i < n; ++i)
if (haystack[i] == needle[0])
{
for (j = 1; j < m; ++j)
if (haystack[i + j] != needle[j])
break;
​
if (j == m)
return i;
}
​
return -1;
}