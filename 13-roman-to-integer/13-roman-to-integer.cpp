class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> basicConstant={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
    int len=s.length();
    int indexLength=len-1;
    int i=0;
    int value=0;
    while(i<len)
    {
        if(i<indexLength )
        {
            auto itr=basicConstant.find(s[i]);
            int first=itr->second;
            auto itr2=basicConstant.find(s[i+1]);
            int second=itr2->second;
            if(first<second)
            {
                value+=(second-first);
                i+=2;
                continue;
            }
            else
            {
                value+=first;
                i++;
            }   
        }
        else
        {
            auto itr=basicConstant.find(s[i]);
            int first=itr->second;
            value+=first;
            i++;
        }
    }
    return value;  
        
        //approach two storing the minus values too
        /*
        //storing the constant since stored in form of hashmap easy to search in O(1)
         unordered_map<char,int> basicConstant={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        unordered_map<string,int> constantPart={
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900}
        };
        char stringArray[]="s";
        int i=0;
        int value=0;
        int len = sizeof(stringArray)/sizeof(stringArray[0]);
        while(i<len)
        {
            // string tempStr=stringArray[i];
            // tempStr+=(string)stringArray[i+1];
            char tempStrArr[]={stringArray[i],stringArray[i+1]};
            string tempStr=tempStrArr;
            auto itr= constantPart.find(tempStr);
            if(itr==stringArray.end())
            {
                auto itr=basicConstant.find(stringArray[i]);
                value+=itr->second;
                i++;
                continue;
            }
            else
            {
                 auto itr=constantPart.find(tempStr);
                value+=itr->second;
                i+=2;
                
            }
        }
        return value;
        */
    }
};