class Solution {
private:
    //TLE

    /*
        intuition ->
            basic as per the question directly using the logic

            we are using a take vector when value is 1 it means we can take it if the value is 0 it means we can't take it in final answer

            We traverse all the elements of the string s
            if at index i, current char is * then , frmo i-1 to 0 we run a while loop and get the smallest first smallest character and it's position and then after this while loop we set this character in take array as 0 since it can't be take finally using a for loop taking all the char which have their value 1 in the take vector
    
    */
    string brute_force(string s){
        int n = s.size();
        //vector which will denote if we have to take this pos char in finall asnwer or not
        vector<int> take(n, 1);

        //run for each character of string s
        for(int i =0; i<n; i++){
            //if current char is *
            if(s[i] == '*'){
                //we don't have to take this *
               take[i] = 0; 
               //from i-1 to 0 we get the first smallest char whose take value is 1, we set it's take value as 0 denoting, that we deleted smallest char previous to current *
               int j = i-1;
               int smallest_el = 26;
               int pos = -1;
               while(j>=0){
                    //if current element is not taken
                    if(take[j] == 1){
                        //if current char is lexicographcially smaller than smallest_el
                        if(s[j]-'a' < smallest_el){
                            //store it in smallest_el 
                            smallest_el = s[j]-'a';
                            //save it's position as well
                            pos = j;
                        }
                    }
                    j--;
               }
               //if smallest_el value is not 26 it means there exist a char which is smaller and whose take value is not 0 yet
               if(smallest_el != 26){
                    take[pos] = 0;
               }
            }
        }
        string ans = "";

        //collect all the char whose take value is 1
        for(int i =0; i<n; i++){
            if(take[i])ans+=s[i];
        }
        return ans;
    }


    //SOL 2 
    //working
    //T.C O(nlogn)
    /*
        we are having a pos_storage vector which store the position of each char, this pos_storage vec is of size 26
        and when we found a char which is not * we add it's index in the pos_storage vector

        we do above while traversing all the index of given string s
        when we find char to *, then we  run a for loop for char 0-26 in the pos_storage index and the first position where there is size>0 then we remove the last inserted index in it,

        in this way we remove the last occuring smallest alpahabet prior to * ,

        finally we run a for loop for all the char of s again,

        we check if this index is present in the pos_storage current char vector. if yes then we add in the answer
    
    */
    //binary search, basic
    bool can_take(int pos, char ch , vector<vector<int>>& pos_storage){
        int left = 0;
        int right = pos_storage[ch- 'a'].size()-1;

        while(left <= right){
            //mid index
            int mid = (left+right)/2;
            //index mid is equal to pos return true
            if(pos == pos_storage[ch-'a'][mid])return true;
            if(pos> pos_storage[ch -'a'][mid])left = mid+1;
            else right = mid -1;
        }
        return false;
    }

    string slight_better_approach(string& s){
        int n = s.size();

        //for each character we will store the indexs at which they occur in s
        vector<vector<int>> pos_storage(26);
        //run a for loop for each index of string s
        for(int i =0; i<n; i++){
            //if current char is not * then we push this index in current char index storer
            if(s[i] != '*'){
                pos_storage[s[i]-'a'].push_back(i);
            }
            //if current char is a *
            else{
                //run a for loop for for a-z in the pos_storage and the first char which has a element it means we can remove it, and we will remove the smallest eleement, we are removing from last which states that it will remove the last occurance of that char 
                //check for a-z
                for(int ch=0; ch<26; ch++){
                    //if there is this char char present in pos_storage
                    if(pos_storage[ch].size()>0){
                        //remove the last occurance of it 
                        pos_storage[ch].pop_back();
                        break;
                    }
                }
            }
        }
        //ans
        string ans = "";
        //for each char of string s we are checking if that is present in the pos_storage
        for(int i=0; i<n; i++){
            //if current char is not *, since we can't take * 
            //we are doing binary search ans seeing if current index is present in pos_storage and therefor can be taken
            if(s[i] != '*' && can_take(i, s[i],pos_storage)){
                ans+=s[i];   
            }
        }
        return ans;
    }
public:
    string clearStars(string s) {
        // return brute_force(s);

        return slight_better_approach(s);
    }
};
