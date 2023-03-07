class Solution {
/*
APPROACH 1:
    simple traverse the entire matrix and find it
    O(N*2)
APPROACH 2:
    we will watch the last column elements if the element is greater than we try to do binary search in that row
    we do binary search in all the rows which have last column element element greater than the target element
    we do so since since each row is sorted but not the entire matrix 
    hence possibilites are there to be found in other row which have last element greater than the target since other element in that row can match the target  
    T.C O(n*logm)

APPROACH 3:
    we start from right corner top most element
    we check if it is equal to the target if no then 
    we check if the current element element is greater than target if yes then possiblilites are there that the element could be found in left of that element hence we try to go in that row further
    if the current element is smaller than the target then there are no possiblities of it to be found in the current row since all other element to left of current element will be smaller 
    hence we move to the next row just below element
    we move to just below element sorted in both row wise and column wise
*/
private:
    bool approach_3(vector<vector<int>>& matrix, int target)
    {
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        int i = 0;
        int j = col_count-1;
        while(i<row_count && j>=0)
        {
            if(matrix[i][j] == target)return true;
            else if(matrix[i][j]<target)i++;
            else j--;
        }
        return false;
    }
   
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return approach_3(matrix,target);
    }
};
