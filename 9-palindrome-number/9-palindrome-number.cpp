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
            vector<int> digitVector;
            while(x!=0)
            {
                digitVector.push_back(x%10);
                x/=10;
            }
            //now we have the vector with all the digits
            int digitVectorSize=digitVector.size();
            int digitVectorSizeReq=digitVectorSize-1;
            int half=digitVectorSize/2;
            for(int i=0;i<half;i++)
            {
                if(digitVector[i]!=digitVector[digitVectorSizeReq-i])return false;
                else continue;          
            }
            return true;
        }
    }
};