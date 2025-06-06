class Solution {
private:
    /*
        explanation ->
            
            eg  bca   suppose we are on b we will insert b in the stack and decrease b count, and now we will see if all the chracater lower than the stack top has been already read i.e occurance of all the character lower than b i.e a has count 0, if so it means all a has been proceseed so we will remove this b , and we will do similary for next stack.top element, we will do this till stack is not empty or if we found a chracater at the top of stock whose previous atleast one previous character is still not processed i.e read



            approach->
                we are traversing all the character of string s
            we count the number of occurances of each character and store it in a vector, 0-25, 0 represent a, z is represented by 25

            once we have the count of each character, this count we have done to count a lexicographically lower charachter if yet to be read aka to be processed . 

            we now try to remove all the chracater from the stack whose all lexicographic chracter has been read or processed i.e    if stack top = d then count of a,b,c should be 0.
            we remove contigous character meaning if we find a characater whose lexicographic smaller chracater is still to be processsed we break out of this removing loop and proceed on processing or read next char from s
    
    */
    string sol(string s){
        int n = s.size();
        stack<int> stk;
        int i =0;
        //count occurances of each char
        vector<int> counter(26,0);
        for(int i =0; i<n; i++){
            counter[s[i]-'a']++;
        }
        string ans = "";

        //process all the index of string s 
        while(i <n){
            //insert the current char
            stk.push(s[i]-'a');
            //decrement it's count 
            //decrease it count to show many how many character are remaining to be processed
            counter[s[i]-'a']--;
            //try to remove all the continous character whose lexicographicallly all lower char are already read
            while(!stk.empty()){
                //read the top char
                int top = stk.top();
                //check if any lowe lexical character is still to be processed for this top
                bool lower_exist = false;
                for(int j =0; j<top; j++){
                    if(counter[j]>0){
                        //if still be processed, set lower_exist to be true
                        lower_exist = true;
                        break;
                    }
                }
                //if lower exist it means we can't remove this or any below character
                if(lower_exist)break;
                //if lexical lower doesn't exist remove the character and insert in the answer
                else{
                    stk.pop();
                    ans.push_back(top+'a');
                }
            }
            i++;
        }
        return ans;
    }
public:
    string robotWithString(string s) {
        return sol(s);
    }
};
