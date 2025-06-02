class Solution {
private:
    //SOL 1
    //WORKING
    //T.C O(n^2)
    /*

        initally we have set candies for each element to be 1 since it is given that atleast one candy is to be given to all children.
        we are running a for loop from  i -> [1 to n-1]
        if ratings[i]> ratings[i-1] we are setting candies[i] = candies[i-1]+1  //i.e the current chidlren reqiure candies one greater than the previous to keep the the answer to be minimum

        //now let's say current element has rating less than previous element
        eg.  1 0 2 and i = 1  ratings[1] = 0
        intially all are having candies 1 
        now i = 1 would also have candies 1, so what shall we do is for all previous indexes whose ratings[j]<ratings[j-1]   for j = i to  to  point j where ratings[j]< ratings[j-1]) we keep on seeing if candies[j-1] <= candies[j] since rating of j-1 is greater than j then it's candies should also be greater, and therefore we are setting candies[j-1] = candies[j] +1 

        
    
    */
    int sol_candies(vector<int>& ratings){
        int n = ratings.size();
        //initially give one candie to everyone
        vector<int> candies(n,1);
        if(n == 1)return 1;

        for(int i=1; i<n; i++){

            //if current element rating is greater than previous element then set it's candies 1+ candies[i-1]
            if(ratings[i]>ratings[i-1]){
                candies[i]= candies[i-1]+1;
            }

            //NOTE -> by looking at example second we find these commented lines are not required at all
            // else if(ratings[i] == ratings[i-1]){
            //     candies[i] = candies[i-1];
            // }


            //current element will be less than the previous element
            else if(ratings[i]< ratings[i-1]){

                //till the point when ratings[i]<ratings[j-1] we need to increase the precious elements ratings if their candies are not suffient, hence doing the same

                //so that the i of initial for loop doesn't get affected
                int j = i;
                //till the point ratings of prvious elment is greater than the ratings of current element
                //j>=1 is the precenting for loop failing condition since j-1 also being checked
                while(j>=1 && ratings[j]< ratings[j-1]){
                    //if the candies of previous greater ratings elemnt is not sufficient then set it's candies to be candies[i]+1
                    if(candies[j-1]<= candies[j]){
                        candies[j-1] = candies[j]+1;
                    }
                    //decrement j value
                    j--;
                }
            }
        }
        int ans = 0;
        for(auto el: candies){
            cout<<el<<" ";
            ans+=el;
        }
        return ans;
    }    

    /*
        approach ->
            Since asked a child with more ratings should get more candies then it's both neighbour.

            Using this intuition ->
                we will try to solve in two pass one from left end of the array and one from the right end of the array.
            from left end of array:
                we run loop from -> [1 to n-1] index , if current index has rating greater than previous element we set the candies of current element to be  candies[i-1]+1

            //since we also need to check from right side as well because we have handled for left neigbhour but didn't handle for right neighbours
            let's do that
            run for loop [n-2 to 0]
            we check if current element index rating greater than  ratings[i+1] also check if whatever candies we have given to the current element is less than or equal to candies[i+1] then we set candies[i] = candies[i+1]+1


            finall we sum all the candies and return


    
    */
    int two_pass(vector<int>& ratings){
        int n = ratings.size();
        vector<int> candies(n,1 );
        for(int i =1; i<n; i++){
            if(ratings[i]> ratings[i-1])candies[i]= candies[i-1]+1;
        }
        for(int i =n-2; i>=0; i--){
            if(ratings[i]> ratings[i+1] && candies[i]<= candies[i+1])candies[i]= candies[i+1]+1;
        }
        int ans = 0;
        for(int el: candies)ans+=el;
        return ans;
    }
public:
    int candy(vector<int>& ratings) {
        // return sol_candies(ratings);

        return two_pass(ratings);
    }
};
