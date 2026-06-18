class Solution {
    /*
        APPROACH 1-> brute force we go in the entire matrix and search in the entire matrix matching intially making the return value to be false
        if matched make it true and return else
        finally return false

        T.C --> O(n*2)

        APPROACH 2 ->
        since given the entire matrix is sorted and have to find some element
        and also the time complexity is expected to be log n hence enough hint to use binary search
        we first use binary seach in last column to find the row no in which the element may lie 
        then we use binary_search in that row to find if it has that element

    */
private:

    bool  _binary_search(vector<int> & row,int left, int right,int target)
    {
        if(left>right)return false;
        int mid = (left+right)/2;
        if(target == row[mid])return true;
        if(target>row[mid])return _binary_search(row,mid+1,right,target);
        else return _binary_search(row,left,mid-1,target);
    } 
    bool approach_2(vector<vector<int>>& matrix, int target)
    {
        bool ans = false;
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        vector<int> last_col;
        for(int i= 0; i<row_count; i++)last_col.push_back(matrix[i][col_count-1]);
        //finding row in which the element may be present
        //using lower_bound function which returns itr of the element which is just larger than the target element
        int row_no = lower_bound(last_col.begin(),last_col.end(),target)-last_col.begin();
        if(row_no==row_count)return false;
        return _binary_search(matrix[row_no],0,col_count-1,target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     return approach_2(matrix, target);   
    }
};
