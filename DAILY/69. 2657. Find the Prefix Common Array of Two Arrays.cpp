class Solution {
private:
    /*
        explanation ->
            we are inserting element of A vector one by one  in set format to reduce the search time complexity, using a for loop 
            and in other inner for loop,  we are checking all the elemnts till position i , if they are present in the above set if present then we are adding it in a count and finally on ending of this inner for loop we insert this value in ans vector
    */
    vector<int> solFindThePrefixCommonArray(vector<int>& A, vector<int>& B){
        int n = A.size();
        vector<int> ans(n,0);
        //set for inserting the values of vector A in set
        unordered_set<int> stA;
        //traversing all the values of set A and inserting them as we go along
        for(int i =0; i<n; i++){
            //insert ith value in the setA
            stA.insert(A[i]);
            int count = 0;
            //traverse all the elemtns of vector B from index j=0 to j=i and check if they are present in the set or not, if present then we increment the counter
            for(int j=0; j<=i; j++){
                if(stA.find(B[j]) != stA.end())count++;
            }
            //store the count value in ans vector
            ans[i] = count;
        }
        return ans;
    }
    //sol 2
    /*
        since we are given that vector A and B are permutation of integer 1 to n we can keep a frequency counter array to count which element has occured 2 times till now and when the count of element becomes 2 we say this element has occured two times

        approach ->
            eg. A = [1,3,2,4], B = [3,1,2,4]
            freq_counter [0,0,0,0]
            now at index i =0
            vector<int> and(n , 0)
            we increment freq_couter[A[0]] value 
            we increement freq_counter[B[0]] value
            if freq_counter[B[0]] == 2 it means this number has occured twice till now then we store in ans[0] = 1 i.e there is one number which has occured two times 
            now we run a for loop checking at index if after incrmenting freq_counter[A[i]] if freq_counter[A[i]] == 2 if yes it means this number had already appeard once before,
            similarly we don freq_counter[B[i]] and check if freq_counter[B[i]] == 2 if yess it means this number also has occured before,
             previous numbers has already been checked before and hence we make ans[i] = and[i-1] + increment where increment is equal to 1 if only freq_counter[A[i]] == 2  , increment is 0 if non becomes 2 and increment is 2 if both freq_counter becomes 2,

             also we are concerned with freq_counter==2 only because the arrays are permutation of number between 1 to n and therefore in each array A, B one number will be appear once in each array

        
    */
    vector<int> sol2(vector<int>& A, vector<int>& B){
        int n = A.size();
        vector<int> ans(n, 0);
        //frequency counter array
        vector<int> freq_counter(n+1, 0);

        //increment A[0]'s count
        freq_counter[A[0]]++;
        //increment B[0]'s count
        freq_counter[B[0]]++;
        //we are checking if counter of B[0] becomes 2 it means both A[0] and B[0] are same number then we save ans[0] = 1 i.e there is one number which has occured twice
        if(freq_counter[B[0]] == 2) ans[0] = 1;
        //now in for loop we are checking for A[i] , B[i] if there count becomes 2
        for(int i=1; i<n; i++){
            int increment = 0;
            //increment A[i] count
            freq_counter[A[i]]++;
            //if A[i] count has become two it means, this number has already appeard before
            if(freq_counter[A[i]] == 2){
                increment++;
            }
            //increment B[i] count
            freq_counter[B[i]]++;
            //if frequency counter B[i] becoms 2 it means this number has appeard before and 
            if(freq_counter[B[i]] == 2){
                increment++;
            }

            //current repative occurance number will be all the previous twice appeard numbers and current index element they become twice as checked in above cases
            ans[i]= ans[i-1] + increment;;
        }
        return ans;
    }
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // return solFindThePrefixCommonArray(A, B);

        return sol2(A, B);
    }
};
