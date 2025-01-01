class Solution {
/*
    approach ->
        we have counted the nubmer of ones in the string first.
        in the for loop --->>>> 
        zeros is the count of zero in the left , ones is the count of ones in the right, intially we havae assumed that there is only right string
        then we start forming the left string , if we encounter a '0' then inrement the zeros count , if we encounter a 1 then we decrease the count of ones , since the count of one in right side will decrease


    T.C -> O(N) since one for loop

*/
private:
    int sol_maxScore(string& s){
        int zeros=0,ones=0;

        //counting the number of ones in the string
        for(char ch: s){
            if(ch == '1')ones++;
        }
        int n = s.size();
        int ans = INT_MIN;

        //i < n-1 since non-part can be empty
        //from left side we are checking for i=0 so it makes sure left part is not empty
        for(int i=0; i<n-1; i++){
            //if found a '0' increment the count of zeros
            if(s[i] == '0'){
                zeros++;
            }
            //if we found a '1' it means '1' in the left part is found therefore we decrease ones count since ones count the nubmer of ones in the right string
            else{
                ones--;
            }
            //calculating the ans
            ans = max(ans, zeros+ones);
        }
        return ans;
    }
public:
    int maxScore(string s) {
        return sol_maxScore(s);
    }
};
