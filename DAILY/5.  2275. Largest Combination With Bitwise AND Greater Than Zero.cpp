class Solution {
private:
    //SOL 1 --> WRONGGGGG
    //this approch of forming
    /*
        here we are trying to form every combination using the basic conept of take and not take normally trying to return the maximum of two, we have done some optimization where if any moment the number becomes 0 then & with any number will zero hence , at the moment and_val becomes zero we are returning INT_MIN as count.

        but it is giving TLE

    */
    int largestSet(int pos, int and_val , int count , vector<int>& candidates){
        if(pos == candidates.size()){
            if(and_val){
                return count;
            }
            return INT_MIN;
        }
        if(!and_val)return INT_MIN;
        int new_and_val = and_val & candidates[pos];
        int left = INT_MIN;
        if(new_and_val){
            left = largestSet(pos+1,new_and_val, count+1 , candidates );
        }
        int right = largestSet(pos+1,and_val, count, candidates);
        return max(left, right);
    }



    //CORRECTT solution
    //SOL 2

    /*
        concept used -> for two numbers & to be a non-zero , their same bit should be 1.
        for n numbers & to be non-zero , all of their same bit number(ith bit ) should be 1.

        using the same concept solved.
            we have take a hash map of size 32 , to store the count of numbers whose ith bit is 1.
            initally all are initialzed to 0 , representing that no number have ith bit 1.

            we traverse through all the elemnts of the array and each element all 32 bit, which ever bit is 1 we incease the count in map for that bit.

            finally we traverse the map for finding the count of number whose that bit is set.
    
    */
    int sol_largestCombination(vector<int>& candidates){
        int n = candidates.size();
        //a map of 32 each index representing a bit , initally all count set to 1
        //we are using this map to count the number of elements which have that bit number set
        unordered_map<int,int> mp(32);
        for(int i = 0; i<32; i++)mp[i] = 0;
        for(int i = 0; i < n; i++ ){
            for(int bit_no= 0; bit_no<32; bit_no++){
                //getting that bit
                int bit = (candidates[i]>>bit_no) & 1;
                //if the bit is set in hash map increase the count of that bit number
                if(bit){
                    mp[bit_no]+=1;
                }
            }
        }
        int max_combination_set = 0;
        for(int i = 0; i<32; i++){
            max_combination_set = max(max_combination_set, mp[i]);
        }
        return max_combination_set;
    }
public:
    int largestCombination(vector<int>& candidates) {

        int n = candidates.size();
        //in signed integer we can represent maximum value 2^31 -1 since the last bit will be used to represent if the number is  +ve or -ve

        //here we are taking int max because which is all ones i.e 2^31-1 since AND of any bit with 1 is same bit
        // return largestSet(0,INT_MAX , 0 , candidates);




        //SOL 2
        return sol_largestCombination(candidates);
    }
};
