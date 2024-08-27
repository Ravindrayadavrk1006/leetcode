INTUITION====>
If n is even -->
starting from Alice she can keep diving by 1 and and everythime Bob will get a odd number to make his turn since odd cannot be divided by even and odd%odd and when we do odd-odd we get even hence whatever number Bob choose to divide Alice will get even.
Finally in last alice will get 2 and hence can divide by 1 and again Bob will get 1 with no further move to make and he will loose.

If n is odd opposite of above will happen and Alice will always loose.

COMPLEXITY====>
Time complexity:
O(1)
Space complexity:
O(1)
Code
class Solution {
public:
    bool divisorGame(int n) {
        if(n%2 == 0)return true;
        return false;
    }
};
