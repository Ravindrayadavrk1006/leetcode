class Solution {
public:
    /********READ THE OUTSIDE COMMENTS TO UNDERSTAND THE IDEAS**********************/
     //this function used for pair matching it return true if matched else return false
    bool pairMatch(char stackChar,char stringChar)
    {
        if(stackChar=='(' && stringChar==')')return true;
        else if(stackChar=='[' && stringChar==']')return true;
        else if(stackChar=='{' && stringChar=='}')return true;
        else return false;
    }
        //the idea is simple, we are using stack. We are having a <pos> pointing to the string character we are currently processing
    //pushing into stack if the the stack is empty <or> if top of stack not equal to the string pos char we are processing
    //if pair matched then we pop else we keep pushing
    //finally if the stack is empty then returning true else returning false
    bool isValid(string s)
    {
        int pos=0;
        stack<char> st;

        while(pos<s.length())
        {
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
        }
        // cout<<"before returning final top"<<st.top()<<endl;
        return st.empty();
    }
};
