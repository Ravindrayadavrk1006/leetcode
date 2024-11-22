class Solution {
private:
    int totalRows, totalColumns;
    void flipper(int col, vector<vector<int>>& matrix){
        for(int i= 0; i< totalRows; i++){
            //flip that element 0 becomes 1-0 = 1 , 1 becomes 1-1 = 0
            matrix[i][col] = 1 -  matrix[i][col];
        }
    }
    int getEqualRows(vector<vector<int>>& matrix){
        int count = 0;
        for(int i =0; i<totalRows; i++ ){
            int j = 0;
            bool add = true ;
            while(j< totalColumns-1){
                //if any moment any cell becomes not equal to previous then check for next row
                if(matrix[i][j] != matrix[i][j+1]){
                    add = false;
                    break;
                }
                j++;
            }
            if(add)count++;
        }
        return count;
    }

    //naive appraoch of take and non take trying all possible matrix trying to flip or not flip all columns
    //TLE
    int solMaxEqualRowAfterFlips(int col , vector<vector<int>>& matrix){
        if(col >= totalColumns ){
            return getEqualRows(matrix);
        }
        //normal flow
        flipper(col, matrix);
        int left = solMaxEqualRowAfterFlips(col+1, matrix);
        //flip back to original format
        flipper(col, matrix);
        int right = solMaxEqualRowAfterFlips(col+1, matrix);
        return max(left, right);
    }

    //better approach 
    //see solution video for better understanding
    /*
    explanation 
        here the pattern is atleast one row with all elements we can form in worst case 
        we will consider 1010 same as 0101 that is just the bits are different pattern is same ,we will be couting all such rows assuming 1010 same as 0101 or 10001 same as 01110 

        why we are assuming same
        let's suppose example given is 
        000
        110
        001 

        ==> in let's just consider 
        110
        001       now we invert just the last column we will have our answer as two

        now think we can count similar pattern together and then if we tried to make same by just flipping the corresponding bits without caring about the other rows because while flipping if they get messed up we don't care because we want the largest number

    */
    int sol2(vector<vector<int>>& matrix){
        unordered_map<string, int> mp;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i<rows ; i++ ){
            //creating keys
            //we will consider 001 or 110 i.e inverse of each other same
            bool invertCurrentBit = false;
            if(matrix[i][0] != 0) invertCurrentBit = true;
            string current_key = "";
            if(invertCurrentBit){
                for(int j = 0; j< columns; j++){
                    //inverting the bit and converting it to char and then adding to the string
                    current_key += ((1- matrix[i][j]) + '0');
                }
            }
            else{
                for(int j = 0; j< columns; j++){
                    current_key += (matrix[i][j] + '0');
                }
            }
            //if doesn't exit then it will create the key and intialize it to 0 and then add one to it
            mp[current_key]++;
            //we are updating our answer with the current key value if it's better than previous answer
            ans  = max(ans, mp[current_key]);
        }
        return ans;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        //CALLLING SOLUTION 1 NAIVE APPROACH
        // int m = matrix.size();
        // int n = matrix[0].size();
        // totalRows = m;
        // totalColumns = n;
        // return solMaxEqualRowAfterFlips(0, matrix);


        //CALLING SOL 2 
        return sol2(matrix);
    }
};
