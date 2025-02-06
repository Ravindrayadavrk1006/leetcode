class Solution {

    //swaping every pair of char in s1 and if any time becomes equal to s2 then it's correct else finally after trying all we return false
    bool sol1(string & s1, string& s2){
        bool swaped  = false;
       int n= s1.size();
       for(int i =0; i<n; i++){
        for(int j = i; j<n; j++){
            swap(s1[i], s1[j]);
            if(s1 == s2)return true;
            swap(s1[i], s1[j]);
        }
       }
       return false;
    }


    //this is wrong
    bool sol2(string& s1, string& s2){
        unordered_map<char,int> mp;
        int n = s1.size();
        for(int i =0; i<n; i++){
            mp[s1[i]] = i;
        }
        int changes = 0;
        for(int i=0; i<n; i++){
            if(mp.find(s2[i]) == mp.end())return false;
            if(mp[s2[i]] != i)changes++;
        }
        if(changes>2)return false;
        return true;
    }
public:
    bool areAlmostEqual(string s1, string s2) {
       return sol1(s1, s2);

        // return sol2(s1, s2);
    }
};
