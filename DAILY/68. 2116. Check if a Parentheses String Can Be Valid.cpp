class Solution {
private:

    //this will fail for test cases like  ()(()(    100010
    //wrong for some test cases
    /*
    bool solCanBeValid(string s, string locked){
        stack<pair<char,char>> st;
        int n = s.size();
        if(n%2 != 0)return false;
        cout<<n<<endl;
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({s[i], locked[i]});
            }
             // if both are locked
            //if stack top element == (   and current s[i] == ')' then pop the stack pop
            else if(st.top().first == '(' &&  s[i] == ')'){
                st.pop();
                //go and check for next character
            }
            //both are unlocked then pop the top element
            else if(st.top().second == '0' && locked[i] == '0'){
                st.pop();
            }
            //here if locked
            //of form   stack.top is uncloekd and  current element is locked with value )
            else if(st.top().second =='0' && s[i] == ')'){
                st.pop();
            }
            //if stack top is (  and current element is unclocked then we pop
            else if(st.top().first == '(' && locked[i] == '0'){
                st.pop();
            }
            else{
                st.push({s[i], locked[i]});
            }
        }
        if(st.empty())return true;
        return false;
    }

    */

    /*
        from the editorial
    
    */
    //correct approach 
    bool correctApproach(string s, string locked){
        int n = s.size();
        if(n %2 ==  1)return false;
        cout<<n<<endl;
        //storing the index in stack if it's unlocked, openBracket
        stack<int> openBracketStorage, unlockedStorage;
        for(int i = 0; i<n; i++){
            //if the current position is uncloked store in unlocked stack
            if(locked[i] == '0')unlockedStorage.push(i);
            //here all are locked
            else if(s[i] == '(')openBracketStorage.push(i);
            //it will be closed and locked
            else if (s[i] == ')'){
                if(!openBracketStorage.empty()){
                    //current element get used to form a pair remove it
                    openBracketStorage.pop();
                }
                else if(!unlockedStorage.empty()){
                    //if there is not a opening bracket to match the current closing bracket then only the code will come here
                    //we are saying match the current closing bracket with a uncloekd one
                    unlockedStorage.pop();
                }
                //if neither a locked opneing brancket nor a uncloked is present to match the current closing bracket then we return false
                else{
                    return false;
                }
            }
        }

        //now there might be some opening brancket left in the openBracketStorage
        while(!openBracketStorage.empty() && !unlockedStorage.empty() && openBracketStorage.top() < unlockedStorage.top()){
            unlockedStorage.pop();
            openBracketStorage.pop();
        }
        if(!openBracketStorage.empty())return false;
        return true;
    }

public:
    bool canBeValid(string s, string locked) {
        // return solCanBeValid(s, locked);
        return correctApproach(s, locked);
    }
};
