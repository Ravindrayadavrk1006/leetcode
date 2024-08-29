/*
Intuition
[VERY IMPORTANT]
for such question or any complex problem in DP try proceeding by taking small cases
eg here
given [[1,1,0]] => output 1
given [[1],[1],[0],[0]] -> output 1
i.e if just one row or just one column then output the value 1 if 1 present else 0;
for general cases
eg. 1 output -> 1
eg. 0 output -> 0
eg. 1 1
0 1
if we consider stading at 1 in row 1 in 0 based index row we can form max square of size 1

eg. 1 1 1
0 1 0
1 1 0
in row 1 in 0 based index row stading at [1][1] from above we got we can form just one cell square.
at [1][2] we can't consider it so let it be so in matrix
in row 2 in 0 based index row standing at [2][1] we can form form just one cell square for [2][2] is 0 so won't contribute.

eg. 1 1 1
1 1 1
0 1 1
at [0][0] can form 1 sqaure of one cell similary for all elements of row [0]
stading at row [1] => at [1][0] looking in already checked direction we can form square of just one cell.
at [1][1] we can see since current position is 1 then it will contribute in a square also looking in filled direction i.e (i-1,j), (i,j-1) and (i-1,j-1) we will find only square possible from above
this implies that one square possible from above and 1 itself contributing => min((i-1,j), (i,j-1) and (i-1,j-1)) + 1(of self contirution). we keep looking and trying like this in further ones.

Complexity
Time complexity:
O(m*n)

Space complexity:
O(m*N)

Code

*/
class Solution {
public:
    int help(vector<vector<char>>& matrix)
{

      //checking if there is just one row in the given matrix if so , then at max only 1 size squre is possible which is only possible if there is 1 in the row
       if(matrix.size() == 1)
        {
            cout<<" i am here "<<matrix.size()<<endl;
            // int max_val = 0;
            for(int i=0; i< matrix[0].size(); i++)
            {
                if( matrix[0][i]-'0' == 1)return 1;
            }
            return 0;
            // return max_val;
        }
        //if matrix has just one column 
        if(matrix[0].size() == 1)
        {  
            for(int i = 0 ; i< matrix.size(); i++)
            {
               if(matrix[i][0]-'0' == 1)return 1;
            }
            return 0;
        }
        //for matrix of size greater than one
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int max_val= 0;

        /*
          our temp matrix is a dp tabulation which calculate the square size
          here in below 2 for looops we are intializing temp array first row and first column with their values because they will contribute that much only
        */
        for(int j=0;j < matrix[0].size(); j++)
        {
            temp[0][j]=matrix[0][j]-'0';
            if(temp[0][j] == 1) max_val = 1;
        }

        for(int i=0;i < matrix.size(); i++)
        {
            temp[i][0]=matrix[i][0]-'0';
            if(temp[i][0] == 1)max_val =1 ;
        }

        /*
          normal processing , if the current matrix[i][j] value is 0 we make temp[i][j] value as 0 , if current martix[i][j] value is 1 then we check for (i,j-1) , (i-1,j) , (i-1,j-1) positions and we take the min value ,
          the reason for taking mimimum value is that suppose any of three is 0 it means they can't contribute in a bigger square because we need all four to to contibute in square.
          
        */
        for(int i = 1 ; i < matrix.size(); i++)
        {
            for(int j= 1; j< matrix[0].size(); j++)
            {
                if(matrix[i][j] != '0')
                {
                    temp[i][j]= min(min(temp[i][j-1],temp[i-1][j]),temp[i-1][j-1]) + 1;
                    max_val = max(max_val, temp[i][j]);
                }
                else temp[i][j]=0;
            }
        }
        return max_val* max_val;
 }
    int maximalSquare(vector<vector<char>>& matrix) {
        return help(matrix);
    }
};
