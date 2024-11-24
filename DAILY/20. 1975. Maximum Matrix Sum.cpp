/*
    explanation -> pattern question on matrix
        try to take a 2*2 matrix or smaller 3*3 , i tried proceeding with 2*2 , here also once you have perfected the solution the solution in 2*2 try in odd size matrix too so that our solution does not fail
        1. take a 2*2 matrix
        here deductions -> if no of cells less than -1 are even then after doing the asked operations all the cells will become positive, if the no of cells less than -1 are odd then all the negative cells will become positive except one cell
        so using this logic we tried in bigger matrix also but if you observe doesn't matter because that logic will flow, 
        now in case of even number of negtives we add all the cells of the matrix converting negatives to positive  and return it because all the cells can be made positive , irrespective of negatives being present anywhere in any size matrix, try to observe or visualize,

        in case of odd numbers of negative finally one cell will remain negative , therefore we need to do those operations so that the least element in matrix remains negative , hence we find the negative , sum all the elemtns of the matrix converting negative to positive , then finally we substract 2*(smallest number of the matrix if all the cells were positive) because once we need to substract and we should not have added this element therefore 2*(least elemtn of the matrix if all the cells were positive)

*/

class Solution {
private:
    long long solMaxMatrixSum(vector<vector<int>>& matrix){
        long long sum  = 0;
        int countNegatives = 0;
        int n = matrix.size();
        //for calculating the least element of the matrix
        int minVal = INT_MAX;
        for(int i = 0; i<n ; i++){
            for(int j=0; j<n; j++){
                //counting the number of negatives
                if(matrix[i][j] <0){
                    countNegatives++;
                }
                //calculating the least value of the matrix , assuming all the elements are positive
                minVal = min(minVal, abs(matrix[i][j]));
                //calculating the sum of the matrix , converting all to be positive
                sum+=abs(matrix[i][j]);
            }
        }

        //if odd numbers of negative cells , substract the 2*least of the matrix as explained earleir
        if(countNegatives%2 != 0){
            return sum - 2*(abs(minVal));
        }
        //if even return the sum as it is because all can be converted into positive
        return sum;
    }
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        return solMaxMatrixSum(matrix);
    }
};
