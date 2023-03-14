class Solution {
private:
int sqrt(int x)
    {
        //using binary search
        float left =1;
        float right = (float)x;
        float req = (float)x;
        float mid  = 0;
        while((right-left)>1e-6)
        {
            
            float temp  = (left+right)/2.0;
            if(temp == mid)return int(mid);
            else
            {
                mid = temp;
            }
            cout<<"left->"<<left<<" right->"<<right<<" mid->"<<mid<<endl;
            if(mid*mid >req )
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
     return right;
    }
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
