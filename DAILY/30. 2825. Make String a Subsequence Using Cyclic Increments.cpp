/*
    APPLICATION OF CONCEPT OF LARGEST COMMON SUBSEQUENCE(LCS)
        we are starting from the end of the both the given string, let's suppose we use pointers i, j  i.e i for str1 and j for str2 ,  we start from i = str1.size()-1 , j = str2.size()-1 
        
        if current char matches or if by incrementing the char of i i.e if str[i] = a ,we make it b and so on. if both the str[i] == str[j] we try to check in the remaining left part (i-1, j-1) , if it doesn't match then we check in (i-1 , j) i.e we try to find the current charcater of str2 in the remaining string of str2
    
    */
class Solution {
private:
    string first,second;
    bool ifSubsequence(int i, int j){
        if(j<0)return true;
        if(i<0)return false;
        if(first[i] == second[j]){
            if(ifSubsequence(i-1, j-1)){
                return true;
            }
        }
        else if(((first[i] - 'a' +1)%26) + 'a' == second[j]){
            if(ifSubsequence(i-1, j-1)){
                return true;
            }
        }
        else{
            return ifSubsequence(i-1, j);
        }
        return false;
    }

    //same above using sol2
    //the above explained concecpt is used here also just done using  while loop
    bool usingforloop(string first, string second){
        int i = first.size()-1;
        int j = second.size()-1;
        while(i>=0 && j>=0){
            if(first[i] == second[j] || (((first[i] - 'a' +1)%26) + 'a' == second[j]) ){
                i-=1;
                j-=1;
            }
            else{
                i-=1;
            }
        }

        if(j<0)return true;
        return false;
    }
public:
    bool canMakeSubsequence(string str1, string str2) {
        first = str1;
        second = str2;



        //SOL 1
        //BASED ON LCS LARGEST COMMON SUBSEQUENCE
        //using recursion 
        // return ifSubsequence(str1.size()-1, str2.size()-1);
        //NOTE LEARNING!!!!
        //in this solution all the i,j pairs will be unique that is no overlapping subproblem therefore we can't apply dp otherwise it will time


        //SOL 2
        //it is same as sol1 just using the while loop
        return usingforloop(str1, str2);
    }
};
