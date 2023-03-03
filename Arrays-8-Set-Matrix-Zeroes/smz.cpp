class Solution {
/*
1.BRUTE FORCE APPROACH -->
    we try to make the entire row and column with elements which is not present in the matrix where the element is zero , we will make in the entire row and column as that element except for where the elemnt is zero in that row or column so that we don't disturb the occances which will be later used to make that row or colmn one

2. optimized approach==>
we creae one extra row and extra col intialize all with 1 when we find a zero while trarsing the matrix we make the element in the extra row and extra colmn as 0 
after traversing and doing for all the elements 
we once again traverl the entire matrix and suppose the extra row and column is
extra row [1 0 0 0 0 ]
extra col [0 1 1 0 0]
so when traversing the matrix when we are at element suppose [1][3] we check the extra row element  if it is zero or if the extra colm index 3 is zero we make matrix [1][3] as zero

*/
//coing approach 2
private:
    void sol_2(vector<vector<int>>& matrix)
    {
        int no_rows = matrix.size();
        int no_cols = matrix[0].size();
        vector<int> extra_col(no_rows,1);
        vector<int> extra_row(no_cols,1);
        for(int i = 0; i<no_rows; i++)
        {
            for(int j = 0 ; j<no_cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    extra_col[i] = 0;
                    extra_row[j] =0;
                }
            }
        }
        for(int i = 0; i<no_rows; i++)
        {
            for(int j = 0 ; j<no_cols; j++)
            {
                if(extra_col[i] == 0 || extra_row[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    /*
        idea we are not using extra row and col space instead we are using the 0th row and 0th col to represent it
        caviat==> since [0][0] will have to represent the 0th row and 0th col then it will make a error hence we need to keep a extra cell to do this to represent the 0th row or 0th col one of these 
        here we are using a var row to represent the 0th row and 0th col will be represented by matrix[0][0]
    */
    void sol_3(vector<vector<int>>& matrix)
    {
         int no_rows = matrix.size();
        int no_cols = matrix[0].size();
        int row = 1;

        //setting value of row var
        if(matrix[0][0] == 0)row=0;
        //setting the row value by checking the 0th row
        for(int j=0 ; j<no_cols; j++)
        {
            if(matrix[0][j] == 0)row= 0;
        }
        for(int i = 1; i<no_rows; i++)
        {
            for(int j = 0 ; j<no_cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0; 
                }
            }
        }
        for(int i =no_rows-1 ; i>0; i--)
        {
            for(int j= no_cols-1; j>=0; j--)
            {
                if(matrix[0][j] == 0 || matrix[i][0]==0)matrix[i][j]=0;
            }
        }
        for(int j= 0; j< no_cols; j++)
        {
            if(row == 0)matrix[0][j]=0;
        }

    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // sol_2(matrix);

        sol_3(matrix);
    }
};
