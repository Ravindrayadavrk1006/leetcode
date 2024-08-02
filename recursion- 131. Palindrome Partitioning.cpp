class Solution {
private:
    bool validPalindrome(string& s, int start , int end){
        while(start < end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    void partitionHelper(int i,string& s,vector<string>& curr_vec,vector<vector<string>>& ans,int n){
        //base cases
        if(i == n)ans.push_back(curr_vec);
        //normal cases
        for(int ind= i; ind <n ; ind++){
            
            if(validPalindrome(s,i,ind)){
                //substr works like from index i print n characters
                cout<<i<<" "<< ind<< " "<<s.substr(i,ind-i+1)<<endl;
                curr_vec.push_back(s.substr(i,ind-i+1));
                partitionHelper(ind+1, s, curr_vec, ans, n);
                curr_vec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr_vec;
        partitionHelper(0, s, curr_vec, ans, s.size());
        return ans;

    }
};
