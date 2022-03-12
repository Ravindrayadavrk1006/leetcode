class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        else if(x==0)
        {
            return true;
        }
        else
        {
            int dupX=x;
            long reverse=0;
            //vector<int> digitVector;
            //***using the reverse number approach****//
            while(x>0)
            {
                reverse=reverse*10+x%10;
                //digitVector.push_back(x%10);
                x/=10;
            }
            if(reverse==dupX)return true;
            return false;
            //now we have the vector with all the digits
            //instead of using vector we can store in a digit
            // int digitVectorSize=digitVector.size();
            // int digitVectorSizeReq=digitVectorSize-1;
            // int half=digitVectorSize/2;
            // for(int i=0;i<half;i++)
            // {
            //     if(digitVector[i]!=digitVector[digitVectorSizeReq-i])return false;
            //     else continue;          
            // }
            // return true;
        }
    }
};