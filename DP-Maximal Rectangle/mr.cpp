class Solution {

    /*refere question Largest Rectangle in Histogram for better understanding and the function optimized comes from there  comes from ther*/
private:
//finding max area of rectange given heights of histogram
    int optimized(vector<int>& heights)
    {

        int n = heights.size();
        stack<int> st;
        int max_area = 0;
        for(int i = 0; i<=n ; i++)
        {
            //removing all the elements from stack which are greater than the current element
            while(!st.empty() && (i ==n || (heights[st.top()]>= heights[i])))
            {
                int prev_hist = heights[st.top()];
                st.pop();
                int width ;
                if(st.empty())width = i;
                else width = i - st.top()-1;
                int prev_rec_area = width*prev_hist;
                max_area= max(max_area,prev_rec_area);
            }
            st.push(i);
        }
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        /*
            here the idea is send the area of histogram to the optimized function and it rreturns
        the largest area of the rectangle

        histogram height --> for 0th row --> ["1","0","1","0","0"]
        for 1st row --> if the current column contain element 1 then 
        it will be added to the previous value of the above row i.e 0th row , if current [row][column] value is zero then value will become zero 
        1st row histogram --> [2,0,2,1,1]
        2nd row histogram --> [3,1,3,2,2]
        3rd row histogram --> [4,0,0,3,0]

        so we provide the histogram for each row to optimized function which returns the max 
        size of rectangle
        */

        //max size rectangle 
        int max_rect = 0;
        int row_size = matrix[0].size();
        int col_size = matrix.size();
        // int hist[row_size];
        vector<int> hist(row_size,0);
        for(int i = 0; i<col_size; i++)
        {
            //filling the histogram vector
            for(int j = 0 ; j<row_size; j++)
            {
                if(matrix[i][j]=='1')hist[j]+=1;
                else hist[j] = 0;
            }
            //for a row histogram is ready sending it to omptimized function to find the 
            max_rect= max(max_rect,optimized(hist));
        }

        return max_rect;

    }
};
