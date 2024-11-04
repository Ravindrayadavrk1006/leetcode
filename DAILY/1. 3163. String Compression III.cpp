 /*
    THIS BELOW LOGIC IS USED IN BOTH THE SOLUTIONS, IN FIRST DUE TO STACK SPACE AND ALL FEW TEST CASES IN LAST ARE FAILING BUT ALL ARE WORKING IN SOLTION 2

        solution->
            i have taken a empty comp or compressed string initally , we are counting the number of character and once different character is encounted saving the current count of character and intialized the other character with count = 1 and moving forward.

            if same character is encountered we just increase it counter and if count ==9 then according to  question we add 9char in the comp and set the count = 1 , 
            if diffrent character is encountered we save the previous run of character and intialized the current character into c char variable and it's count = 1
    
    */


class Solution {
private:
    //SOLUTION 1
    //WRONG SOLUTION -> BECAUSE GIVING ERROR BECAUSE TAKING MORE TIME
    string strCompressed(int pos, string& word, string& comp, int count, char curr, int n){
        if(pos == n){
            // ostringstream temp;
            // temp<<count<<curr;
            string temp = to_string(count)+ curr;
            // comp+=temp.str();
            comp+=temp;
            return  comp;
        }
        if(word[pos] == curr){
            if(count == 9){
                // ostringstream temp;
                // temp<<count<<curr;
                string temp = to_string(count)+ curr;
                // comp+=temp.str();
                comp+=temp;
                count = 1;
            }
            else{
                count++;
            }
            //there is condition if count is more than 9 then we need to rest
            return strCompressed(pos+1, word,comp,count,curr,n);
        }
        else{
            // ostringstream temp;
            // temp<<count<<curr;
            string temp = to_string(count)+ curr;
            // comp+=temp.str();
            comp+=temp;
            count = 1;
            curr = word[pos];
            return strCompressed(pos+1, word, comp, count, curr,n);
        }
    }

    //the above code turned in non-recursive to remove the tle issue
    /*
        solution->
            i have taken a empty comp or compressed string initally , we are counting the number of character and once different character is encounted saving the current count of character and intialized the other character with count = 1 and moving forward.

            if same character is encountered we just increase it counter and if count ==9 then according to  question we add 9char in the comp and set the count = 1 , 
            if diffrent character is encountered we save the previous run of character and intialized the current character into c char variable and it's count = 1
    
    */

    //SOLUTION 2
    string non_recursive(string word){
        string comp = "";
        int n = word.size();
        int count = 1;
        char c = word[0];
        for(int i = 1; i< n; i++){
            if(word[i] == c){
                if(count == 9){
                    string temp = to_string(9) + c;
                    comp+=temp;
                    count = 1;
                }
                else{
                    count++;
                }
            }
            else{
                string temp = to_string(count)+ c;
                comp+=temp;
                count = 1;
                c = word[i];
            }
        }
        //adding the last part
        string temp = to_string(count) + c;
        return comp+temp;
    }
public:
    string compressedString(string word) {

        //CALLING SOLUTION FIRST, IT IS GIVING TLE
        /*
        string comp= "";
        int n = word.size();
        return strCompressed(1, word, comp, 1, word[0],n);   
        */
        return non_recursive(word);
    }
};
