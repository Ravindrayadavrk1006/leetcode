explained well in C.P notebook 
problem link --->  https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=0


/*
    naive approach -->
    here we try to start with taking a dist of 1 and try to increase 
    until we reaches a point that k number of cows can't be accomodated 
    when taking a distance of dist
    we return the value of dist till when we were able to accomodate
*/
int naive_approach(vector<int> &stalls, int k)
{
    //k is req_cows
    //starting with min distance i.e dist of 1
    int dist = 1;
    //a check variable 
    bool checker = true;
    int n = stalls.size();
    /*
        this while is used a a counter to max value
    */
    while(checker)
    {
        int curr_cow = 1;
        int cow_pos = stalls[0];
        int temp_dist = dist+1;
        /*
        this loop check if poosible allocation for a distance of dist+1
        */
        for(int i = 1; i<n; i++)
        {
            //if the distance of previous cow place and current cow is greater than temp_dist i.e dist+1 we are checking for
            if(stalls[i]-cow_pos>=temp_dist)
            {
                curr_cow++;
                cow_pos = stalls[i];
            }
            //if k(req_cow i.e given cows) cows have been allocated 
            //this means work of this function is complete and we can have to update the dist with this temp dist and break
            if(curr_cow==k)
            {
                dist = temp_dist;
                break;
            }
        }
        //checking if we were not able to allocate k cows with the dist+1 dist hence we will say that the previous dist value was the max value where we can place cows
        if(curr_cow<k)checker = false;
    }
    return dist;
}

/*
    approach 2 ===> we can use recursion with dp with still it will give same t.c with extra space of O(n*k)

*/


/*

    approach 3-->
    we will use the concept of allocate minimum no of pages but here just
    reverse that is we have to maximize the minimum in erlier it was minimize the maximum
    T.C --> nLogn

*/

//helper function for checking if we can place cows at min distance of mid 
bool _minimum_mid_allocation_possible(vector<int>& stalls,int mid,int k)
{
    int n = stalls.size();
    int cow_pos = stalls[0];
    int curr_cows = 1;
    for(int i = 1 ; i<n ; i++)
    {
        if(stalls[i]-cow_pos>=mid)
        {
            curr_cows++;
            cow_pos = stalls[i];
        }

        //STATEMENT 1
        //at any moment we get that yes we can allocate k cows we return true
        //if this statement never get true that means we were not able to allocate k cows
        if(curr_cows==k)return true;
    }
    //our funtion comes here when STATEMENT 1 never becomes true
    //hence we were not able to allocate k cows hence we return false
    return false;
}

int BS(vector<int> &stalls, int k)
{
    int n = stalls.size();
    int left = 1;
    int right = stalls[n-1]-stalls[0];
    while(left<=right)
    {
        //bitwise shift to half since bit operation are pretty fast
        int mid = (left+right)>>1;
        if(_minimum_mid_allocation_possible(stalls,mid,k))
        {   
            //if that current minmum mid amount is possible we will try to maximize it for it
            left = mid+1;
        }
        //i.e when trying minimum allocation of mid amount we were not able to allocate let's try to allocate less amount than mid
        else{
            right = mid-1;
        }
    }
    /*we return right since 
    suppose  right= 3 left = 4
    we are saying that we can allocate 3 and less than that distance since we have to maximize the allocation
    we return right value
    left i.e 4 and it's higher we couln't allocate 
    */
    return right;   
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());

    //CALLING NAIVE APPROACH
    // return naive_approach(stalls,k);


    //CALLING BINARY SEARCH APPROACH
    return BS(stalls,k);

}
