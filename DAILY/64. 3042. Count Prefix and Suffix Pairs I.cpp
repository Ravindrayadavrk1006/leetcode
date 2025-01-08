class Solution {
private:
    bool isPrefixAndSuffix(string s1, string s2){
        int n = s1.size();
        int n2= s2.size();
        if(s1.size()> s2.size())return false;
        //checking if prefix and suffix
        //matching all the n characters of s1 if in s2 from start and end
        for(int i=0; i<n;i++){
            //if from start ith chracter of s1 not equal to ith character of s2 OR from end ith character of s1 not equal to ith character of s2 then we return false
            if(s1[i] != s2[i] || s1[n-i-1] != s2[n2-i-1])return false;
        }

        //if passed correctly the above loop then it's correct
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        //pass every possible of pair of isPrefixAndSuffix(s1, s2)
        for(int i =0; i<n-1; i++){
            for(int j=i+1; j<n;j++){
                if(isPrefixAndSuffix(words[i], words[j]))ans++;
            }
        }
        return ans;
    }
};
