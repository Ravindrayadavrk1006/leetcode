Intuition
we know for log base 2 n i.e log(n)/log(2) we require single 1 . for ex. n = 9 we get log(n)/log(2)= 3 for it we get single 1 and further we subtract n = n-pow(2,log(n)/log(2)) and call the recursive funciton with this n value since for ex. 12 can be written as 8+4 in terms of multiple of 2 hence we do log12/log 2 = 3 which gives single 1 and further in next call 12-2^3 = 4 for log 4 /log2 gives 2 and sinlge 1 here too . and in next call 4- 2^2 gives 0 and 0 return no 1
hence total one's 1+1

Complexity
Time complexity:
O(nlogn)

Space complexity:
O(n)

Code
class Solution {
public:

    int help(int n , vector<int>& ans)
    {
        if(n==0)return 0;
        else if(n==1)return 1;
        if(ans[n] != -1 )return ans[n];
        int x = log(n)/log(2);
        // int a = count++;
        return ans[n] = 1 + help(n - pow(2,x), ans); 
        
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=help(i, ans);
        }
        return ans;
    }
};
