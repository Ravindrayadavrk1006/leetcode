class Solution {
private:
    //without sorting directly
    //so the inbuilt find is some sort of KMP pattern matching algorithm
    //read the kmp algorithm from abdul bari you tube
    vector<string> solStringMatching(vector<string>& words){
        int n = words.size();
        vector<string> ans;
        for(int i =0; i<n; i++){
            for(int j=0; j<n;j++){
                if(i!=j && words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        return solStringMatching(words);
    }
};
