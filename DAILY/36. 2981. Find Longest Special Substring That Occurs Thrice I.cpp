class Solution {

/*

    since the given s.length <=50 in constraints so , we can easly form brute force algoritm

    here we are trying to form all the substring by running two nested for loops, the moment we found a character which is different than the last character of the current substring, it's not special we check for substring which start from next character of main for loop, else we keep on adding the current char to the current substring and everytime we add a character a new substring is formed so we increase it's count in the hashmap



    we are trying to count the occurance of every special substring, by trying to form every substring and keeping the count in hashmap for special substring only
*/
private:
    int solMaximumLength(string& s){
        int n = s.size();
        int currLen = 1;
        unordered_map<string, int> mp;
        for(int i = 0; i<n; i++){
            string curr_substr = "";
            curr_substr+=s[i];
            mp[curr_substr]++;
            cout<<curr_substr<<" "<<mp[curr_substr]<<endl;
            for(int j= i+1; j<n; j++){
                if(curr_substr.back()!= s[j])break;
                else{
                    curr_substr+=s[j];
                    mp[curr_substr]++;
                    cout<<curr_substr<<" "<<mp[curr_substr]<<endl;
                }
            }
        }
        int ans = -1;
        for(auto el: mp){
            int len = el.first.size();
            cout<<len<<endl;
            if(el.second>2)ans = max(ans, len );
        }
        return ans;
    }
public:
    int maximumLength(string s) {
        return solMaximumLength(s);
    }
};
