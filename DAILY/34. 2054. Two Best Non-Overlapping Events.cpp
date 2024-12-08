class Solution {
private:

    //giving wrong answer because of time 
    int bruteForce(vector<vector<int>>& events){
        int n = events.size();
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            ans = max(ans, events[i][2]);
            for(int j = i+1; j<n; j++){                
                // cout<<i<<" "<<j<<endl;
                if(i != j && !((events[j][0]>= events[i][0] && events[j][0] <= events[i][1]) || (events[j][1] >= events[i][0] && events[j][1] <= events[i][1])) ){
                    // cout<<i<<" "<<j<<" "<<events[i][2] + events[j][2]<<endl;
                    ans = max(ans, events[i][2] + events[j][2]);
                }
            }
        }
        return ans;
    }

//-------------------------using editorial----------------------

    //using recursion
    //take and non-take appraoch of trying all the combination and using dp for optimizing the solution
    //non working solution giving wrong answer i.e TLE
    int solRecursion(int indx, int elCount,vector<vector<int>>& events, vector<vector<int>>& dp){
        if(indx>= events.size() || elCount == 2)return 0;
        if(dp[indx][elCount] != -1)return dp[indx][elCount];
        //normal flow 
        //for take situation we will take the current element and move to take the element from next correct range, from the elemtnw whose events[i][0] is greater then event[indx][1]

        //hence finding the same 
        int currEnd = events[indx][1];
        int low = indx +1;
        int high = events.size() -1;
        while(low <= high){
            int mid =  (low +  (high - low))/2;
            //it means it's one of the correct value, we will try to minize it
            if(events[mid][0]> currEnd)high = mid-1;
            else low = mid+1;
        }
        //here what we are saying in the ternary operator that if the next index is possible then we will try to take otherwise we will take the current element only , it is taking the current element only
        int take = events[indx][2] + (low < events.size() ?  solRecursion(low,elCount+1,events, dp): 0);
        int notTake = solRecursion(indx+1, elCount, events, dp);
        return dp[indx][elCount] = max(take, notTake);
    }




//----------------------------------------------working 

    //line sweep algorithm, this is also the 3rd approach given in the editorial
    //link to understand line sweep algorithm -> https://youtu.be/YnIxejYW7cE?si=oyVtFr-_oVaBW_VS
    /*
        we are saving the starting by marking starting with +1 and storing the end of the interval with -1 ,
        then we are sorting the formed list and processing element by element , if the current element is a start element i.e it's el[1] is 1 denoting it is a start then we check what is the maximum value of previous finished elemnt , we add and try to update the answer if it is greater,
        if the current is a end or stop element i.e el[1] == -1 then we update the maxFinishedValue, that is the maximum of all the elements that are finished
    */
    int solLineSweepAlgorithm(vector<vector<int>>& events){
        vector<vector<int>> startStops;
        for( auto event: events){
            //1 denote it's a 
            startStops.push_back({event[0], 1, event[2]});
            //-1 denote it is the stop or end, there is 1 added to the end element ,  one is added because we want that the next interval should start at element not on that, see eg. if {1,3,2} and {3,5,4} here first is ending at 3 and the second is starting if we have not added 1 in the fist then first the first one will be processed and 2 of first will come into consideration that it is already over
            // startStops.push_back({event[1]+1,-1, event[2]});


            //instead of that above commented line and addition of one in the stop value we can do this , this what it is doing that the end will be processed after start if the values are like this {1,3,2} {3,5,4} in the original events i.e the {1,3,4} won't come into consideration because it will be processed after {1,3,2} will be proceseed first because in the startStops array they will be in this order after sorting  {3,1,4} {3,2,2}-> representing 3 is   
            startStops.push_back({event[1],2, event[2]});
        }
        //sort normal line sweep algoirthm
        sort(startStops.begin(), startStops.end());
        //maxFinishedValue determine the previous maxFinishedValue
        int ans = 0, maxFinishedValue = 0;
        for(auto el: startStops){
            if(el[1] != 2 ){
                ans = max(ans, el[2] + maxFinishedValue);
            }
            //it's the ending of an event so let's update the maxFinishedValue
            else{
                maxFinishedValue = max(maxFinishedValue, el[2]);
            }
        }
        return ans;
    }



    //from editorial

    //using minheap 
    int solMinHeap(vector<vector<int>>& events){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(events.begin(), events.end());
        int maxFinishedValue = 0, ans = 0;
        //we have sorted now we will process each element in the order
        for(auto el: events){
            //we are saying that to remove all the elements which are finsished till now from the heap and store the finsihed element max value in a element maxFinished element
            while(!pq.empty() && pq.top().first < el[0]){
                maxFinishedValue = max(maxFinishedValue, pq.top().second);
                //remove this element, since it's max is already taken into account in the just above statement
                pq.pop();
            }
            //the current element become the value of current element and previous finsished ranges maxValue 
            ans = max(ans, el[2]+ maxFinishedValue);
            //push this current element, it's end time and it's value
            pq.push({el[1], el[2]});
        }
        return ans;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //non working
        // return bruteForce(events);

        //solution 2 not working, this is from editorial
        // vector<vector<int>> dp(events.size(),vector<int>(2,-1) );
        // sort(events.begin(), events.end());
        // return solRecursion(0, 0,events ,dp);





        // return solLineSweepAlgorithm(events);



        //editorial solution using minheap
        return solMinHeap(events);
    }
};
