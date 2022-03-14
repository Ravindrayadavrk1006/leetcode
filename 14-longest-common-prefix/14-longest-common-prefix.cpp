class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos=0;
        char pos_element=strs[0][pos];
        string prefix="";
        while(1)
        {
            // cout<<"inside the infinite loop"<<endl;
            int i=0;
            while(i<strs.size() && pos<strs[i].length())
            {
                if(strs[i][pos]!=pos_element)
                {
                    return prefix;
                }
                
                i++;
                
            }
            if(i==strs.size())
            {
                prefix.push_back(pos_element);
                pos++;
                pos_element=strs[0][pos];
            }
            else return prefix;
        }
        
    }
};