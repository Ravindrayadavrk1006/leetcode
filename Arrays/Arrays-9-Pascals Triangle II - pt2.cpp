class Solution {
public:
    /*
    concept --> for finding the element at Rth row and Cth column 
    formula used in pascals tria
    in 1 base indexing  [r][c] element will be r-1
                                                 C
                                                  c-1
    that is combination value at the r-1 and c-1 

    */
    int combination(int n, int c)
    {
        //calculating nCc ie nCr
        if(c == 0 || c ==1)return n;
        int top = 1;
        for(int i =n; i>n-c; i--)
        {
            top=top*i;
        }
        int  bottom = 1;
        for(int i = c; i>1; i--)
        {
            bottom = bottom*i;
        }
        return top/bottom;
    }
    void sol(int rowIndex, vector<int> & ans)
    {
        ans.push_back(1);
        int count = rowIndex+1;
        int times = count -2  ;
        int pos = rowIndex+1;
        for(int i =1 ; i<=rowIndex-1 ; i++)
        {
            pos = pos-1;
            long long temp = (long long )ans[i-1]*pos/i;
            ans.push_back((int)temp);
        }
        ans.push_back(1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0)
        {
            ans.push_back(1);
            return ans;
        }
        sol(rowIndex,ans);
        return ans;
    }
};
