/*
    Basic Problem of traversing a matrix

    since here asked to set the row and column which have any value set to 0.
    once we found a element to be zero, we are storing it's row, column number in sets. we are using set so that we don't have to set this again and again.
    we are using two set -> one for storing the row and one for storing the column 

    finally we are setting all the elements of the row and col to be 0

*/
class Solution {
private:
    void set_row_col_zeros(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        //below sets store the row and column to store which need to be set to 0
        //we have used set since it will save from setting same row or column again
        unordered_set<int> row_st;
        unordered_set<int> col_st;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row_st.insert(i);
                    col_st.insert(j);
                }
            }
        }

        //now setting those row col to be zeros
        for(auto row: row_st){
            for(int j =0; j<n; j++)matrix[row][j] = 0;
        }
        for(auto col: col_st){
            for(int i=0; i<m; i++)matrix[i][col] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set_row_col_zeros(matrix);
    }
};
