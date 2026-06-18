class Solution {
/*
    APPROACH 1->
        we try to calculate for each given for each array element much water
        will be stored.
        for exampel [0,1,0,2,1,0,1,3,2,1,2,1] the first example given
        at index 0 -> 0 unit stored
        at index 1-> 0 unit stored
        at index 2 -> 1 unit stored
        at index 3 -> 0 unit stored
        at index 4 -> 1 unit stored 
        at index 5 -> 2 unit stored
        and so on ...

        suppose we are at index 2 -> 1 unit stored
        formula for calucating the amount of water at any index
        we do min(leftmaxpiller to current index,rigthmaxpiller to current index) - the height of current index
        at index 2 -> min(1,3) - 0 => 1-0 = 1
        for calulating the leftmaxpiller and right maxpiller we have to run a loop of order N and we have to run it for each given index hence T.C -> O(n*2)
        for reducing the time complexity-->
        we prehand calculate the left maximum for each and rigth maximum for each element 
        for left mmax we start from left and when we found a value greater than current element we incremement the value
        similary for right max we start from end
        ---> 
        left max -> 0 1 1 2 2 2  2 3 3 3 3 3
        <--------
        right max-> 3 3 3 3 3 3 3 3 2 2 2 1     
        now for suppose index at 2 for min(leftmax,right max)==>  min(1,3)=1

*/
private:
    int approach_1(vector<int>& height)
    {
        int n = height.size();
        //calculating left max and rigth max arrays
        vector<int> left_max(n);
        left_max[0]=height[0];
        vector<int> right_max(n);
        right_max[n-1]=height[n-1];
        for(int i = 1; i<n ; i++)
        {
            left_max[i]=max(left_max[i-1],height[i]);
            right_max[n-i-1]=max(right_max[n-i],height[n-i-1]);
        }
        int ans = 0;
        for(int i=0; i<n;i++)
        {
            ans+=(min(left_max[i],right_max[i])-height[i]);
        }
        return ans;
    }
    //APPROACH 2
    /*
        here we use two pointers approach
        idea--> we keep two pointers left and right
        and we try to use the appraoch_1 logic but modified
        we check if traverse the logic for better understanding
        or try for striver video 2-pointer placement series

    */
    int approach_2(vector<int>& height)
    {
        int n = height.size();
        int left = 0 ;
        int right = n-1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>left_max)left_max = height[left];
                else ans+=left_max-height[left];
                left++;
            }
            else
            {
                if(height[right]>right_max)right_max = height[right];
                else ans+=right_max-height[right];
                right--;
            }
        }
        return ans;
    }
public:
    int trap(vector<int>& height) {
        // return approach_1(height);

        return approach_2(height);
    }
};
