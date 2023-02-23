class Solution {
private:

    /*
        approach of Maximal Square problem

        the idea is we copy the 0th row and 0th column 
        and then for remaining the current value will be min(result[i-1][j],result[i][j-1],result[i-1][j-1])+1 if the current element in the given matrix is 1 else the value will be zero
        we then sum all the elements in the result and return the value

        reason ---> we are looking towards left and up direction from current cell,since the first row and colmn can form squares of size 1 at max so we copy the first row and column 
        for remaining since standing at the current position if it is zero it won't form any square neither it can contiribute in any larger square hence we put 0 there
        if the current element in the given matrix is 1 then we look at result[i-1][j],result[i][j-1],,result[i-1][j-1] and if the elements in the square are suppose all ones it means they we can form a square of size 4 and since current can form a square of size 1 hence we place  min(result[i-1][j],result[i][j-1],result[i-1][j-1])+1 . min since suppose once is saying it can form a square of 0 other are saying we can contirubte 1 so the final value means all three are contiributing in the square hence we keep min of the above +1 
    also visualize by taking example by placing other values suppose 
    1 2
    1 [fill]      
    suppose we are are at [fill] position 1 value is saying that i can only contirbute no one to left top or diagonal top can contirubte in me 
    2 is saying i can contirubte and top diagonal and left can contirbute s
    1 at line 16 is saying only i can contibute 
    so oveall 1 onces are saying left se kuch nhi milega 1 at line 15 saying diagonal left or top se kuch nhi milega but two is saying i can get 1 from above as well
    but for forming a larger square all theee should bring as equal to 2 to contirbute 3 size(2 extra and one themself ) array at [fill position] which is not happpening hence we take the min values of (result[i-1][j],result[i][j-1],result[i-1][j-1]) and since fill himself is 1 so +1 because 2 k size ka ek square or 1 k size ka ek square             
    */
    int sol(vector<vector<int>>& matrix)
    {
        int x = matrix.size();
        int y = matrix[0].size();
         int no_of_square = 0;
        vector<vector<int>> result(x,vector<int>(y,0));
        for(int j= 0 ; j<y; j++)
        {
            no_of_square+=matrix[0][j];
            result[0][j]=matrix[0][j];
        }
        for(int j=1 ; j<x; j++)
        {
            no_of_square+=matrix[j][0];
            result[j][0]=matrix[j][0];
        }

        //for traversing the other squares 
        for(int i = 1; i<x; i++)
        {
            for(int j = 1; j<y; j++)
            {
                if(matrix[i][j]==0)result[i][j]=0;
                else
                {
                    int min_val = min(result[i-1][j],result[i][j-1]);
                    min_val = min(min_val,result[i-1][j-1]);
                    result[i][j] = min_val+1;
                    no_of_square+=result[i][j];
                }
            }
        }
       
        return no_of_square;
        // for(int i = 0; i<x; i++)
        // {
        //     for(int j = 0;j<y; j++)
        //     {
        //         no_of_square+=
        //     }
        // }

    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        return sol(matrix);
    }
};
