class Solution {
private:
    /*
        approach -> 
            for each row we are doing the shift for shifting we start from end of each row,
            once correct shifting is done then we do the 90* clockwise rotation,

            1. shifting->
                we start from the end of the row by running a for loop from end towards start of the row.
                    we count the space if current cell is space we add to the cell , if it's a obstacle we set the space cout to 0, if the current cell is stone and the space count is not zero then we can shift the stone , we shift the stone to the last space of our count, and make the current cell space.


            2. rotating by 90* clockwise->
                we create a new ans matrix of size(col,row)
                we go through each cell of the shifted box, 
                in our ans cell  the original cell becomes -->>     column becomes row,  the column in ans matrix is row-current_column-1

                ***REMEMBER 90* ROTATION IS DIFFERENT FROM TRANSPOSE

    */
    vector<vector<char>> sol1(vector<vector<char>>& box){
        int rows = box.size();
        int cols = box[0].size();
        //shifting to the correct position
        for(int i=0; i< rows; i++){
            int space = 0;
            for(int j=cols-1; j>=0; j--){
                if(box[i][j] == '.'){
                    space++;
                }
                else if(box[i][j] == '*')space = 0;
                else{
                    if(space){
                        //space the stone in the first valid space from left
                        box[i][j+space] = '#';
                        //make the current index empty or remove the stone from current index
                        box[i][j] = '.';
                    }
                }
            }
        }


        //printing our output //the 90* clockwise rotation is still remaining to be done
        for(int i=0; i< rows; i++){
            for(int j = 0; j<cols;j++){
                cout<<box[i][j];
            }
            cout<<endl;
        }
        //doing 90* rotation clockwise
        vector<vector<char>> ans(cols,vector<char>(rows));
        for(int i = 0; i< rows; i++){
            for(int j=0; j<cols; j++){
                //rotating the box 90* is not same as transpose
                //here columns becomes rows and, the column in new table is total_rows -i -1;
                ans[j][rows-i-1] = box[i][j];
            }
        }
        return ans;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        return sol1(box);
    }
};
