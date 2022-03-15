class Solution {
public:
    bool pairMatch(char stackChar,char stringChar)
    {
        // cout<<"passed element in this function "<<endl<<"stackChar=>"<<stackChar<<"stringChar=>"<<stringChar<<endl;
        if(stackChar=='(' && stringChar==')')return true;
        else if(stackChar=='[' && stringChar==']')return true;
        else if(stackChar=='{' && stringChar=='}')return true;
        else return false;
    }
    bool isValid(string s)
    {
        int pos=0;
        stack<char> st;

        while(pos<s.length())
        {
            // cout<<"pos=> "<<s[pos]<<"stack.top=>"<<st.top()<<endl;
            if(st.empty() || !pairMatch(st.top(),s[pos]))
            {
                st.push(s[pos]);
                pos++;
            }
            else if(pairMatch(st.top(),s[pos]))
            {
                st.pop();
                pos++;
            }
            // cout<<st.top()<<endl;
        }
        // cout<<"before returning final top"<<st.top()<<endl;
        return st.empty();
    }
};