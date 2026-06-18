Intuition
from the current position going in all four direction and exploring other direction if current element is the same as the starting element.
Using recursion to explore all the ways

Complexity
Time complexity:
m*n i.e size image

Space complexity:
O(m*n)

Code
class Solution {
public:
    void help(int x, int y , vector<vector<int>>& image, int from_color, int to_color, int x_size, int y_size)
    {
        //base case
        // [*IMPORTANT] image[x][y] != from_color condition because it will allow from traversing unnecessary paths
        if(x < 0 || x == x_size || y < 0  || y == y_size || image[x][y] != from_color) return;
        
        image[x][y]=to_color;
        //go right
        help(x+1, y, image, from_color, to_color, x_size, y_size);
        //go left
        help(x-1, y, image, from_color, to_color, x_size, y_size);
        //go top
        help(x, y-1, image, from_color, to_color, x_size, y_size);
        //go bottom
        help(x, y+1, image, from_color, to_color, x_size, y_size);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int from_color=image[sr][sc];
        int to_color=color;
        int x_size=image.size();
        int y_size=image[0].size();
        
        //if to change color and previous color same
        if(from_color == to_color)return image;
        help(sr, sc, image, from_color, to_color, x_size, y_size);
        return image;
    }
};
