class Solution {
private:
    /*
        T.C -> O(n^2)
        explanation ->
            straight according to the question we are starting from the left and as soon as we encounter a number if it's previous element is a alphabet we remove the alpabet,
            we do so for every numberical char of the given string

        
        in internal for loop ->
            in each iternation we are trying to remove on dight and it's associated alphabet

        

    
    */
//basic brute force
    string brute_force(string s){

        //since in the internal for loop each time one possible pair can be removed, so this loop tries all the possible pair that can be removed
        while(true){
            int i = 0;
            if(s.size() == 0)return "";
            int n = s.size();
            bool removed = false;

            //trying to remove A SINGLE digit and associated removeable alphabet
            while(i<n){
                //if current char is a dight
                if(s[i]-'0'>=0 && s[i]-'0'<=9){
                    //if the index is 0 then we there can't be any alpahbet before it so can't remove anything try next
                    if(i == 0){
                        i++;
                        continue;
                    }
                    //if previous char is a alphabet and current char is already a digit, remove the alphabet 
                    else if(!(s[i-1]-'0'>=0 && s[i-1]-'0'<=9)){
                        s = s.substr(0,i-1) + s.substr(i+1);
                        removed = true;
                        break;
                    }
                }
                i++;
            }
            //if no alpabet was removed in the internal iternation then we break and current string is the answer
            if(!removed)return s;
        }
        return s;
    }




    /*
        T.C -> O(n)
        approach->
            we are traversing the string s and if the current char is a alphabet character then we are storing it's index in max-heap so that the topmost alpabhet index is at top.
            when the current char is a digit then we see if the top element in the max-heap has index less than the current i if yes then pop the top elment,
            else we store this digit char index in another vector called num_vec;

            //we now can pop all the remaining elmeent from max-heap and store it in a vector called alphabet_vec or alpahebet vector. since it's a max-heap therefore we are storing from last in the alphabet_vec



            //now we will have two SORTED array num_vec and alphabet_vec both containg the index of element that need to be the in the final string,

            use merge_algorithm to merge both the sorted arrays positions
            #now we will form a string from the indexes stored in this sorted vector

    
    
    */
    //merge alorithm
    vector<int> merge_algorithm(vector<int>& first, vector<int>& second){
        int i =0, j = 0;
        int n1 = first.size();
        int n2 = second.size();
        vector<int> merged;
        while(i<n1 && j<n2){
            if(first[i]< second[j]){
                merged.push_back(first[i++]);
            }
            else{
                merged.push_back(second[j++]);
            }
        }
        while(i<n1){
            merged.push_back(first[i++]);
        }
        while(j<n2){
            merged.push_back(second[j++]);
        }
        return merged;
    }
    string optimal(string s){
        int n = s.size();
        //max-heap for storing alphabatical chars
        priority_queue<int> pq;
        vector<int> num_vec;
        for(int i =0; i<n; i++){
            if(s[i]- '0'>=0 && s[i]-'0'<= 9){
                if(!pq.empty() && pq.top()< i){
                    pq.pop();
                }
                else{
                    num_vec.push_back(i);
                }
            }
            //push the char in the max-heap
            else{
                pq.push(i);
            }
        }
        int n_char = pq.size();
        vector<int> alphabet_vec(n_char);
        int i = n_char-1;
        while(!pq.empty()){
            alphabet_vec[i] = pq.top();
            pq.pop();
            i--;
        } 
        vector<int> positions = merge_algorithm(num_vec, alphabet_vec);
        string ans = "";
        for(const auto el: positions)ans+=s[el];
        return ans;
    }
public:
    string clearDigits(string s) {
        // return brute_force(s);

        return optimal(s);
    }
};
