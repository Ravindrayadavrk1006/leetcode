class Solution {
    /*
        APPROACH 1--> brute force 
            make a extra matrix of given size and copy the first row in last column ans second row in second last column i.e 
            the row will become column no -> totalcol-1 -row
        this uses a extra space of O(N*2)

        APPROACH 2-->
        we do transpose of the matrix and then reverse the row't element
        eg 
        given matrix 
        1 2 3
        4 5 6
        7 8 9  
        it's transpose -->
        1 4 7
        2 5 8
        3 6 9 

        final ans will be reverse of each row of the transpose matrix


    */
private:
    void approach_2(vector<vector<int>> &matrix)
    {
        //doing transpose
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        //generating transpose of matrix
        for(int i = 0; i<row_count; i++)
        {
            for(int j= 0; j<col_count; j++)
            {
                //since swapping all the elemnt of the matrix will give back the same matrix hence only swapping the lower half of matrix with the upper half
                if(i>j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        //reversing each row
        for(int i = 0; i<row_count; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        approach_2(matrix);
    }
};
