class Solution {
private:
    /*
        using example 1 of Problem Description
        we can get the largest rectange of size 10 ie 5*2 i.e one given 5 and other from 6 size histogram

        we can find the area of rectangle like :
        standing at 2 size histgram we see we can get max of size 2 rectangle since next hist is of size 1  , standing at 1 size histogram we figure we can go in left direction till 0 index and in right we can go till 3 size histgram and we will get rectangle of size 6*1 i.e right pos-left pos * current size of histogram
        similarly for 5 we can't go in left direction since privious hist is of size 1 and in right direction we can go since the size of histogram is 6 hence we get 2*5 size rectangle using the same concept 


    for each histogram we can go in left and in right find the hist whose size is smaller than the current hist and we can do (right-left) *current hist size to get the rectangle 
    same concept is being used in below solution

    just to improve the time complexity of finding left and right small for each hist fromn
    to constant we are using a concept which is explained below 
    
    
    */


    int sol(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n];
        int rightsmall[n];

        //populating the left small array


        //working:
        /*
            we take a stack and start traversing the given heights array 
            the idea used is for the current heights[i] we remove all the elements which are greater or equal than the current heights[i] from the stack and in the leftsmall array store the element current_stack_stop+1 and then push the current element in the stack

            take paper pen to visualize the working
        */
        for(int i = 0; i<n ; i++)
        {
            //removing all the elements from stack which are greater than the current element
            while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
            if(st.empty())leftsmall[i] = 0;
            else leftsmall[i]= st.top()+1;
            st.push(i);
        }

        //making sure the stack is empty for again use
        while(!st.empty())st.pop();
        //populating the right small array
        //same way we find the left small
        for(int i = n-1; i>=0 ; i--)
        {
            //removing all the elements from stack which are greater than the current element
            while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
            if(st.empty())rightsmall[i] = n-1;
            else rightsmall[i]= st.top()-1;
            st.push(i);
        }


        //finding the heights of each rectangle 
        //formula used (rightsmall[i]-leftsmall[i] +1)*height of ith histogram

        int max_size_rectangle = -1e9;
        for(int i = 0 ; i<n ; i++)
        {
            int curr_rec_size=  (rightsmall[i]-leftsmall[i]+1)*heights[i];
            max_size_rectangle = max(max_size_rectangle,curr_rec_size);
        }
        return max_size_rectangle;
    }

//more optimized solution 
    //please refer to striver video for detailed explanation video topic : largest rectahnge in historgram part-2 
    //only explain this to the interviewer if he is forcing for it
    //not very necessary
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
    int largestRectangleArea(vector<int>& heights) {
        //return sol(heights);

        //calling optimized solution
        return optimized(heights);
    }
};
