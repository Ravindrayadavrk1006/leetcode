Intuition
simple recrusive of once taking a arr element once skipping and forming maximum size .

SOLUTION CAN BE IMPROVED SINCE CHARACTERS MEANS JUST ENGLISH 26 CHARACTERS HENCE TAKE AN ARRAY OF SIZE 26 AND APPROACH

Approach
Compare function => used for comparing if current arr element has repertative char among itself and also compare if current arr element characters already present in the original set(a set used for storing the unique char till now)

we take recursive approach of once taking element and in other recrusive call skipping and traversing all the possible ways and then comparing which gives maximum length

Complexity
Time complexity:
O(2^n*nums.size())

Space complexity:
O(nums.size())

Code
class Solution {
public:
    bool unique(unordered_set<char>&original_set,string s)
    {
        unordered_set<char> temp;
        for(int i=0; i<s.size(); i++)
        {
            if(temp.find(s[i]) == temp.end())temp.insert(s[i]);
            else return false;
        }
        for(int j=0; j<s.size(); j++)
        {
            if(original_set.find(s[j]) == original_set.end())continue;
            else return false;
        }
        return true;
    }
    int help(int pos, vector<string>& arr, unordered_set<char>& original_set,int len)
    {
        if(pos==arr.size())return len ;
        
        string s = arr[pos];
        bool check=unique(original_set, s);
        if(!check)return help(pos+1,arr,original_set,len);
        else
        {
            //pick
            for(int i=0; i<s.size(); i++)
            {
                original_set.insert(s[i]);
            }
            int first = help(pos+1,arr,original_set,len+s.size());

            //skip
            for(int i=0; i<s.size(); i++)
            {
                original_set.erase(s[i]);
            }
            int second = help(pos+1,arr,original_set,len);
            return max(first,second);

        }
    }
    int maxLength(vector<string>& arr) {
        unordered_set<char> original_set;
        return help(0,arr,original_set,0);
        
    }
};
